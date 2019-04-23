#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED
#include "vetor.h"

typedef struct{
    VETOR posicao;
    VETOR velocidade;
    double largura;
    double altura;
    int vaiDesenhar;
}OBJETO;


#endif // PERSONAGEM_H_INCLUDED
