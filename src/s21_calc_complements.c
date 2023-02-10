#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = is_correct(A);
  s21_create_matrix(A->columns, A->rows, result);
  if (A->columns != A->rows && status == OK) {
    status = CALCULATION_ERROR;
  } else if (A->columns == A->rows && status == OK) {
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      matrix_t buffer = {0};
      s21_create_matrix(A->rows, A->rows, &buffer);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          minor_search(A->matrix, buffer.matrix, i, j, A->rows);
          result->matrix[i][j] =
              pow(-1, i + j) * determinant_search(&buffer, A->rows - 1);
        }
      }
      s21_remove_matrix(&buffer);
    }
  }
  return status;
}
