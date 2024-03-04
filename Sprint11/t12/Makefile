CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
LANG = clang

PROJ_NAME = PLAYLIST
EXEC_NAME = playlist
.PHONY: all clean uninstall reinstall
all: $(PROJ_NAME)
$(PROJ_NAME):
	mkdir -p ./obj
	$(LANG) $(CFLAGS) ./src/*.c -I ./inc -c
	mv *.o ./obj
	$(LANG) $(CFLAGS) ./obj/* -o $(EXEC_NAME)
uninstall:
	rm -rf ./obj $(EXEC_NAME)
clean:
	rm -rf ./obj
reinstall: uninstall $(PROJ_NAME)

