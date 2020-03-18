CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lm

EXEC = ortografia
OBJ = ortografia.o dicionario.o

#Default
all: ortografia

#Ligação
ortografia: $(OBJ)
	$(CC) $(OBJ) -o ortografia $(CFLAGS) $(LDLIBS)

#Compilação
ortografia.o: ortografia.c dicionario.h
	$(CC) -c ortografia.c $(CFLAGS)

dicionario.o: dicionario.c dicionario.h
	$(CC) -c dicionario.c $(CFLAGS)

#Remove arquivos temporários
clean:
	-rm -f $(OBJ) *~

#Remove tudo que não é código-fonte
purge: clean
	-rm -f $(EXEC)
