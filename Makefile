compile:
	cmake -S . -B build
	cd build && make

run:
	build/engine

clean:
	rm -rf build
