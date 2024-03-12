#include <stdio.h>

// Лабораторная работа №3. Вариант 15.

int main() {

    char str1[50], str2[50], str3[100], str4[96];
    int i, j, count;

    printf("Enter the first string: \n");
    gets(str1);

    printf("Enter the second string: \n");
    gets(str2);

    i = 0;
    while (str1[i++] != '\0');
    printf("First string length is: \t%d chars \n", i-1);

    i = 0;
    while (str2[i++] != '\0');
    printf("Second string length is: \t%d chars \n", i-1);

    j = 0;
    for(i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != ' ') {
            str3[j] = str1[i];
            j++;
        }
    }
    for(i = 0; str2[i] != '\0'; i++) {
        if (str2[i] != ' ') {
            str3[j] = str2[i];
            j++;
        }
    }

    str3[j] = '\0';
    printf("Combined first and second string is: %s\n", str3);

    i = 0;
    j = 0;
    count = 0;
    do {
        if ((i+1)%2 != 0 | count >=4)
        {
            str4[j] = str3[i];
            j++;
        }
        else if ((i+1)%2 == 0) {
            count++;
        }
        i++;
    } while (i < sizeof(str3));

    printf("Edited string is: %s\n", str4);

    return 0;
}
