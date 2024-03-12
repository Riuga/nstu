// Лабораторная работа №6. Вариант 15

#include <stdio.h>
#include <string.h>

// Задание 1
/*
int main(int argc, char *argv[]) {
    FILE *finput, *foutput;
    char buffer[50], f_out_name[20], symbol;
    int i;

    if(argc < 3) {
        printf("Not enough parameters\n");
        return 0;
    }

    finput = fopen(argv[1], "rt");
    if(finput == NULL)
    {
        printf("File doesn't exist\n\r");
        return 0;
    }

    i = 0;
    while(*(argv[1]+i) != '.' && *(argv[1]+i) != '\0')
    {
        f_out_name[i] = *(argv[1]+i);
        i++;
    }
    f_out_name[i] = '\0';
    strcat(f_out_name, ".out");

    foutput = fopen(f_out_name, "wt");
    if(foutput == NULL) {
        printf("File doesn't exist\n\r");
        return 0;
    }

    symbol = *argv[2];
    while (fgets(buffer, 30, finput) != 0) {
        i = 0;
        while (buffer[i] != '\0') {
            if(buffer[i] == symbol) {
                fputs(buffer, foutput);
                i = strlen(buffer);
            }
            i++;
        }
    }

    fclose(finput);
    fclose(foutput);
    printf("Done");
    return 0;
}
*/
// Задание 2

int main(int argc, char *argv[]) {
    FILE *finput, *foutput;
    char buffer[50], f_out_name[20], currentChar;
    int i, j, exchangeCount;

    if(argc < 3) {
        printf("Not enough parameters\n");
        return 0;
    }

    finput = fopen(argv[1], "rt");
    if(finput == NULL)
    {
        printf("File doesn't exist\n\r");
        return 0;
    }

    i = 0;
    while(*(argv[1]+i) != '.' && *(argv[1]+i) != '\0')
    {
        f_out_name[i] = *(argv[1]+i);
        i++;
    }
    f_out_name[i] = '\0';
    strcat(f_out_name, ".out");

    foutput = fopen(f_out_name, "wt");
    if(foutput == NULL) {
        printf("File doesn't exist\n\r");
        return 0;
    }

    exchangeCount = *argv[2] - 48;
    i = 0;
    while ((currentChar=getc(finput)) != EOF) {
        if (currentChar != '\n' && currentChar != '\0') {
            buffer[i] = currentChar;
            i++;
        } else {
            char lastChar = buffer[i-1];
            for (j = 0; j < i-1; j++) {
                if (exchangeCount > 0 && buffer[j] == lastChar) {
                    buffer[j] = ' ';
                    exchangeCount -= 1;
                }
            }
            i = 0;
            exchangeCount = (int)*argv[2]-48;
            fputs(buffer, foutput);
            memset(buffer, 0, sizeof buffer);
            fputc('\n', foutput);
        }
    }
    char lastChar = buffer[i-1];
    for (j = 0; j < i-1; j++) {
        if (exchangeCount > 0 && buffer[j] == lastChar) {
            buffer[j] = ' ';
            exchangeCount -= 1;
        }
    }
    fputs(buffer, foutput);
    fclose(finput);
    fclose(foutput);
    printf("Done");
    return 0;
}
