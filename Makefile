all: $(patsubst src/%.c, bin/%, $(wildcard src/*.c))

bin/%: src/%.c
	gcc $< -o $@
