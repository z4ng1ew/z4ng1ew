CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CFLAGSGCOV = -fprofile-arcs -ftest-coverage
CFLAGSSANITIZE = -fsanitize=address
CFLAGSASAN = -fsanitize=address
CFLAGSLSAN = -fsanitize=leak
CFLAGSUBSAN = -fsanitize=undefined

LIB = s21_string.a
LIB_CFLAGS = -lcheck -lsubunit -lm


BASE_FUNC_PATH = base
S21_SPRINTF_PATH = advanced

LIB_SRC = $(wildcard $(BASE_FUNC_PATH)/*.c) \
          $(wildcard $(S21_SPRINTF_PATH)/*.c)

LIB_OBJ = $(LIB_SRC:.c=.o)

TEST_PATH = unit_tests
TEST_SRC = $(wildcard $(TEST_PATH)/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: test

rebuild: clean all

rebuild: clean sanitize

#  s21_string.a----------------------------------------------------------------------------------------

s21_string.a: clean $(LIB_OBJ)
	ar rcs $(LIB) $(LIB_OBJ)
	rm -f *.o

#  ----------------------------------------------------------------------------------------------------

clean:
	find . -type f -name "*.o" -o -name "*.a" -o -name "*.gcda" -o -name "*.gcno" -o -name "*.bak" | xargs rm -f
	rm -f $(TEST_PATH)/$(TEST_PATH) a.out
	rm -rf gcov_report/
	rm -f $(LIB) *.info *.log *.txt

#  TEST------------------------------------------------------------------------------------------------

test: clean s21_string.a $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -l:$(LIB) $(LIB_CFLAGS) -o $(TEST_PATH)/$(TEST_PATH)
	./unit_tests/unit_tests

#  GCOV------------------------------------------------------------------------------------------------

insert_flags_gcov:
	$(eval CFLAGS += $(CFLAGSGCOV))

gcov_report: clean insert_flags_gcov test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report

gcov:
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html

#  ----------------------------------------------------------------------------------------------------

clangn:
	find . -type f -name "*.c" -o -name "*.h" | xargs clang-format -n

clangi:
	find . -type f -name "*.c" -o -name "*.h" | xargs clang-format -i

valgrind:
	valgrind --tool=memcheck --leak-check=yes -s ./unit_tests/unit_tests 2>&1 | tee mem_leaks.log

insert_flags_sanitize:
	$(eval CFLAGS += $(CFLAGSSANITIZE))

sanitize: clean insert_flags_sanitize test



insert_flags_all_sanitizers:
	$(eval CFLAGS += $(CFLAGSASAN) $(CFLAGSLSAN) $(CFLAGSUBSAN))

all_sanitizers: clean insert_flags_all_sanitizers test