// Лабораторная работа №4. Вариант 15

#include <stdio.h>
#include <string.h>

#define strCount 4
#define strSize 127

// Задание 1

int inputString(char string[], int size) {
    int i;
    int j = size;
    while (j >= size) {
        printf("\n Input your string here:");
        gets(string);
        j = strlen(string);
    }
    for (i = j; string[i] != ' '; i--);
    return j - i - 1;
}

void outputString(char string[], int lastWordLength, int strNumber) {
    printf("\n String number %d,%s, the length of last word = %d symbols.", strNumber, string, lastWordLength);
}

void stringReplace(char str1[], char str2[]) {
    char temp[strSize];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int sort(char array[][strSize], int len[], int strAmount, int* replaces) {
    int temp;
    int maxSpacesAmount = 0;
    for (int i = 0; i < strAmount; i++) {
        int min = len[i];
        int minIndex = i;

        for (int j = i; j < strAmount; j++) {
            if (len[j] < min) {
                min = len[j];
                minIndex = j;
            }
        }
        if (minIndex != i) {
            stringReplace(array[i], array[minIndex]);
            temp = len[i];
            len[i] = len[minIndex];
            len[minIndex] = temp;
            *replaces += 1;
        }
    }
    for(int i = 0; i < strAmount; i++) {
        int tempSpaces = 0;
        for(int j = 0; j < strlen(array[i]); j++) {
            if(array[i][j] == ' ') {
                tempSpaces += 1;
            } else {
                if (tempSpaces > maxSpacesAmount) {
                    maxSpacesAmount = tempSpaces;
                    tempSpaces = 0;
                }
            }
        }
    }
    return maxSpacesAmount;
}

int main() {
    char array[strCount][strSize];
    int len[strCount];
    int replaces, spaces;
    for(int i = 0; i < strCount; i++) len[i] = inputString(array[i], strSize);
    spaces = sort(array, len, strCount, &replaces);
    printf("\n Amount of replaces = %d", replaces);
    printf("\n Amount of spaces in a row = %d", spaces);
    for(int i = 0; i < strCount; i++) outputString(array[i], len[i], i);
    return 0;
}

// Задание 2

/*
int inputString(char *string, int size) {
    int i;
    int j = size;
    while (j >= size) {
        printf("\n Input your string here:");
        gets(string);
        j = strlen(string);
    }
    for (i = j; string[i] != ' '; i--);
    return j - i;
}

void outputString(char* string, int* lastWordLength, int* strNumber) {
    printf("\n String number %d,%s, the length of last word = %d symbols.", *strNumber, string, *lastWordLength);
}

void stringReplace(char *str1, char *str2) {
    char temp[strSize];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int sort(char array[][strSize], int *len, int strAmount, int *replaces) {
    int *temp = 0;
    int maxSpacesAmount = 0;
    for (int i = 0; i < strAmount; i++) {
        int min = len[i];
        int minIndex = i;

        for (int j = i; j < strAmount; j++) {
            if (*(len+j) < min) {
                min = *(len+j);
                minIndex = j;
            }
        }
        if (minIndex != i) {
            stringReplace(array[i], array[minIndex]);
            *temp = *(len+i);
            *(len+i) = *(len+minIndex);
            *(len+minIndex) = *temp;
            *replaces += 1;
        }
    }
    for(int i = 0; i < strAmount; i++) {
        int tempSpaces = 0;
        for(int j = 0; j < strlen(array[i]); j++) {
            if(array[i][j] == ' ') {
                tempSpaces += 1;
            } else {
                if (tempSpaces > maxSpacesAmount) {
                    maxSpacesAmount = tempSpaces;
                    tempSpaces = 0;
                }
            }
        }
    }
    return maxSpacesAmount;
}

int main() {
    char array[strCount][strSize];
    int len[strCount];
    int replaces, spaces;
    for(int i = 0; i < strCount; i++) len[i] = inputString(array[i], strSize);
    spaces = sort(array, len, strCount, &replaces);
    printf("\n Amount of replaces = %d", replaces);
    printf("\n Amount of spaces in a row = %d", spaces);
    for(int i = 0; i < strCount; i++) outputString(array[i], &len[i], &i);
    return 0;
}*/
