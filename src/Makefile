CC = gcc
FLAGS= -std=c11 -Wall -Werror -Wextra
UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lm -lrt -lpthread -lsubunit
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif

all: clean s21_decimal.a
deafult: all
s21_decimal.o:
	gcc $(FLAGS) -c functions/*/*.c
s21_decimal.a: s21_decimal.o 
	ar cr s21_decimal.a *.o
clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda *.info s21_decimal report
test: clean
	gcc $(FLAGS) -o s21_decimal tests/*.c tests/*/*.c functions/*/*.c -lcheck -lm $(LDFLAGS)
	./s21_decimal
add_coverage_flag:
	$(eval FLAGS += --coverage)
gcov_report: add_coverage_flag test
	lcov -t "stest" -o s21_decimal.info -c -d .
	genhtml -o report s21_decimal.info
	$(OPEN_CM) report/index.html