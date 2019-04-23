#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED
#include "sistema.h"

int score;
OBJETO lingua;
OBJETO pontaLingua;
OBJETO *moscas;
OBJETO *abelhas;
OBJETO fundoJogo[6];
OBJETO fada;
OBJETO galho;
OBJETO asteroide;
OBJETO asteroide2;

int qtdDeMoscas;
int qtdDeAbelhas;
int score;
int teclas[255];
int vida;
double velocidadeJogo;
int indiceDoSpriteMosca;
int indiceDoSpriteAbelha;
int indiceDoSpriteFada;
int posicaoGalho;

//Carregamento de Texturas usadas no jogo
GLuint moscaTextura[23];
GLuint abelhasTextura[6];
GLuint FadaTextura[3];
GLuint FundoFase1Textura[1];
GLuint FundoFase2Textura[1];
GLuint FundoFase3Textura[1];
GLuint BaseLinguaTextura[1];
GLuint PontaLinguaTextura[1];
GLuint VidaTextura[3];
GLuint TelasExtrasTextura[6];
GLuint GalhoTextura[2];
GLuint AsteroideTextura[1];


void iniciarPosicoes();
void desenharFundo();
void desenharParalax();
void desenharLingua();
void desenharMosca();
void desenharAbelha();
void desenharFada();	
void desenharDisplay();
void iniciaJogo();
void desenharTelaExtra();
int testeColisao(OBJETO *obj);
void iniciaProximaFase();

#endif // JOGO_H_INCLUDED
