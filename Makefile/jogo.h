#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED
#include "sistema.h"

int score;
OBJETO lingua;
OBJETO pontaLingua;
OBJETO *moscas;
int qtdDeMoscas;

void desenharFundo();
void desenharLingua();
void desenharMosca();
void iniciaPrimeiraFase();
void desenharPause();
void desenharESC();
void desenharReinicio();
void movimentarLingua(unsigned char key);



#endif // JOGO_H_INCLUDED
