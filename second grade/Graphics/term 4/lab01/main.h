#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

matrix_t create_matrix(int rows, int columns);
void remove_matrix(matrix_t *A);
double **fill_matrix(int rows, int cols);
double get_det(matrix_t *A);
void print_me(matrix_t A);
int gauss_elim(matrix_t *A);
void save_to_file(matrix_t A);