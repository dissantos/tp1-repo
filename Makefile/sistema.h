#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "personagem.h"
#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

GLuint carregaTextura(const char* arquivo);

void escreveTexto(void * font, char *s, float x, float y, float z);

void desenhaObjeto(OBJETO objAtual,GLuint idTextura);

char *gerarNomeTextura(char *nome, int indice);

void iniciarMusica(char const nome[40], int loop);

void pararMusica();

#endif // SISTEMA_H_INCLUDED
