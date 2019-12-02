GPP=g++

all: clean compile run

clean:
	rm -rf bin/*

compile:
	$(GPP) src/rsa_cpu.cpp -o bin/rsa_cpu

run:
	bin/rsa_cpu