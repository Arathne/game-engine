compile:
	cmake -S . -B build
	cd build && make

run:
	build/engine

valgrind:
	valgrind build/engine

clean:
	rm -rf build
