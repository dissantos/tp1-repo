#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED
#include "sistema.h"

int score;
OBJETO lingua;
OBJETO pontaLingua;
OBJETO *moscas;
int qtdDeMoscas;
int score;
int teclas[255];
int vida;

void desenharFundo();
void desenharLingua();
void desenharMosca();
void desenharDisplay();
void iniciaPrimeiraFase();
void desenharPause();
void desenharESC();
void desenharReinicio();
void testeColisaoMosca();




#endif // JOGO_H_INCLUDED
