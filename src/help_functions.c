#include "s21_matrix.h"

int is_correct(matrix_t *A) {
  int status = OK;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0 ||
      A->rows == NAN || A->columns == NAN || A->rows == INFINITY ||
      A->columns == INFINITY) {
    status = ERROR_INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] == INFINITY || A->matrix[i][j] == NAN) {
          status = CALCULATION_ERROR;
        }
      }
    }
  }
  return status;
}

void minor_search(double **A, double **buffer, int skip_i, int skip_j,
                  int size) {
  int index_i = 0;
  int index_j = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i != skip_i && j != skip_j) {
        buffer[index_i][index_j++] = A[i][j];
        if (index_j == size - 1) {
          index_j = 0;
          index_i++;
        }
      }
    }
  }
}

double determinant_search(matrix_t *A, int size) {
  double result = 0.0;
  matrix_t buffer = {0};
  if (size == 1) {
    result = A->matrix[0][0];
  } else {
    int status = s21_create_matrix(size, size, &buffer);
    if (status == OK) {
      for (int i = 0; i < size; i++) {
        minor_search(A->matrix, buffer.matrix, 0, i, size);
        if (i % 2 == 0) {
          result += A->matrix[0][i] * determinant_search(&buffer, size - 1);
        } else {
          result -= A->matrix[0][i] * determinant_search(&buffer, size - 1);
        }
      }
      s21_remove_matrix(&buffer);
    }
  }
  return result;
}

int is_diagonal(matrix_t *A) {
  int status = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i == j) {
        continue;
      }
      if (A->matrix[i][j] != 0) {
        status = 0;
      }
    }
  }
  return status;
}

void set_sign(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i == j) {
        if (A->matrix[i][j] > 0 && result->matrix[i][j] < 0) {
          result->matrix[i][j] *= -1;
        }
      } else {
        result->matrix[i][j] = 0.0;
      }
    }
  }
}
