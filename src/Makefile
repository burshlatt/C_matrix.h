CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

matrix.a: clean
	$(CC) $(CFLAGS) -c s21_*.c help_functions.c
	ar rcs matrix.a *.o

test: matrix.a
	$(CC) $(CFLAGS) -c unit_tests.c -o unit_tests.o
	$(CC) unit_tests.o matrix.a $(TEST_LIBS) -o matrix
	./matrix

gcov_report: matrix.a
	$(CC) $(FLAGS) --coverage unit_tests.c s21_*.c matrix.a $(TEST_LIBS) -o gcov_test
	./gcov_test
	lcov -t "matrix" -o matrix.info -c -d .
	genhtml -o report matrix.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info report gcov_test matrix
