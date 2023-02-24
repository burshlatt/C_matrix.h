#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = is_correct(A);
  s21_create_matrix(A->rows, A->columns, result);
  if (status == OK && number != INFINITY && number != NAN) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else if (status == OK && (isinf(number) || isnan(number))) {
    status = CALCULATION_ERROR;
  }
  return status;
}
