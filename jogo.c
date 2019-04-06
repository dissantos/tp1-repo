#include "jogo.h"
#include "sistema.h"
#include "tela.h"
#include <time.h>


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
        vel = (double)vel/1000;
        if(rand() % 2 == 0)
            vel *= -1;
        moscas[i].velocidade.x+= vel;
        vel = rand()%100;
        vel = (double)vel/1000;
        if(rand() % 2 == 0)
            vel*= -1;
        moscas[i].velocidade.y += vel;
	}
	
	for(int i = 0; i < qtdDeMoscas ; i++)
		desenhaObjeto(moscas[i],"mosca1.png");
}

void iniciaPrimeiraFase(){
    mundoX = 400;
    mundoY = 800;
    

    desenharFundo();
    desenharLingua();
    desenharMoscas();
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

void movimentarLingua(char unsigned key){
	switch(key){
		case 'w':
			lingua.altura += 2;
			pontaLingua.velocidade.y += 2;
			break;
		case 's':
			lingua.altura -= 2;
			pontaLingua.velocidade.y -= 2;
			break;
		case 'a':
			lingua.velocidade.x -= 2;
			pontaLingua.velocidade.x -= 2;
			break;
		case 'd':
			lingua.velocidade.x += 2;
			pontaLingua.velocidade.x += 2;
			break;
		case 'p':
			tela = TELA_PAUSE;
			break;
		case 'r':
			tela = TELA_REINICIAR;
			break;
		case 27:
			tela = TELA_ESC;
			break;
	}
}
