all: MINILIBMX create_lib	
	

MINILIBMX: obj/mx_printchar.o obj/mx_printint.o obj/mx_printstr.o obj/mx_strcpy.o obj/mx_strlen.o obj/mx_strcmp.o obj/mx_isdigit.o obj/mx_isspace.o obj/mx_atoi.o obj/header.h.gch

obj/mx_printchar.o: 
	mkdir -p obj
	cp src/mx_printchar.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_printchar.c -o obj/mx_printchar.o

obj/mx_printint.o: 
	mkdir -p obj
	cp src/mx_printint.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_printint.c -o obj/mx_printint.o

obj/mx_printstr.o: 
	mkdir -p obj
	cp src/mx_printstr.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_printstr.c -o obj/mx_printstr.o

obj/mx_strcpy.o: 
	mkdir -p obj
	cp src/mx_strcpy.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_strcpy.c -o obj/mx_strcpy.o

obj/mx_strlen.o: 
	mkdir -p obj
	cp src/mx_strlen.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_strlen.c -o obj/mx_strlen.o

obj/mx_strcmp.o:
	mkdir -p obj
	cp src/mx_strcmp.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_strcmp.c -o obj/mx_strcmp.o

obj/mx_isdigit.o: 
	mkdir -p obj
	cp src/mx_isdigit.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_isdigit.c -o obj/mx_isdigit.o

obj/mx_isspace.o:
	mkdir -p obj
	cp src/mx_isspace.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_isspace.c -o obj/mx_isspace.o

obj/mx_atoi.o: 
	mkdir -p obj
	cp src/mx_atoi.c obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/mx_atoi.c -o obj/mx_atoi.o

obj/header.h.gch:
	mkdir -p obj
	cp inc/header.h obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/header.h -o obj/header.h.gch

create_lib:
	ar -src minilibmx.a obj/mx_printchar.o obj/mx_printint.o obj/mx_printstr.o obj/mx_strcpy.o obj/mx_strlen.o obj/mx_strcmp.o obj/mx_isdigit.o obj/mx_isspace.o obj/mx_atoi.o obj/header.h.gch
	ranlib minilibmx.a

uninstall:
	rm -rf obj
	rm minilibmx.a

clean:
	rm -rf obj

reinstall:
	make uninstall
	make
