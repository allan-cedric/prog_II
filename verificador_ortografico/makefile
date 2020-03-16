CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lm

OBJETOS = ortografia.o dicionario.o

#default
all: ortografia clean

#ligação
ortografia: $(OBJETOS)
	$(CC) $(OBJETOS) -o ortografia $(CFLAGS) $(LDLIBS)

#compilação
ortografia.o: ortografia.c dicionario.h
	$(CC) -c ortografia.c $(CFLAGS)

dicionario.o: dicionario.c dicionario.h
	$(CC) -c dicionario.c $(CFLAGS)

#arquivos temporários
clean:
	rm $(OBJETOS)
