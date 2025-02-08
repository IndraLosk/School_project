C_FLags= gcc -Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE

all: s21_cat 

s21_cat: s21_cat.c 
	 $(C_FLags) s21_cat.c -o s21_cat
	
test:
	bash test_cat.sh

clean:
	rm -rf s21_cat