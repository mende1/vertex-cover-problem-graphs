all: run

run:
	g++ -o main main.cpp && ./main && rm main
