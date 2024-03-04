all: MINILIBMX


MINILIBMX:
	mkdir -p obj
	cp src/* obj/
	cp inc/* obj/
	make build
	make create_lib

files = $(wildcard obj/*.[c|h])
build:
	cd obj; \
	for file in $(files); do\
		clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c  ../$$file ;\
	done;

create_lib:
	ar -rc minilibmx.a obj/*.o obj/*.h.gch
	ranlib minilibmx.a 

little_clean:
	rm *.o
	rm obj/*.h
	rm obj/*.c 
	rm obj/*.o 
	rm obj/*.h.gch 

uninstall:
	rm -rf obj
	rm *.a 

clean:
	rm -rf obj

reinstall:
	make uninstall
	make
