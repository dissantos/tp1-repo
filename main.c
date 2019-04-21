#include "sistema.h"
#include "personagem.h"
#include "tela.h"
#include "menu.h"
#include "jogo.h"
#include <time.h>
#include <string.h>

OBJETO lingua;


void inicializa()
{
	tela = TELA_JOGO; //inicia no jogo
	faseAtual = 0;
	indiceDoSpriteMosca = 0;
	indiceDoSpriteAbelha = 0;
	indiceDoSpriteFada = 0;
	switch(tela){
		case TELA_MENU:
			mundoX = 800;
    		mundoY = 800;
    		break;
    	case TELA_JOGO:
    		mundoX = 400;
    		mundoY = 800;
	}
    
    
    score = 0;
    vida = 3;
	qtdDeMoscas = 10;
    qtdDeAbelhas = 2;
    iniciarPosicoes();
    
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
    	case TELA_JOGO:
    		iniciaJogo();
    		break;
    	default:
    		desenharTelaExtra();
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
   	case TELA_JOGO:
		testeColisaoMosca();
		
		//movimenta cenario
		fundoJogo[0].posicao.y -= velocidadeJogo;
		if(fundoJogo[0].posicao.y + fundoJogo[0].altura/2 <= 0){
			fundoJogo[0].posicao.y = mundoY + mundoY/2;
		}
		fundoJogo[1].posicao.y -= velocidadeJogo;
		if(fundoJogo[1].posicao.y + fundoJogo[1].altura/2 <= 0){
			fundoJogo[1].posicao.y = mundoY + mundoY/2;
		}
		//movimenta moscas
		for(int i = 0; i < qtdDeMoscas; i++)
			//if(moscas[i].vaiDesenhar == 1)
				moscas[i].posicao.y -= moscas[i].velocidade.y;
				
		//movimenta abelhas
		for(int i = 0; i < qtdDeAbelhas; i++)
			abelhas[i].posicao.y -= abelhas[i].velocidade.y;
			
		//movimenta fada
		fada.posicao.y -= fada.velocidade.y;
		
		//teclado
		if(teclas['w']||teclas['W']){
			if(pontaLingua.posicao.y + pontaLingua.velocidade.y + pontaLingua.altura/2 <= 800){
				lingua.altura += 2 * lingua.velocidade.y;
				pontaLingua.posicao.y += pontaLingua.velocidade.y;
			}
		}
		
		if(teclas['s']||teclas['S']){
			if(pontaLingua.posicao.y + pontaLingua.velocidade.y - pontaLingua.altura/2 >= 0){
				lingua.altura -= 2 * lingua.velocidade.y;
				pontaLingua.posicao.y -= pontaLingua.velocidade.y;
			}
		}
		
		if(teclas['a']||teclas['A']){
			lingua.posicao.x -= lingua.velocidade.x;
			pontaLingua.posicao.x -= pontaLingua.velocidade.x;
			if(pontaLingua.posicao.x + pontaLingua.velocidade.x + pontaLingua.largura/2 < 0){
				pontaLingua.posicao.x = 400;
				lingua.posicao.x = 400;
				pontaLingua.velocidade.x = 0;
				lingua.velocidade.x = 0;
			}
		}
		
		if(teclas['d']||teclas['D']){
			lingua.posicao.x += lingua.velocidade.x;
			pontaLingua.posicao.x += pontaLingua.velocidade.x;
			if(pontaLingua.posicao.x + pontaLingua.velocidade.x - pontaLingua.largura/2 > 400){
				pontaLingua.posicao.x = 0;
				pontaLingua.velocidade.x = 0;
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
		
		//teste para ver se pode passar para a proxima faseAtual
		for(int i = 0,cont = 0; i < qtdDeMoscas; i++){
			if(moscas[i].vaiDesenhar == 0)
				cont++;
			if(cont == qtdDeMoscas){
				tela = TELA_PROXIMAFASE;
				faseAtual++;
				if(faseAtual == 3)
					tela = TELA_VITORIA;
				iniciaProximaFase();
			}
		}
		//atualizar indice do sprite da moscas
		indiceDoSpriteMosca++;
		indiceDoSpriteAbelha++;
		indiceDoSpriteFada++;
		if(indiceDoSpriteMosca == 23)
			indiceDoSpriteMosca = 0;
		if(indiceDoSpriteAbelha == 6)
			indiceDoSpriteAbelha = 0;
		if(indiceDoSpriteFada == 3)
			indiceDoSpriteFada = 0;
			
		//indica tela de game over se o jogador perder todas as vidas
		if(vida <= 0)
			tela = TELA_DERROTA;
		
		break;
	case TELA_PROXIMAFASE:
		if(teclas['s']||teclas['S'])
			tela = TELA_JOGO;
		break;
	case TELA_VITORIA:
		if(teclas['s']||teclas['S'])
			exit(0);
	case TELA_DERROTA:
		if(teclas[27])
			exit(0);
		break;
	case TELA_PAUSE:
		if(teclas['s']||teclas['S']){
			tela = TELA_JOGO;
		}
		break;
	case TELA_REINICIAR:
		if(teclas['s']||teclas['S']){
			inicializa();
		}
		if(teclas['n']||teclas['N']){
			tela = TELA_JOGO;
		}
		break;
	case TELA_ESC:
		if(teclas['s']||teclas['S'])
			exit(0);
		if(teclas['n']||teclas['N'])
			tela = TELA_JOGO;
		break;
    }

    glutPostRedisplay();




    glutTimerFunc(17, atualiza, 0);
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

