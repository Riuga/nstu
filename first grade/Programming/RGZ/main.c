/* Курсовая работа по информатике. Вариант 16.
 * Структура: Название пункта, расстояние, количество рейсов
 * Количество записей: 200
 * Номер поля для сортировки: 1
 * Выделение памяти: статическое
 * Тип сортировки: по убыванию
 * Вывод: экран
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NOTES 200
#define NAME_LENGTH 30
#define FILE_PATH "database.txt"

typedef struct {
    char name[NAME_LENGTH];
    int distance;
    int flightsCount;
} Flight;

void add_note();
void out_note();
void sort();
void print_db();
void write_db();
void read_db();

int btr_str(const char* s1, const char* s2, int l);

Flight flights[NOTES];
bool isSorted;

int main() {
    isSorted = false;
    int command = 0;
    do {
        printf("\n\t[Menu]\n");
        printf("<1> Input note\n");
        printf("<2> Output note\n");
        printf("<3> Sort notes by destination\n");
        printf("<4> Output sorted notes\n");
        printf("<5> Save notes in file\n");
        printf("<6> Read notes from file\n");
        printf("<0> Exit\n");

        printf("\nInput number of command here: ");
        scanf("%d", &command);

        if (command == 0)
            break;
        else if (command == 1)
            add_note();
        else if (command == 2)
            out_note();
        else if (command == 3)
            sort();
        else if (command == 4)
            print_db();
        else if (command == 5)
            write_db();
        else if (command == 6)
            read_db();
        else
            printf("Incorrect command, try again:\n");

        printf("################\n");
    } while (command != 0);

    return 0;
}

void add_note() {
    int num;

    printf("Number of note: ");
    scanf("%d", &num);
    num--;

    printf("> Input new note here:\n");

    printf("  Destination: ");
    scanf("%s", flights[num].name);

    printf("  Distance: ");
    scanf("%d", &flights[num].distance);

    printf("  Number of flights: ");
    scanf("%d", &flights[num].flightsCount);

    isSorted = false;
}

void out_note() {
    int num;

    printf("Number of note: ");
    scanf("%d", &num);
    num--;

    if (flights[num].distance > 0) {
        printf("> Note №%d\n", num+1);
        printf("\tDestination: %s\n", flights[num].name);
        printf("\tDistance: %d\n", flights[num].distance);
        printf("\tNumber of flights: %d\n", flights[num].flightsCount);
    } else {
        printf("There is not note %d\n", num+1);
    }
}

void sort() {
    if (!isSorted) {
        for (int loop = 0; loop < NOTES/2; loop++) {
            for (int number = 0; number < NOTES-1; number++) {
                if (flights[ number ].name == NULL ||
                    (flights[number+1].name != NULL &&
                     btr_str(flights[number].name, flights[number+1].name, 0) > 0))
                {
                    Flight temp = flights[number+1];
                    flights[number+1] = flights[number];
                    flights[number] = temp;
                }
            }
        }

        printf("Database was sorted\n");
        isSorted = true;
    }

}

void print_db() {
    if (!isSorted)
        sort();

    for (int num = 0; num < NOTES; num++) {
        if (flights[num].distance > 0) {
            printf("> Note № %d", num+1);
            printf("  Destination: %s\n", flights[num].name);
            printf("  Distance: %d\n", flights[num].distance);
            printf("  Number of flights: %d\n", flights[num].flightsCount);
        }
    }
}

void write_db() {
    FILE* database = fopen(FILE_PATH, "w");

    if (database != NULL) {
        int added_flights = 0;
        for (int note = 0; note < NOTES; note++) {
            if (flights[note].distance > 0)
                added_flights++;
        }
        fprintf(database, "#%d\n", added_flights);

        for (int num = 0; num < NOTES; num++) {
            if (flights[num].distance > 0) {
                fprintf(database, "%s %d %d\n",
                        flights[num].name, flights[num].distance, flights[num].flightsCount);
            }
        }
        printf("Notes was saved\n");
    } else {
        printf("Error\n");
    }

    fclose(database);
}

void read_db() {
    FILE* database = fopen(FILE_PATH, "r");

    if (database != NULL) {
        for (int note = 0; note < NOTES; note++) {
            flights[note].distance = -1;
        }

        int added_flights = 0;
        fscanf(database, "#%d\n", &added_flights);

        for (int num = 0; num < added_flights; num++) {
            fscanf(database, "%s %d %d\n",
                   flights[num].name, &flights[num].distance, &flights[num].flightsCount);
        }

        printf("Notes was loaded\n");
    } else {
        printf("Error\n");
    }

    fclose(database);
    isSorted = false;
}

int btr_str(const char* s1, const char* s2, int l) {
    int ltr = l;
    int max_ltr = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);

    if (s1[ltr] > s2[ltr])
        return -1;
    else if (s2[ltr] > s1[ltr])
        return 1;
    else {
        if (ltr < max_ltr)
            return btr_str(s1, s2, ltr+1);
        else
            return (strlen(s1) > strlen(s2) ? -1 : 1);
    }
}