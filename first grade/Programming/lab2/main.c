#include <stdio.h>

// Лабораторная работа №2. Вариант 15.

//Задание 1
/*
int main() {
    char str[50];
    int i = 0;

    printf("Type text string here: ");
    gets(str);
    printf("Old string: %s\n", str);
    label10: if(str[i]=='\0') goto label11;
            str[i]=(str[i]=='n')? '0':str[i];
            str[i]=(str[i]=='o')? '1':str[i];
            str[i]=(str[i]=='p')? '2':str[i];
            str[i]=(str[i]=='q')? '3':str[i];
            str[i]=(str[i]=='r')? '4':str[i];
            str[i]=(str[i]=='s')? '5':str[i];
            str[i]=(str[i]=='t')? '6':str[i];
            str[i]=(str[i]=='u')? '7':str[i];
            str[i]=(str[i]=='v')? '8':str[i];
            str[i]=(str[i]=='w')? '9':str[i];
            str[i]=(str[i]=='D')? 'k':str[i];
            str[i]=(str[i]=='L')? 'f':str[i];
            str[i]=(str[i]=='G')? 't':str[i];
            str[i]=(str[i]=='S')? 'r':str[i];
            i++;
            goto label10;

    label11: printf("New string: %s\n", str);
    return 0;
}
*/

// Задние 2

/*
int main() {

    char str[50];
    int i = 0;

    printf("Type text string here: ");
    gets(str);
    printf("Old string: %s\n", str);
    label10: if(str[i]=='\0') goto label11;
    if (str[i] == 'n') str[i] = 0;
    else if (str[i]=='o') str[i] = '1';
    else if (str[i]=='p') str[i] = '2';
    else if (str[i]=='q') str[i] = '3';
    else if (str[i]=='r') str[i] = '4';
    else if (str[i]=='s') str[i] = '5';
    else if (str[i]=='t') str[i] = '6';
    else if (str[i]=='u') str[i] = '7';
    else if (str[i]=='v') str[i] = '8';
    else if (str[i]=='w') str[i] = '9';
    else if (str[i]=='D') str[i] = 'k';
    else if (str[i]=='L') str[i] = 'f';
    else if (str[i]=='G') str[i] = 't';
    else if (str[i]=='S') str[i] = 'r';
    i++;
    goto label10;

    label11: printf("New string: %s\n", str);
    return 0;
}
*/

// Задание 3

int main() {

    char str[50];
    int i = 0;

    printf("Type text string here: ");
    gets(str);
    printf("Old string: %s\n", str);
    label10: if(str[i]=='\0') goto label11;
        switch(str[i])
        {
            case 'n':str[i]='0'; break;
            case 'o':str[i]='1'; break;
            case 'p':str[i]='2'; break;
            case 'q':str[i]='3'; break;
            case 'r':str[i]='4'; break;
            case 's':str[i]='5'; break;
            case 't':str[i]='6'; break;
            case 'u':str[i]='7'; break;
            case 'v':str[i]='8'; break;
            case 'w':str[i]='9'; break;
            case 'D':str[i]='k'; break;
            case 'L':str[i]='f'; break;
            case 'G':str[i]='t'; break;
            case 'S':str[i]='r'; break;
        }
        i++;
        goto label10;

    label11: printf("New string: %s\n", str);

    return 0;
}
