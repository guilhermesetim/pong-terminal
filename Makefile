
all:
	g++ main.cpp src/*.cpp -o main.out

run:
	./main.out

clean:
	rm main.out
