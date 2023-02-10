#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = is_correct(A);
  if (A->columns != A->rows && status == OK) {
    status = CALCULATION_ERROR;
  } else if (A->rows == 1 && status == OK) {
    *result = A->matrix[0][0];
  } else if (A->rows != 1 && status == OK) {
    *result = determinant_search(A, A->rows);
  }
  return status;
}
