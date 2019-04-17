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
    for(int i  = 0; i < 10; i++){
        vel = rand()%100;
        if(rand() % 2 == 0)
            vel *= -1;
        vel = (double)vel/100;
        
        moscas[i].velocidade.x+= vel;
        vel = rand()%100;
        if(rand() % 2 == 0)
            vel*= -1;
        vel = (double)vel/100;
        moscas[i].velocidade.y += vel;
        moscas[i].posicao.y -= 1;
        if(moscas[i].posicao.y <= 0 || moscas[i].posicao.x <= 0 || moscas[i].posicao.x >= 400){
        	moscas[i].posicao.y = 800;
        	moscas[i].posicao.x = rand()%401;
        	moscas[i].velocidade.x = 0;
        	moscas[i].velocidade.y = 0;
        }
	}
	
	for(int i = 0; i < qtdDeMoscas ; i++)
		if(moscas[i].vaiDesenhar == 1)// corrigir essa parte 
			desenhaObjeto(moscas[i],"mosca1.png");
}

void desenharScore(){
	glColor3f(1,1,1);
	escreveTexto(  GLUT_BITMAP_9_BY_15 , "SCORE:" , 300,750,0);
	char pontuacao[5];
	sprintf(pontuacao,"%d",score);
	
	escreveTexto( GLUT_BITMAP_9_BY_15 , pontuacao, 370,750,0 );
}

void iniciaPrimeiraFase(){
    mundoX = 400;
    mundoY = 800;
    

    desenharFundo();
    desenharLingua();
    desenharMoscas();
    desenharScore();
}

void desenharESC(){
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0,0,0);
		glVertex3f(mundoX,0,0);
		glVertex3f(mundoX,mundoY,0);
		glVertex3f(0,mundoY,0);
	glEnd();
	
	glColor3f(1,0,0);
	escreveTexto( GLUT_BITMAP_TIMES_ROMAN_24, "Se deseja sair do jogo aperte S",50,400,0);
	escreveTexto( GLUT_BITMAP_TIMES_ROMAN_24, "se nao aperte N",100,350,0);
}

void desenharPause(){
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0,0,0);
		glVertex3f(mundoX,0,0);
		glVertex3f(mundoX,mundoY,0);
		glVertex3f(0,mundoY,0);
	glEnd();
	
	glColor3f(0,0,1);
	escreveTexto( GLUT_BITMAP_TIMES_ROMAN_24, "JOGO PAUSADO",50,400,0);
	escreveTexto(  GLUT_BITMAP_9_BY_15 , "Aperte 's' para continuar...",50,350,0);

}

void desenharReinicio(){
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0,0,0);
		glVertex3f(mundoX,0,0);
		glVertex3f(mundoX,mundoY,0);
		glVertex3f(0,mundoY,0);
	glEnd();
	
	glColor3f(0,1,0);
	escreveTexto(  GLUT_BITMAP_HELVETICA_18 , "VOCE DESEJA REINICIAR O JOGO?",50,400,0);
	escreveTexto(  GLUT_BITMAP_HELVETICA_12 , "Aperte 's' para reiniciar e 'n' se quiser continuar...",0,350,0);

}

int testeColisaoMosca(OBJETO ob1, OBJETO ob2){

	double distancia = sqrt((ob1.posicao.x+ob1.velocidade.x - ob2.posicao.x+ob2.velocidade.x)*(ob1.posicao.x+ob1.velocidade.x - ob2.posicao.x+ob2.velocidade.x) + (ob1.posicao.y+ob1.velocidade.y - ob2.posicao.y+ob2.velocidade.y)*(ob1.posicao.y+ob1.velocidade.y - ob2.posicao.y+ob2.velocidade.y));
	double raio1 = sqrt(pow((ob1.largura/2),2) + pow((ob1.altura/2),2));
	double raio2 = sqrt(pow((ob2.largura/2),2) + pow((ob2.altura/2),2));


	if(distancia <= (raio1 + raio2) ){
		return 0;
	}
	return 1;

}

