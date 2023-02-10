#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  int status_a = is_correct(A);
  int status_b = is_correct(B);
  s21_create_matrix(A->rows, A->columns, result);
  if (status_a == OK && status_b == OK) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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
