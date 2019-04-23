#include "sistema.h"
#include "tela.h"
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void iniciaMenu();
void desenhaLogo();
void desenharHistoria();
void desenharAjuda();
void desenharCredito();
void identificarBotao(int x, int y);
int delay;

OBJETO JogarMenu;
OBJETO AjudaMenu;
OBJETO CreditosMenu;
OBJETO sairMenu;
OBJETO RankingMenu;
OBJETO creditinhosVoltar;
OBJETO AjudaVoltar;
OBJETO HistoryVoltar;
OBJETO HistoryJogar;
OBJETO umaLindaHistoria;

GLuint MenuTextura[1];
GLuint CreditosTextura[1];
GLuint AjudaTextura[1];
GLuint HistoryTextura[1];
GLuint LogoTextura[1];
GLuint BotaoVoltarMenuTextura[1];
GLuint BotaoAjudaTextura[1];
GLuint BotaoCreditosTextura[1];
GLuint BotaoJogarMenuTextura[1];
GLuint BotaoRankingMenuTextura[1];
GLuint BotaoVoltarCreditosTextura[1];
GLuint BotaoVoltarAjudaTextura[1];
GLuint BotaoVoltarHistoryTextura[1];
GLuint BotaoJogarHistoryTextura[1];

#endif // MENU_H_INCLUDED
