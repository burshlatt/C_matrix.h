#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = is_correct(A);
  double det = 0.0;
  int is_created = 0;
  matrix_t minor = {0};
  matrix_t transpose = {0};
  if (status == OK) {
    s21_determinant(A, &det);
    if (det == 0.0) {
      status = CALCULATION_ERROR;
    } else {
      status = s21_calc_complements(A, &minor);
      if (status == OK) {
        if (is_diagonal(A)) {
          set_sign(A, &minor);
        }
        status = s21_transpose(&minor, &transpose);
        if (status == OK) {
          s21_mult_number(&transpose, (1 / fabs(det)), result);
          is_created = 1;
        }
        s21_remove_matrix(&transpose);
      }
      s21_remove_matrix(&minor);
    }
  }
  if (!is_created) {
    s21_create_matrix(0, 0, result);
  }
  return status;
}
