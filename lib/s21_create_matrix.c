#include "../s21_matrix.h"

// Вовсе не так в ночи беззвездной

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL) {
    return INCORRECT_MATRIX;
  }

  int matrix_status = OK;

  if (rows < 1 || columns < 1) {
    matrix_status = INCORRECT_MATRIX;
    result->matrix = NULL;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows + rows * columns, sizeof(double));
    if (result->matrix == NULL) {
      matrix_status = INCORRECT_MATRIX;
    } else {
      // allocating one block of memory for everything at once
      double *start = (double *)(result->matrix + rows);
      // indexing our matrix
      int iteration_limit = rows <= columns ? columns : rows;
      for (int i = 0; i < iteration_limit; i++) {
        result->matrix[i] = start + i * columns;
      }
    }
  }

  return matrix_status;
}
