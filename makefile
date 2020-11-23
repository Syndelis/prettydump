all: pdump

pdump: main.c
	gcc -g main.c -o pdump

install: pdump
	cp pdump ~/.local/bin