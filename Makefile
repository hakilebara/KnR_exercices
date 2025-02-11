all: $(patsubst src/%.c, bin/%, $(wildcard src/*.c))

bin/%: src/%.c | bin
	gcc -g $< -o $@

bin:
	mkdir -p $@
