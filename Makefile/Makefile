CC=gcc
OPCOES_COMPILADOR=-I. -I/usr/include/SOIL -lSOIL -lglut -lGLU -lGLEW -lGL -lSDL -lSDL_mixer -lm
TODOS_ARQUIVOS_PONTOH = tela.h menu.h personagem.h vetor.h jogo.h
TODOS_ARQUIVOS_OBJ = main.o sistema.o menu.o jogo.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o main $^ $(OPCOES_COMPILADOR)

run: all
	(cd .. && exec Makefile/main)

clean:
	rm *.o main
