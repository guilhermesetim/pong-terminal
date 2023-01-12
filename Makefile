OBJS = $(addprefix ./obj/, main.o src.o)

all: compilar linkar

run:
	./bin/main.out

clean:
	rm ./bin/main.out ./obj/*.o

compilar: 
	g++ -c ./src/Ambiente.cpp -o ./obj/Ambiente.o
	g++ -c ./src/Bola.cpp -o ./obj/Bola.o
	g++ -c ./src/Placar.cpp -o ./obj/Placar.o
	g++ -c ./src/Raquete.cpp -o ./obj/Raquete.o
	g++ -c ./src/acaoTeclado.cpp -o ./obj/acaoTeclado.o
	g++ -c ./src/main.cpp -o ./obj/main.o	
	
linkar:
	g++ ./obj/*.o -o ./bin/main.out
