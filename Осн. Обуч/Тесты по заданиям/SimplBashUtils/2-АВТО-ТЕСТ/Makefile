Project_Name = grep
Flags = -Wall -Werror -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L

all: s21_$(Project_Name)

s21_$(Project_Name): clean
	gcc $(Flags) s21_$(Project_Name).c -o s21_$(Project_Name) -g -std=c11

clean:
	rm -rf *.out s21_$(Project_Name)

style:
	clang-format -style=google -n *.c *.h

format:
	clang-format -style=google -i *.c *.h
