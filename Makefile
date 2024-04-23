CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++17 -pedantic
TEST_LIB = s21_matrix_oop
GCOVR_FLAGS = --coverage -fprofile-arcs -ftest-coverage -O0 -fPIC
VALGRIND = --leak-check=full --show-leak-kinds=all --track-origins=yes

TEST_DIR = ./tests
REPORT_DIR = ./report

GTEST_FLAGS =
D_OS =
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	GTEST_FLAGS = -lcheck -lgtest -lsubunit -lm -lpthread -lrt 
	D_OS = -D __My_Linux__
else
	GTEST_FLAGS = -lcheck -lm -lpthread -lgtest
	D_OS = -D __My_APPLE__
endif

OPEN = open
ifeq ($(OS), Linux)
	OPEN = xdg-open
endif



all: clean $(TEST_LIB).a test

$(TEST_LIB).a: clean
	$(CC) -c $(FLAGS) $(TEST_LIB).cpp
	ar rc $(TEST_LIB).a *.o
	ranlib $(TEST_LIB).a

clean:
	rm -f *.a *.o *.so *.out leak.log
	rm -rf $(TEST_DIR)/*.cpp $(TEST_DIR)/s21_matrix_oop.* $(TEST) $(TEST).o
	rm -rf $(REPORT_DIR)
	rm -rf $(TEST_DIR)/test_cov
	rm -rf $(TEST_DIR)/*.gcno $(TEST_DIR)/*.info  $(TEST_DIR)/*.gcda

valgrind: test
	valgrind $(VALGRIND) --log-file="leak.log" ./test.out

check_style:
	clang-format -n -style=google *.cpp *.h 

format_style:
	clang-format -i -style=google *.cpp *.h 

test: $(TEST_LIB).a main_test.o 
	$(CC) $(FLAGS) -o test.out main_test.o $(TEST_LIB).a $(GTEST_FLAGS) $(GCOVR_FLAGS)
	./test.out

main_test.o: main_test.cpp test_operators.h test_functions.h test_constructors.h
	$(CC) $(FLAGS) -c $< -o $@

gcov_report: clean $(TEST_LIB).cpp main_test.o
	mkdir -p $(REPORT_DIR)
	$(CC) $(FLAGS) $(GCOVR_FLAGS) $(TEST_LIB).cpp main_test.o $(GTEST_FLAGS) -o $(TEST_DIR)/test_cov
	$(TEST_DIR)/test_cov
	gcovr -r . --html --html-details -o $(REPORT_DIR)/coverage-report.html
	$(OPEN) $(REPORT_DIR)/coverage-report.html  


.PHONY: all clean gcov_report valgrind check_style format_style test