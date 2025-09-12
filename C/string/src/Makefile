CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TFLAGS = -lcheck

ifeq ($(shell uname), Linux)
	TFLAGS += -lm -lsubunit -pthread -lrt
endif

ifeq ($(shell uname), Darwin)
	TFLAGS += -fprofile-arcs -ftest-coverage
endif

FILES_C = s21_*.c
FILES_O = s21_*.o

all: s21_string.a

s21_string.a:
	$(CC) $(CFLAGS) -c $(FILES_C)
	ar -rcs $@ $(FILES_O)
	ranlib $@
	rm $(FILES_O)

test: s21_string.a
	checkmk clean_mode=1 ./tests/s21_test.check > ./tests/test.c
	$(CC) ./tests/test.c $(FILES_C) s21_string.a -o test1 $(TFLAGS) 
	./test1

gcov_report: s21_string.a 
	mkdir logs
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage s21_string.a ./tests/test.c $(FILES_C) -o logs/gcov_report $(TFLAGS)
	./logs/gcov_report
	gcovr --html-details --gcov-exclude ./tests/test.c -o logs/report.html
	open logs/report.html 
	
clean: 
	rm -rf *.o *.a .clang-format test1 logs *.gcda *.gcno ./tests/test.c

rebuild: clean all

style: 
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n --style=Google *.c *.h
	rm .clang-format

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i --style=Google *.h *.c
	rm .clang-format

cpp:
	cppcheck --enable=all $(FILES_C) --suppress=unusedFunction --suppress=missingIncludeSystem  s21_string.h 

leak:
	valgrind --tool=memcheck --leak-check=yes  ./test1

leakMac:
	leaks --atExit -- ./test1
