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
    
    score = 0;
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
    qtdDeMoscas = 10;

    moscas = malloc(sizeof(OBJETO) * qtdDeMoscas);
    for(int i = 0; i < qtdDeMoscas; i++){
		moscas[i].posicao.x = rand()%401;
		moscas[i].posicao.y = rand()%601+150;
		moscas[i].velocidade.x = 0;
		moscas[i].velocidade.y = 0;
		moscas[i].largura = 20;
		moscas[i].altura = 20;
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

void teclado(unsigned char key, int x, int y)
{
    if(tela >= TELA_JOGO_1 && tela <= TELA_JOGO_4)
        movimentarLingua(key);
    if(tela == TELA_ESC){
    	switch(key){
    		case 's':
    			exit(0);
    		case 'n':
    			tela = TELA_JOGO_1;
    			break;
    	}
    }
    if(tela == TELA_PAUSE){
    	switch(key){
    		case 's' :
    		tela = TELA_JOGO_1;
    		break;
    	}
    }
    if(tela == TELA_REINICIAR){
    	switch(key){
    		case 's' :
    			//reinicia todas as variaveis	
    			score = 0;
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
				}
				tela = TELA_JOGO_1;
				break;
			case 'n' :
				tela = TELA_JOGO_1;
				break;	
    	}
    }


}


void mouseClicado(int button, int state, int x, int y){
	if(tela == TELA_MENU)
    	tela = identificarBotao(x,y);
}


void atualiza()
{


    switch(tela){
   	case TELA_MENU:

   		break;
   	case TELA_JOGO_1:
		for(int i = 0; i < qtdDeMoscas; i++)
			testeColisaoMosca(pontaLingua,moscas[i]);
		glutPostRedisplay();
   		break;
    }

    glutPostRedisplay();




    glutTimerFunc(25, atualiza, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 800);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Pescaria");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouseClicado);
    glutDisplayFunc(desenha);
    glutIdleFunc(atualiza);

    inicializa();

    glutTimerFunc(0, atualiza, 0);

    glutMainLoop();

    return 0;
}

