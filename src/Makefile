CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

s21_matrix.a: clean
	$(CC) $(CFLAGS) -c s21_*.c help_functions.c
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(CFLAGS) -c unit_tests.c -o unit_tests.o
	$(CC) unit_tests.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

gcov_report: s21_matrix.a
	$(CC) $(FLAGS) --coverage unit_tests.c s21_*.c s21_matrix.a $(TEST_LIBS) -o gcov_test
	./gcov_test
	lcov -t "s21_matrix" -o s21_matrix.info -c -d .
	genhtml -o report s21_matrix.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info report gcov_test s21_matrix

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h
	rm .clang-format
