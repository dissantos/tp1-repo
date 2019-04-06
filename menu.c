#ifndef MENU_C_INCLUDED
#define MENU_C_INCLUDED
#include "menu.h"
#include "sistema.h"

OBJETO botaoJogar;
OBJETO botaoScore;
OBJETO botaoSair;
int mouseX,mouseY;

//recebe as coordenadas do mouse
void iniciaMenu(int x,int y){
    mouseX = x;
    mouseY = y;

    OBJETO tela;

    tela.posicao.x = 0+1;
    tela.posicao.y = 0+1;
    tela.velocidade.x = 0;
    tela.velocidade.y = 0;
    tela.altura = mundoY-1;
    tela.largura = mundoX-1;

    OBJETO objAtual = tela;


    desenhaObjeto(tela,"fundoMenu.png");


    botaoJogar.posicao.x = 500;
    botaoJogar.posicao.y = 500;
    botaoJogar.velocidade.x = 0;
    botaoJogar.velocidade.y = 0;
    botaoJogar.largura = 100;
    botaoJogar.altura = 50;

    //glColor3f(0,1,0);
    desenhaObjeto(botaoJogar,"play.png");

}

int identificarBotao(int x,int y){
    mouseX = x;
    mouseY = y;

    printf("%d %d\n",x,y);

    if(x >= botaoJogar.posicao.x && x <= botaoJogar.posicao.x + botaoJogar.largura && y >= botaoJogar.posicao.y && y <= botaoJogar.posicao.y + botaoJogar.altura )
    	return 1;

    return 0;
}



#endif // MENU_C_INCLUDED
