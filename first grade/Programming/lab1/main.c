#include <stdio.h>

//Лабораторная работа 1 Вариант 15

//Задание 1

/*
static int A = 12, B = 8, C = 34, D = 123;

int main() {
    printf("\n\t\tИсходные данные:\n\tA=%d, B=%d, C=0%o, D=0%o", A, B, C, D);
    A = (A * C / D + --B)/4;
    B -= 6;
    C = (C + ++A + ++B) * 2;
    D = (B & 128) | (C >> 1) & 8;
    printf("\n\t\tРезультаты расчета:\n\tA=%d B=%d C=0%o D=0%o",A,B,C,D);
    return 0;
}
*/

//Задание 2

/*
int main() {
    static int A = 12, B = 8, C = 34, D = 123;
    printf("\n\t\tИсходные данные:\n\tA=%d, B=%d, C=0%o, D=0%o", A, B, C, D);
    A = (A * C / D + --B)/4;
    B -= 6;
    C = (C + ++A + ++B) * 2;
    D = (B & 128) | (C >> 1) & 8;
    printf("\n\t\tРезультаты расчета:\n\tA=%d B=%d C=0%o D=0%o",A,B,C,D);
    return 0;
}
*/

// Задание 3

/*
int main() {
    static int A, B, C, D;
    printf("Введите A, B, C, D: ");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("\n\t\tИсходные данные:\n\tA=%d, B=%d, C=0%o, D=0%o", A, B, C, D);
    A = (A * C / D + --B)/4;
    B -= 6;
    C = (C + ++A + ++B) * 2;
    D = (B & 128) | (C >> 1) & 8;
    printf("\n\t\tРезультаты расчета:\n\tA=%d B=%d C=0%o D=0%o",A,B,C,D);
    return 0;
}
*/

// Задание 4

/*
int main() {
    auto int A, B, C, D;
    printf("\n\t\tДо присваивания:\n\tA=%d B=%d C=0%o D=0%o",A,B,C,D);
    printf("Введите A, B, C, D: ");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("\n\t\tИсходные данные:\n\tA=%d, B=%d, C=0%o, D=0%o", A, B, C, D);
    A = (A * C / D + --B)/4;
    B -= 6;
    C = (C + ++A + ++B) * 2;
    D = (B & 128) | (C >> 1) & 8;
    printf("\n\t\tРезультаты расчета:\n\tA=%d B=%d C=0%o D=0%o",A,B,C,D);
    return 0;
}
*/

// Задание 5

/*
#include "lab1.h"
int main() {
    printf("Введите A, B, C, D: ");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("\n\t\tИсходные данные:\n\tA=%d, B=%d, C=0%o, D=0%o", A, B, C, D);
    A = (A * C / D + --B)/4;
    B -= 6;
    C = (C + ++A + ++B) * 2;
    D = (B & 128) | (C >> 1) & 8;
    printf("\n\t\tРезультаты расчета:\n\tA=%d B=%d C=0%o D=0%o",A,B,C,D);
    return 0;
}
*/

// Задание 6

/*
static int mas[] = {12, 8, 34, 123};

int main() {
    printf("\n\t\tИсходные данные:\n\mas[0]=%d mas[1]=%d mas[2]=0%o mas[3]=0%o", mas[0],mas[1],mas[2],mas[3]);
    mas[0] = (mas[0] * mas[2] / mas[3] + --mas[1])/4;
    mas[1] -= 6;
    mas[2] = (mas[2] + ++mas[0] + ++mas[1]) * 2;
    mas[3] = (mas[1] & 128) | (mas[2] >> 1) & 8;
    printf("\n\t\tРезультаты расчета:\n\mas[0]=%d mas[1]=%d mas[2]=0%o mas[3]=0%o", mas[0],mas[1],mas[2],mas[3]);
    return 0;
};
*/
