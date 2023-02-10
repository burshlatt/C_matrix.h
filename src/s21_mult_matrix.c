#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  int status_a = is_correct(A);
  int status_b = is_correct(B);
  s21_create_matrix(A->rows, B->columns, result);
  if (status_a == OK && status_b == OK) {
    if (result->rows == result->columns) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = 0.0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      status = CALCULATION_ERROR;
    }
  } else if (status_a == 1 || status_b == 1) {
    status = ERROR_INCORRECT_MATRIX;
  } else {
    status = CALCULATION_ERROR;
  }
  return status;
}
