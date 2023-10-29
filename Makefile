CC = g++
flags = -Wundef -Werror -Wall
exec = calculadora

$(exec): main.o bin/abbNode.o bin/abb.o bin/node.o bin/stack.o
	$(CC) $(flags) main.o bin/abbNode.o bin/abb.o bin/node.o bin/stack.o -o $(exec)
	
run: $(exec)
	./$(exec)
	
all: clean run
	
main.o: main.cpp
	$(CC) $(flags) main.cpp -o main.o -c

bin/abbNode.o: Clasescpp/abbNode.cpp
	$(CC) $(flags) Clasescpp/abbNode.cpp -o bin/abbNode.o -c

bin/abb.o: Clasescpp/abb.cpp
	$(CC) $(flags) Clasescpp/abb.cpp -o bin/abb.o -c

bin/node.o: Clasescpp/node.cpp
	$(CC) $(flags) Clasescpp/node.cpp -o bin/node.o -c

bin/stack.o: Clasescpp/stack.cpp
	$(CC) $(flags) Clasescpp/stack.cpp -o bin/stack.o -c

clean:
	rm bin/*.o *.o $(exec)