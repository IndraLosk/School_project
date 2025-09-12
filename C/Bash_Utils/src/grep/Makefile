C_FLags=-Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE

all: build 

build: s21_grep 

s21_grep: s21_grep.c 
	gcc $(C_FLags) s21_grep.c -o s21_grep

test:
	bash test_grep.sh

clean:
	rm -rf s21_grep

