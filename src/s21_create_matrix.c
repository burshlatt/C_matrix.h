#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (rows > 0 && columns > 0 && rows != NAN && rows != INFINITY &&
      columns != NAN && columns != INFINITY) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = NULL;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = NULL;
        result->matrix[i] = (double *)malloc(columns * sizeof(double));
        if (result->matrix[i] == NULL) {
          i = rows;
        }
      }
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = 0;
        }
      }
    } else {
      result->rows = 0;
      result->columns = 0;
      result->matrix = NULL;
      status = ERROR_INCORRECT_MATRIX;
    }
  } else {
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;
    status = ERROR_INCORRECT_MATRIX;
  }
  return status;
}
