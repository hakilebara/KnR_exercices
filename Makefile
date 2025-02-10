all: $(patsubst src/%.c, bin/%, $(wildcard src/*.c))

bin/%: src/%.c | bin
	gcc $< -o $@

bin:
	mkdir -p $@
