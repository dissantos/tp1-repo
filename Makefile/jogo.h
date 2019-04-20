#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED
#include "sistema.h"

int score;
OBJETO lingua;
OBJETO pontaLingua;
OBJETO *moscas;
OBJETO *abelhas;
OBJETO fundoJogo[2];
int qtdDeMoscas;
int qtdDeAbelhas;
int score;
int teclas[255];
int vida;
double velocidadeJogo;
int indiceDoSpriteMosca;
int indiceDoSpriteAbelha;

void iniciarPosicoes();
void desenharFundo();
void desenharLingua();
void desenharMosca();
void desenharAbelha();
void desenharDisplay();
void iniciaJogo();
void desenharPause();
void desenharESC();
void desenharReinicio();
void desenharProximaFase();
void desenharVitoria();
void testeColisaoMosca();
void iniciaProximaFase();




#endif // JOGO_H_INCLUDED
