#include "menu.h"
#include "sistema.h"
#include <unistd.h>
#include<math.h>
#include <stdio.h>

OBJETO botaoJogar;
OBJETO botaoScore;
OBJETO botaoSair;
int mouseX,mouseY;

//desenha a logo do jogo
void desenhaLogo(){
	OBJETO logo;
    mundoX = 1200;
    mundoY = 800;
    logo.posicao.x = mundoX/2;
    logo.posicao.y = mundoY/2;
    logo.velocidade.x = 0;
    logo.velocidade.y = 0;
    logo.altura = mundoY;
    logo.largura = mundoX;
	desenhaObjeto(logo,LogoTextura[0]);
}

void iniciaMenu(){

    OBJETO tela;
    mundoX = 1200;
    mundoY = 800;
    tela.posicao.x = mundoX/2;
    tela.posicao.y = mundoY/2;
    tela.velocidade.x = 0;
    tela.velocidade.y = 0;
    tela.altura = mundoY;
    tela.largura = mundoX;


    
    //+++++++++++++++++++++++++++++++++++
    //  Botoes do menu
    //Botao Jogar
    JogarMenu.posicao.x = mundoX/2;
    JogarMenu.posicao.y = mundoY/2;
    JogarMenu.velocidade.x = 0;
    JogarMenu.velocidade.y = 0;
    JogarMenu.largura = 500;
    JogarMenu.altura = 300;

    //Botao Voltar
    sairMenu.posicao.x = 100;
    sairMenu.posicao.y = 50;
    sairMenu.velocidade.x = 0;
    sairMenu.velocidade.y = 0;
    sairMenu.largura = 500;
    sairMenu.altura = 300;

    //Botao Ajuda
    AjudaMenu.posicao.x = 100;
    AjudaMenu.posicao.y = 770;
    AjudaMenu.velocidade.x = 0;
    AjudaMenu.velocidade.y = 0;
    AjudaMenu.largura = 500;
    AjudaMenu.altura = 300;
    
    //Botao Creditos
    CreditosMenu.posicao.x = 1090;
    CreditosMenu.posicao.y = 50;
    CreditosMenu.velocidade.x = 0;
    CreditosMenu.velocidade.y = 0;
    CreditosMenu.largura = 500;
    CreditosMenu.altura = 300;

    //Botao Ranking Menu
    RankingMenu.posicao.x = mundoX/2;
    RankingMenu.posicao.y = 320;
    RankingMenu.velocidade.x = 0;
    RankingMenu.velocidade.y = 0;
    RankingMenu.largura = 500;
    RankingMenu.altura = 300;
 
    //++++++++++++++++++++++++++++++++++++

    //gera a imagem do menu
    if(delay < 90){
    	desenhaLogo();
    }
    else{
		desenhaObjeto(tela,MenuTextura[0]);
		desenhaObjeto(AjudaMenu,BotaoAjudaTextura[0]);
		desenhaObjeto(CreditosMenu,BotaoCreditosTextura[0]);
		desenhaObjeto(JogarMenu,BotaoJogarMenuTextura[0]);
		desenhaObjeto(sairMenu,BotaoVoltarMenuTextura[0]);
		desenhaObjeto(RankingMenu,BotaoRankingMenuTextura[0]);
	}
       //glColor3f(0,1,0);
}



void desenharHistoria(){
	//Tela com a historia antes do jogo

    mundoX = 1200;
    mundoY = 800;
    umaLindaHistoria.posicao.x = mundoX/2;
    umaLindaHistoria.posicao.y = mundoY/2;
    umaLindaHistoria.velocidade.x = 0;
    umaLindaHistoria.velocidade.y = 0;
    umaLindaHistoria.altura = mundoY;
    umaLindaHistoria.largura = mundoX;

    
    //Botao Voltar da Historia
    HistoryVoltar.posicao.x = 300;
    HistoryVoltar.posicao.y = 50;
    HistoryVoltar.velocidade.x = 0;
    HistoryVoltar.velocidade.y = 0;
    HistoryVoltar.altura = 300;
    HistoryVoltar.largura = 500;


    //Botao Voltar da Historia
    HistoryJogar.posicao.x = 1100;
    HistoryJogar.posicao.y = 750;
    HistoryJogar.velocidade.x = 0;
    HistoryJogar.velocidade.y = 0;
    HistoryJogar.altura = 300;
    HistoryJogar.largura = 500;
    
    desenhaObjeto(umaLindaHistoria,HistoryTextura[0]);
    desenhaObjeto(HistoryVoltar,BotaoVoltarHistoryTextura[0]);
    desenhaObjeto(HistoryJogar,BotaoJogarHistoryTextura[0]);
}

void desenharAjuda(){
 //Tela com a Ajuda
    OBJETO ajudinha;
    mundoX = 1200;
    mundoY = 800;
    ajudinha.posicao.x = mundoX/2;
    ajudinha.posicao.y = mundoY/2;
    ajudinha.velocidade.x = 0;
    ajudinha.velocidade.y = 0;
    ajudinha.altura = mundoY;
    ajudinha.largura = mundoX;
    desenhaObjeto(ajudinha,AjudaTextura[0]);
   
    //Botao Voltar da Ajuda
    AjudaVoltar.posicao.x = 300;
    AjudaVoltar.posicao.y = 50;
    AjudaVoltar.velocidade.x = 0;
    AjudaVoltar.velocidade.y = 0;
    AjudaVoltar.altura = 300;
    AjudaVoltar.largura = 500;
    desenhaObjeto(AjudaVoltar,BotaoVoltarAjudaTextura[0]);
}

void desenharCredito(){
	//Tela de Creditos
    OBJETO creditinhos;
    mundoX = 1200;
    mundoY = 800;
    creditinhos.posicao.x = mundoX/2;
    creditinhos.posicao.y = mundoY/2;
    creditinhos.velocidade.x = 0;
    creditinhos.velocidade.y = 0;
    creditinhos.altura = mundoY;
    creditinhos.largura = mundoX;
    desenhaObjeto(creditinhos,CreditosTextura[0]);

    //Botao Voltar dos Creditos
    creditinhosVoltar.posicao.x = 300;
    creditinhosVoltar.posicao.y = 50;
    creditinhosVoltar.velocidade.x = 0;
    creditinhosVoltar.velocidade.y = 0;
    creditinhosVoltar.altura = 300;
    creditinhosVoltar.largura = 500;
    desenhaObjeto(creditinhosVoltar,BotaoVoltarCreditosTextura[0]);
}

void identificarBotao(int x,int y){
		    mouseX = x;
		    mouseY = y;

		    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
		    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

		    float aspectMenu = (float) mundoX/mundoY;
		    float aspectWindow = (float) windowWidth/windowHeight;

		    int realX = mouseX;
		    int realY = mouseY;

		    if (aspectWindow > aspectMenu) {
			realX -= (windowWidth - (aspectMenu*windowHeight))/2;
		    } else {
			realY -= (windowHeight - (aspectMenu*windowWidth))/2;
		    }

		    int refMouseX = (realX) * (mundoX/windowWidth);
		    int refMouseY = mundoY - ((realY) * (mundoY/windowHeight));

	switch(tela){
		case TELA_MENU:
		    //----------------------------------------------------------------------------
		    //Menu
		    //Botao ajuda do menu
		    if (refMouseX > 23 && refMouseX < 103 && refMouseY > 755 && refMouseY < 790) {
			tela = TELA_AJUDA;
			glutPostRedisplay();
		    }

		    //Botao sair
		    if (refMouseX > 5 && refMouseX < 145 && refMouseY > 20 && refMouseY < 85) {
			printf("sair\n");
			exit(0);
		    }

		    //Botao creditos
		    if (refMouseX > 760 && refMouseX < 910 && refMouseY > 31 && refMouseY < 67) {
			tela = TELA_CREDITO;
			glutPostRedisplay();
		    }

		    //Botao ranking
		    if (refMouseX > 390 && refMouseX < 535 && refMouseY > 287 && refMouseY < 347) {
			printf("ranking\n");
		    }

		    //Botao jogar
		    if (refMouseX > 390 && refMouseX < 535 && refMouseY > 367 && refMouseY < 426) {
			tela = TELA_HISTORIA;
			glutPostRedisplay();
		    }
			break;
		case TELA_HISTORIA:
            //botao para voltar para o menu
			if(refMouseX >= HistoryVoltar.posicao.x - HistoryVoltar.largura/2 && refMouseX <= HistoryVoltar.posicao.x + HistoryVoltar.largura/2 &&
               refMouseY >= HistoryVoltar.posicao.y - HistoryVoltar.altura/2 && refMouseY <= HistoryVoltar.posicao.y + HistoryVoltar.altura/2){
                tela = TELA_MENU;
                glutPostRedisplay();
            }
            //botao para ir para o jogo em si
            if(refMouseX >= HistoryJogar.posicao.x - HistoryJogar.largura/2 && refMouseX <= HistoryJogar.posicao.x + HistoryJogar.largura/2 && 
               refMouseY >= HistoryJogar.posicao.y - HistoryJogar.altura/2 && refMouseY <= HistoryJogar.posicao.y + HistoryJogar.altura/2){
               	pararMusica();
                tela = TELA_JOGO;
                glutPostRedisplay();
            }
			//Ao cllicar em voltar, retorna ao menu

			break;
		case TELA_AJUDA:
            //botao para voltar para o menu
            if(refMouseX >= AjudaVoltar.posicao.x - AjudaVoltar.largura/2 && refMouseX <= AjudaVoltar.posicao.x + AjudaVoltar.largura/2 &&
               refMouseY >= AjudaVoltar.posicao.y - AjudaVoltar.altura/2 && refMouseY <= AjudaVoltar.posicao.y + AjudaVoltar.altura/2){
                tela = TELA_MENU;
                glutPostRedisplay();
            }
			break;
		case TELA_CREDITO:
            //botao para voltar para o menu
			if(refMouseX >= creditinhosVoltar.posicao.x - creditinhosVoltar.largura/2 && refMouseX <= creditinhosVoltar.posicao.x + creditinhosVoltar.largura/2 &&
               refMouseY >= creditinhosVoltar.posicao.y - creditinhosVoltar.altura/2 && refMouseY <= creditinhosVoltar.posicao.y + creditinhosVoltar.altura/2){
                tela = TELA_MENU;
                glutPostRedisplay();
            }
			break;	
	}
}

