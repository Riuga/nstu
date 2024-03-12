// Лабораторная работа №5

#include <stdio.h>
#include <stdlib.h>

#define size 3

struct State {
    char name_d[20];
    int number_r;
    int space;
    int price;
};


/*int main() {
    struct State routes[size];
    // filling array
    for (int route = 0; route < size; route++) {
        printf("Typing template: <district> <number of rooms> <space> <price>\n");
        printf("\nRoute's %d data:\n", route + 1);
        scanf("%s %d %d %d",
              routes[route].name_d,
              &routes[route].number_r,
              &routes[route].space,
              &routes[route].price);
    }
    // print routes
    for (int route = 0; route < size; route++) {
        printf("\nRoute's %d data:\n", route + 1);
        printf("\n\tName of district: %s",   routes[route].name_d);
        printf("\n\tNumber of rooms: %d", routes[route].number_r);
        printf("\n\tSpace: %d",  routes[route].space);
        printf("\n\tPrice: %d",   routes[route].price);
    }
    return 0;
}

*/

/*void sort(struct State* routes[size]) {
    int start = 0;
    int index_max = -1;
    int max = 10000;
    while (start < size) {
        max = -1;
        index_max = -1;
        for (int route = start; route < size; route++) {
                max = routes[route]->number_r;
                index_max = route;
            }
        }

        // swap
        struct State* temp = routes[index_max];
        routes[index_max] = routes[start];
        routes[start] = temp;

        start++;
    }
*/

void sort(struct State* routes[size]) {
    int start = 0;
    int index_max = -1;
    int max = 10000;
    while (start < size) { // each route must be checked
        max = 1000;
        index_max = -1;
        for (int route = start; route < size; route++) { // don't check sorted ones
            if (routes[route]->number_r < max) {
                max = routes[route]->number_r;
                index_max = route;
            }
        }

        // swap
        struct State* temp = routes[index_max];
        routes[index_max] = routes[start];
        routes[start] = temp;

        start++;
    }
}

int main() {
    struct State* routes[size];
    for (int route = 0; route < size; route++) {
        routes[route] = malloc(sizeof(struct State));
    }
    // filling array
    printf("Typing template: <district> <number of rooms> <space> <price>\n");
    for (int route = 0; route < size; route++) {
        printf("\nRoute's %d data:\n", route + 1);
        scanf("%s %d %d %d",
              routes[route]->name_d,
              &routes[route]->number_r,
              &routes[route]->space,
              &routes[route]->price);
    }

    sort (&routes);

    // print sorted routes
    for (int route = 0; route < size; route++) {
        printf("\n\nRoute's %d data:", route + 1);
        printf("\n\tDistrict: %s",   routes[route]->name_d);
        printf("\n\tNumber of rooms: %d", routes[route]->number_r);
        printf("\n\tSpace: %d",  routes[route]->space);
        printf("\n\tPrice: %d",   routes[route]->price);
    }
    return 0;
}