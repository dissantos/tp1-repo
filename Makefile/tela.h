#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

#define TELA_MENU 0
#define TELA_JOGO 1 //fases do jogo
#define TELA_PROXIMAFASE 2
#define TELA_VITORIA 3
#define TELA_DERROTA 9

#define TELA_LOGO 12
#define TELA_SCORE 4
#define TELA_AJUDA 5
#define TELA_HISTORIA 10
#define TELA_CREDITO 11

#define TELA_PAUSE 6
#define TELA_REINICIAR 7
#define TELA_ESC 8

double mundoX;
double mundoY;
int tela;
int faseAtual;
int larguraJanela;
int alturaJanela;


#endif // TELA_H_INCLUDED
