all: copy MINILIBMX

copy:
	mkdir obj -p
	cp inc/*.h obj/
	cp src/*.c obj/

MINILIBMX: 
	make build

build:
	cd obj ;\
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic *.c *.h ;\
	cp a.out ../calc

uninstall:
	rm -rf obj
	rm calc

clean:
	rm -rf obj

reinstall:
	make uninstall
	make
