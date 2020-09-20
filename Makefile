CC=gcc
CFLAGS=

compile: src/sexpify-args.c
	mkdir -p build
	gcc src/sexpify-args.c -o build/sexpify

install: compile
	cp build/sexpify /usr/local/bin/sexpify
