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
void desenharFundo();
void desenharLingua();
void desenharMosca();
void desenharScore();
void iniciaPrimeiraFase();
void desenharPause();
void desenharESC();
void desenharReinicio();
int testeColisaoMosca(OBJETO ob1, OBJETO ob2);
void movimentarLingua(unsigned char key);



#endif // JOGO_H_INCLUDED
