#include "sistema.h"
#include "personagem.h"
#include "tela.h"
#include "menu.h"
#include "jogo.h"
#include <time.h>

OBJETO lingua;


void inicializa()
{
	tela = TELA_JOGO_1; //inicia no jogo
	faseAtual = 0;
	switch(tela){
		case TELA_MENU:
			mundoX = 800;
    		mundoY = 800;
    		break;
    	case TELA_JOGO_1:
    		mundoX = 400;
    		mundoY = 800;
	}
    //inicializa fundo do jogo
    fundoJogo[0].posicao.x = mundoX/2;
	fundoJogo[0].posicao.y = mundoY/2;
	fundoJogo[0].velocidade.y = 0;
	fundoJogo[0].velocidade.x = 0;
	fundoJogo[0].largura = mundoX;
	fundoJogo[0].altura = mundoY;
	
	fundoJogo[1].posicao.x = mundoX/2;
	fundoJogo[1].posicao.y = mundoY+mundoY/2;
	fundoJogo[1].velocidade.y = 0;
	fundoJogo[1].velocidade.x = 0;
	fundoJogo[1].largura = mundoX;
	fundoJogo[1].altura = mundoY;
    
    
    score = 0;
    vida = 3;
    //inicializa lingua
    lingua.posicao.x = 200;
    lingua.posicao.y = 0;
    lingua.velocidade.x = 0;
    lingua.velocidade.y = 0;
    lingua.largura = 50;
    lingua.altura = 50;
    pontaLingua.posicao.x = lingua.posicao.x - 3;
    pontaLingua.posicao.y = lingua.altura - 5;
    pontaLingua.velocidade.x = 0;
    pontaLingua.velocidade.y = 0;
    pontaLingua.altura = 50;
    pontaLingua.largura = 50;
    
    //inicia moscas Fase 1
    qtdDeMoscas = 20;

    moscas = malloc(sizeof(OBJETO) * qtdDeMoscas);
    for(int i = 0; i < qtdDeMoscas; i++){
		moscas[i].posicao.x = rand()%401;
		moscas[i].posicao.y = rand()%1001+150;
		moscas[i].velocidade.x = 0;
		moscas[i].velocidade.y = 0;
		moscas[i].largura = 20;
		moscas[i].altura = 20;
		moscas[i].vaiDesenhar = 1;
	}
    
    glClearColor(1, 1, 1, 1);
    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}



void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    
    switch(tela){
    	case TELA_MENU:
    		iniciaMenu(0,0);
    		break;
    	case TELA_JOGO_1:
    		iniciaPrimeiraFase();
    		break;
    	case TELA_PAUSE:
    		desenharPause();
    		break;
    	case TELA_ESC:
    		desenharESC();
    		break;
    	case TELA_REINICIAR:
    		desenharReinicio();
    		break;
    	
    }

    glutSwapBuffers();
}

void redimensiona(int w, int h)
{

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,mundoX,0,mundoY,-1,1);
    glMatrixMode(GL_MODELVIEW);

}

void teclaPressionada(unsigned char key, int x, int y)
{
	teclas[key] = 1;
}

void teclaLiberada(unsigned char key, int x, int y){
	teclas[key] = 0;
	// se personagem solta a tecla mudar vetor teclas para 0
}


void mouseClicado(int button, int state, int x, int y){
	if(tela == TELA_MENU)
    	tela = identificarBotao(x,y);
}


void atualiza()
{

	//fazer mudancas com as teclas aqui
    switch(tela){
   	case TELA_MENU:

   		break;
   	case TELA_JOGO_1:
		testeColisaoMosca();
		
		//movimenta cenario
		/*
		fundoJogo[0].posicao.y -= 0.06;
		if(fundoJogo[0].posicao.y + fundoJogo[0].altura/2 <= 0){
			fundoJogo[0].posicao.y = mundoY + mundoY/2;
		}
		fundoJogo[1].posicao.y -= 0.06;
		if(fundoJogo[1].posicao.y + fundoJogo[1].altura/2 <= 0){
			fundoJogo[1].posicao.y = mundoY + mundoY/2;
		}
		*/
		//movimenta moscas
		for(int i = 0; i < qtdDeMoscas; i++)
			if(moscas[i].vaiDesenhar == 1)
				moscas[i].posicao.y -= 0.06;
		
		//teclado
		if(teclas['w']||teclas['W']){
			if(pontaLingua.posicao.y + pontaLingua.velocidade.y + pontaLingua.altura/2 <= 800){
				lingua.altura += 0.02;
				pontaLingua.velocidade.y += 0.01;
			}
		}
		
		if(teclas['s']||teclas['S']){
			if(pontaLingua.posicao.y + pontaLingua.velocidade.y - pontaLingua.altura/2 >= 0){
				lingua.altura -= 0.02;
				pontaLingua.velocidade.y -= 0.01;
			}
		}
		
		if(teclas['a']||teclas['A']){
			lingua.velocidade.x -= 0.01;
			pontaLingua.velocidade.x -= 0.01;
			if(pontaLingua.posicao.x + pontaLingua.velocidade.x + pontaLingua.largura/2 < 0){
				pontaLingua.posicao.x = 400;
				lingua.posicao.x = 400;
				pontaLingua.velocidade.x = 0;
				lingua.velocidade.x = 0;
			}
		}
		
		if(teclas['d']||teclas['D']){
			lingua.velocidade.x += 0.01;
			pontaLingua.velocidade.x += 0.01;
			if(pontaLingua.posicao.x + pontaLingua.velocidade.x - pontaLingua.largura/2 > 400){
				pontaLingua.posicao.x = 0;
				lingua.posicao.x = 0;
				pontaLingua.velocidade.x = 0;
				lingua.velocidade.x = 0;
			}
		}
		if(teclas['p']||teclas['P']){
			tela = TELA_PAUSE;
		}
		if(teclas['r']){
			tela = TELA_REINICIAR;
		}
		if(teclas[27]){
			tela = TELA_ESC;
		}
		break;
	case TELA_PAUSE:
		if(teclas['s']||teclas['S']){
			tela = TELA_JOGO_1;
		}
		break;
	case TELA_REINICIAR:
		if(teclas['s']||teclas['S']){
			score = 0;
			vida = 3;
    	    lingua.posicao.x = 200;
			lingua.posicao.y = 0;
			lingua.velocidade.x = 0;
			lingua.velocidade.y = 0;
			lingua.largura = 50;
			lingua.altura = 50;
			pontaLingua.posicao.x = lingua.posicao.x - 3;
			pontaLingua.posicao.y = lingua.altura - 5;
			pontaLingua.velocidade.x = 0;
			pontaLingua.velocidade.y = 0;
			pontaLingua.altura = 50;
			pontaLingua.largura = 50;
			for(int i = 0; i < qtdDeMoscas; i++){
				moscas[i].posicao.x = rand()%401;
				moscas[i].posicao.y = rand()%601+150;
				moscas[i].velocidade.x = 0;
				moscas[i].velocidade.y = 0;
				moscas[i].largura = 20;
				moscas[i].altura = 20;
				moscas[i].vaiDesenhar = 1;
			}
			tela = TELA_JOGO_1;
		}
		if(teclas['n']||teclas['N']){
			tela = TELA_JOGO_1;
		}
		break;
	case TELA_ESC:
		if(teclas['s']||teclas['S'])
			exit(0);
		if(teclas['n']||teclas['N'])
			tela = TELA_JOGO_1;
		break;
    }

    glutPostRedisplay();




    glutTimerFunc(33, atualiza, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    

    
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(400, 800);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Pescaria");

    inicializa();

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaLiberada);
    glutMouseFunc(mouseClicado);
    glutDisplayFunc(desenha);
    glutIdleFunc(atualiza);



    glutTimerFunc(0, atualiza, 0);

    glutMainLoop();

    return 0;
}

