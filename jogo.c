#include "jogo.h"
#include "sistema.h"
#include "tela.h"
#include <time.h>
#include <math.h>


void desenharFundo(){
    glColor3f(0,0.8,1);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0,0,0);
        glVertex3f(mundoX,0,0);
        glVertex3f(mundoX,mundoY,0);
        glVertex3f(0,mundoY,0);
    glEnd();
}

void desenharLingua(){
    glColor3f(1,0.6,0.9);


    desenhaObjeto(lingua,"baseLingua.png");
    desenhaObjeto(pontaLingua,"pontaLingua.png");


    glEnd();
}

void desenharMoscas(){
	double vel;
    srand(time(NULL));
    for(int i  = 0; i < qtdDeMoscas; i++){
        vel = rand()%100;
        if(rand() % 2 == 0)
            vel *= -1;
        vel = (double)vel/100;
        
        moscas[i].velocidade.x+= vel;
        moscas[i].posicao.y -= 2;
        if(moscas[i].posicao.y <= 0 || moscas[i].posicao.x <= 0 || moscas[i].posicao.x >= 400){
        	moscas[i].posicao.y = 800;
        	moscas[i].posicao.x = rand()%401;
        	moscas[i].velocidade.x = 0;
        	moscas[i].velocidade.y = 0;
        }
	}
	
	for(int i = 0; i < qtdDeMoscas ; i++){
		if(moscas[i].vaiDesenhar == 1){// corrigir essa parte 
			desenhaObjeto(moscas[i],"mosca1.png");
		}
	}
}

void desenharDisplay(){
	OBJETO vidaDisplay;
	vidaDisplay.posicao.x = 30;
	vidaDisplay.posicao.y = 775;
	vidaDisplay.velocidade.x = 0;
	vidaDisplay.velocidade.y = 0;
	vidaDisplay.altura = 25;
	vidaDisplay.largura = 60;
	
	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0,750,0);
		glVertex3f(400,750,0);
		glVertex3f(400,800,0);
		glVertex3f(0,800,0);	
	glEnd();
	
	switch(vida){
		case 3:
			desenhaObjeto(vidaDisplay,"3vidas.png");
			break;
		case 2:
			desenhaObjeto(vidaDisplay,"2vidas.png");
			break;
		case 1:
			desenhaObjeto(vidaDisplay,"1vida.png");
			break;
	}
	
	
	
	glColor3f(1,1,1);
	escreveTexto(  GLUT_BITMAP_9_BY_15 , "SCORE:" , 300,760,0);
	char pontuacao[5];
	sprintf(pontuacao,"%d",score);
	
	escreveTexto( GLUT_BITMAP_9_BY_15 , pontuacao, 370,760,0 );
}


void desenharESC(){
	OBJETO telaESC;
	telaESC.posicao.x = 200;
	telaESC.posicao.y = 400;
	telaESC.velocidade.x = 0;
	telaESC.velocidade.y = 0;
	telaESC.altura = 800;
	telaESC.largura = 400;
	
	desenhaObjeto(telaESC, "telaESC.png");
}

void desenharPause(){
	OBJETO telaPause;
	telaPause.posicao.x = 200;
	telaPause.posicao.y = 400;
	telaPause.velocidade.x = 0;
	telaPause.velocidade.y = 0;
	telaPause.altura = 800;
	telaPause.largura = 400;
	
	desenhaObjeto(telaPause, "telaPause.png");

}

void desenharReinicio(){
	OBJETO telaReinicio;
	telaReinicio.posicao.x = 200;
	telaReinicio.posicao.y = 400;
	telaReinicio.velocidade.x = 0;
	telaReinicio.velocidade.y = 0;
	telaReinicio.altura = 800;
	telaReinicio.largura = 400;
	
	desenhaObjeto(telaReinicio, "telaReinicio.png");

}


void testeColisaoMosca(){
	double distancia, raio1,raio2;
	for(int i = 0; i < qtdDeMoscas; i++){
		if(moscas[i].vaiDesenhar == 1){
			distancia = sqrt(pow((pontaLingua.posicao.x + pontaLingua.velocidade.x - moscas[i].posicao.x + moscas[i].velocidade.x),2) + 									pow((pontaLingua.posicao.y + pontaLingua.velocidade.y - moscas[i].posicao.y + moscas[i].velocidade.y),2));
			raio1 = sqrt(pow((pontaLingua.largura/2),2) + pow((pontaLingua.altura/2),2));
			raio2 = sqrt(pow((moscas[i].largura/2),2) + pow((moscas[i].altura/2),2));
			if(distancia <= (raio1 + raio2) ){
				moscas[i].vaiDesenhar = 0;
				score +=  10;
			}
		}
	}
}

void iniciaPrimeiraFase(){
    mundoX = 400;
    mundoY = 800;
    

    desenharFundo();
    desenharLingua();
    desenharMoscas();
    desenharDisplay();
    //desenhaQtdDeMoscas();
}


