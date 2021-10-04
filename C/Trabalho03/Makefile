# Makefile

# Linka códigos-objeto (cria executável main)
main: main.o auxiliar.o
	gcc -o main main.o auxiliar.o

# Compila main.c (cria código-objeto main.o)
main.o: main.c auxiliar.h
	gcc -c -o main.o main.c

# Compila auxiliar.c (cria código-objeto auxiliar.o)
auxiliar.o: auxiliar.c auxiliar.h
	gcc -c -o auxiliar.o auxiliar.c

# Remove executável e códigos-objeto
clean:
	rm -f main *.o