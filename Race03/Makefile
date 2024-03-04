CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic -D_XOPEN_SOURCE=600 -D_POSIX_C_SOURCE=200112L
LIBS := -lncurses

EXECUTABLE := matrix_rain

all: $(EXECUTABLE)

$(EXECUTABLE): $(wildcard ./inc/*.h) $(wildcard ./src/*.c)
	mkdir -p ./obj
	$(CC) $(CFLAGS) -c ./src/*.c
	mv ./*.o ./obj
	$(CC) $(LIBS) $(CFLAGS) -o $(EXECUTABLE) ./obj/*.o

uninstall:
	rm -rf ./obj
	rm -rf ./$(EXECUTABLE)

clean:
	rm -rf ./obj

reinstall: uninstall all

