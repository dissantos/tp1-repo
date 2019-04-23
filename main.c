#include "sistema.h"
#include "personagem.h"
#include "tela.h"
#include "menu.h"
#include "jogo.h"
#include <time.h>
#include <string.h>

OBJETO lingua;

void inicializa(){
	tela = TELA_MENU; //inicia no jogo
	faseAtual = 0;
	
	if(tela == TELA_MENU)
		iniciarMusica("Eu to tranquilão - Mc Sapão.ogg",-1);

	//Inicializa os indices dos sprites
	indiceDoSpriteMosca = 0;
	indiceDoSpriteAbelha = 0;
	indiceDoSpriteFada = 0;

	//Checagem do tamanho da tela
	switch(tela){
		case TELA_MENU:
		mundoX = 1200;
    		mundoY = 800;
    		break;
    	case TELA_JOGO:
    		mundoX = 400;
    		mundoY = 800;
	}
    
    
    score = 0;
    vida = 3;

	//num de moscas e abelhas
	qtdDeMoscas = 10;
    qtdDeAbelhas = 2;
	char spriteMosca[][23] = {"mosca (0).png","mosca (1).png","mosca (2).png","mosca (3).png","mosca (4).png","mosca (5).png",
							  "mosca (6).png","mosca (7).png","mosca (8).png","mosca (9).png","mosca (10).png","mosca (11).png",
							  "mosca (12).png","mosca (13).png","mosca (14).png","mosca (15).png","mosca (16).png","mosca (17).png",
							  "mosca (18).png","mosca (19).png","mosca (20).png","mosca (21).png","mosca (22).png"};
	char spriteAbelhas[][6] = {"1.png","2.png","3.png","4.png","5.png","6.png"};
	char spriteFada[][20] = {"fada(1).png","fada(2).png","fada(3).png"};
	char FundoFase1[] = "fundoJogo1.png";
	char BaseLingua[] = "baseLingua.png";
    char PontaLingua[] = "pontaLingua.png";
    char Vidas[][15] = {"3vidas.png","2vidas.png","1vida.png"};
	char TelasExtras[][30] = {"telaProximaFase.png", "telaVitoria.png", "telaFimDeJogo.png","telaPause.png","telaESC.png", "telaReinicio.png"};
	char FundoFase2[] = "snow.png";
	char FundoFase3[] = "boss.png";
	char Galho[][20] = {"galhoEsquerda.png","galhoDireita.png"};

    char MenuLindo[] = "OPEN2.png";
    char CreditosLindo[]= "Creditos.png";
    char AjudaLindo[] = "ajuda.png";
    char HistoryLindo[] = "history.png";
	char LogoLindo[] = "logo.png";
	char BotaoVoltarMenu[] = "BotaoSair.png";
	char BotaoAjudaMenu[] = "BotaoAjuda.png";
	char BotaoCreditosMenu[] = "BotaoCreditos.png";
	char BotaoJogarMenu[] = "BotaoJogar.png";
	char BotaoRankingMenu[] = "BotaoRanking.png";
	char BotaoVoltarCreditos[] = "BotaoVoltar.png";
	char BotaoVoltarAjuda[] = "BotaoVoltar.png";
	char BotaoVoltarHistory[] = "BotaoVoltar.png";
	char BotaoJogarHistory[] = "BotaoJogar.png";

	//Carrega as texturas das moscas
	for(int i = 0; i < 23; i++){
		moscaTextura[i] = carregaTextura(spriteMosca[i]);
	}

	//Carrega as texturas das abelhas
	for(int i = 0; i < 6; i++){
		abelhasTextura[i] = carregaTextura(spriteAbelhas[i]);
	}

	//Carrega as texturas da fada
	for(int i = 0; i < 3; i++){
		FadaTextura[i] = carregaTextura(spriteFada[i]);
	}

	//Carrega as textura do fundo
	FundoFase1Textura[0] = carregaTextura(FundoFase1);

	//carrega as texturas da lingua
	BaseLinguaTextura[0] = carregaTextura(BaseLingua);
	PontaLinguaTextura[0] = carregaTextura(PontaLingua);

	//carrega as texturas da vida
	for(int i = 0; i < 3; i++){
		VidaTextura[i] = carregaTextura(Vidas[i]);
	}

	//carrega as texturas das telas extras
	for(int i = 0; i < 6; i++){
		TelasExtrasTextura[i] = carregaTextura(TelasExtras[i]);
	}
	
	//Carrega as textura do fundo das outras fases
	FundoFase2Textura[0] = carregaTextura(FundoFase2);
	FundoFase3Textura[0] = carregaTextura(FundoFase3);

	//**************************************************
    //Carrega a textura do menu
	MenuTextura[0] = carregaTextura(MenuLindo);
	BotaoVoltarMenuTextura[0] = carregaTextura(BotaoVoltarMenu);
	BotaoAjudaTextura[0] = carregaTextura(BotaoAjudaMenu);
	BotaoCreditosTextura[0] = carregaTextura(BotaoCreditosMenu);
	BotaoJogarMenuTextura[0] = carregaTextura(BotaoJogarMenu);
	BotaoRankingMenuTextura[0] = carregaTextura(BotaoRankingMenu);

	//carrega a textura dos Creditos
	CreditosTextura[0] = carregaTextura(CreditosLindo);
	BotaoVoltarCreditosTextura[0] = carregaTextura(BotaoVoltarCreditos);

    //Carrega a textura da Ajuda
	AjudaTextura[0] = carregaTextura(AjudaLindo);
	BotaoVoltarAjudaTextura[0] = carregaTextura(BotaoVoltarAjuda);

    //Carrega a textura da historia
	HistoryTextura[0] = carregaTextura(HistoryLindo);
	BotaoVoltarHistoryTextura[0] = carregaTextura(BotaoVoltarHistory);
	BotaoJogarHistoryTextura[0] = carregaTextura(BotaoJogarHistory);

	//Carrega a textura da logo
	LogoTextura[0] = carregaTextura(LogoLindo);
	
	//carrega textura do paralax da fase 1
	for(int i = 0; i < 2; i++){
		GalhoTextura[i] = carregaTextura(Galho[i]);
	}
	
	//carrega textura do paralax da fase 3
	AsteroideTextura[0] = carregaTextura("asteroid-icon.png");
	
	//**************************************************

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
    	case TELA_AJUDA:
    		desenharAjuda();
    		break;
    	case TELA_HISTORIA:
    		desenharHistoria();
    		break;
    	case TELA_CREDITO:
    		desenharCredito();
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

/*
void redimensiona(int w, int h)
{

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,mundoX,0,mundoY,-1,1);
    glMatrixMode(GL_MODELVIEW);

}*/

void redimensiona(int width, int height) {
	larguraJanela = width;
	alturaJanela = height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, mundoX, 0, mundoY, -1, 1);

    float razaoAspectoJanela = ((float)width)/height;
    float razaoAspectoMundo = ((float) mundoX)/ mundoY;
    // se a janela está menos larga do que o mundo (16:9)...
    if (razaoAspectoJanela < razaoAspectoMundo) {
        // vamos colocar barras verticais (acima e abaixo)
        float hViewport = width / razaoAspectoMundo;
        float yViewport = (height - hViewport)/2;
        glViewport(0, yViewport, width, hViewport);
    }
    // se a janela está mais larga (achatada) do que o mundo (16:9)...
    else if (razaoAspectoJanela > razaoAspectoMundo) {
        // vamos colocar barras horizontais (esquerda e direita)
        float wViewport = ((float)height) * razaoAspectoMundo;
        float xViewport = (width - wViewport)/2;
        glViewport(xViewport, 0, wViewport, height);
    } else {
        glViewport(0, 0, width, height);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y){
	teclas[key] = 1;
}

void teclaLiberada(unsigned char key, int x, int y){
	teclas[key] = 0;
	// se personagem solta a tecla mudar vetor teclas para 0
}


void mouseClicado(int button, int state, int x, int y){
	if(delay >= 90){
    	identificarBotao(x,y);
    }
}


void atualiza(){
	//fazer mudancas com as teclas aqui
    switch(tela){
   	case TELA_MENU:
   		delay++;

   		break;
   	case TELA_JOGO:
		//teste de colisoes das moscas
		for(int i = 0 ; i < qtdDeMoscas ;  i++){
			if(testeColisao(&moscas[i])){
				iniciarMusica("Yoshis Island tongue sound effect.ogg",0);
				score+=10;
			}
		}
		//teste de colisoes das abelhas
		for(int i = 0; i < qtdDeAbelhas; i++){
			if(testeColisao(&abelhas[i])){
				iniciarMusica("Undertale Sound Effect - Attack.ogg",0);
				score-= 15;
				vida--;
			}
		}
		//testa colisao com a fada
		if(testeColisao(&fada)){
			iniciarMusica("TP_Fairy.wav",0);
			vida = 3;
			score += 50;
		}
		
		
		//movimenta cenario de acordo com a fase

		switch(faseAtual){
			case 0:
				fundoJogo[0].posicao.y -= velocidadeJogo/3;
				if(fundoJogo[0].posicao.y + fundoJogo[0].altura/2 <= 0){
					fundoJogo[0].posicao.y = mundoY + mundoY/2;
				}
				fundoJogo[1].posicao.y -= velocidadeJogo/3;
				if(fundoJogo[1].posicao.y + fundoJogo[1].altura/2 <= 0){
					fundoJogo[1].posicao.y = mundoY + mundoY/2;
				}
				break;
			case 1:
				fundoJogo[2].posicao.y -= velocidadeJogo;
				if(fundoJogo[2].posicao.y + fundoJogo[2].altura/2 <= 0){
					fundoJogo[2].posicao.y = mundoY + mundoY/2;
				}
				fundoJogo[3].posicao.y -= velocidadeJogo;
				if(fundoJogo[3].posicao.y + fundoJogo[3].altura/2 <= 0){
					fundoJogo[3].posicao.y = mundoY + mundoY/2;
				}
				
				break;
			case 2:
				fundoJogo[4].posicao.y -= velocidadeJogo/3;
				if(fundoJogo[4].posicao.y + fundoJogo[4].altura/2 <= 0){
					fundoJogo[4].posicao.y = mundoY + mundoY/2;
				}
				fundoJogo[5].posicao.y -= velocidadeJogo/3;
				if(fundoJogo[5].posicao.y + fundoJogo[5].altura/2 <= 0){
					fundoJogo[5].posicao.y = mundoY + mundoY/2;
				}
				
			break;			
		}
		
		//movimenta paralax
		switch(faseAtual){
			case 0:
				galho.posicao.y -= velocidadeJogo;
				if(galho.posicao.y <= 0){
					posicaoGalho = rand()%2;
					if(posicaoGalho == 0)
						galho.posicao.x = 100;
					else
						galho.posicao.x = 300;
					galho.posicao.y = 710;
				}
				break;
			case 2:
				asteroide.posicao.y -= velocidadeJogo;
				asteroide2.posicao.y -= velocidadeJogo;
				if(asteroide.posicao.y + asteroide.altura/2 <= 0){
					asteroide.posicao.y = mundoY;
					asteroide.posicao.x = rand()%401;
				}
				if(asteroide2.posicao.y + asteroide2.altura/2 <= 0){
					asteroide2.posicao.y = mundoY+rand()%300;
					asteroide2.posicao.x = rand()%401;
				}
		}

		//movimenta moscas
		for(int i = 0; i < qtdDeMoscas; i++){
			if(moscas[i].vaiDesenhar == 1)
				moscas[i].posicao.y -= velocidadeJogo;
		}

		//movimenta abelhas
		for(int i = 0; i < qtdDeAbelhas; i++)
			abelhas[i].posicao.y -= velocidadeJogo;
			
		//movimenta fada
		fada.posicao.y -= fada.velocidade.y;
		
		//teclado
		if(teclas['w']||teclas['W']){ 	//pra subir e descer a lingua
			if(pontaLingua.posicao.y + pontaLingua.velocidade.y + pontaLingua.altura/2 <= 800){
				lingua.altura += 2 * lingua.velocidade.y;
				pontaLingua.posicao.y += pontaLingua.velocidade.y;
			}
		}
		
		if(teclas['s']||teclas['S']){ //Pra descer a lingua ate zero
			if(pontaLingua.posicao.y + pontaLingua.velocidade.y - pontaLingua.altura/2 >= 0){
				lingua.altura -= 2 * lingua.velocidade.y;
				pontaLingua.posicao.y -= pontaLingua.velocidade.y;
			}
		}
		
		if(teclas['a']||teclas['A']){	//movimentacao lateral da lingua
			lingua.posicao.x -= lingua.velocidade.x;
			pontaLingua.posicao.x -= pontaLingua.velocidade.x;
			if(pontaLingua.posicao.x /*+ pontaLingua.velocidade.x + pontaLingua.largura/2 */<= 0){
				pontaLingua.posicao.x = 400;
				lingua.posicao.x = 400;
				//pontaLingua.velocidade.x = 0;
				//lingua.velocidade.x = 0;
			}
		}
		
		if(teclas['d']||teclas['D']){	//movimentacao lateral da lingua
			lingua.posicao.x += lingua.velocidade.x;
			pontaLingua.posicao.x += pontaLingua.velocidade.x;
			if(pontaLingua.posicao.x /*+ pontaLingua.velocidade.x - pontaLingua.largura/2*/ >= 400){
				pontaLingua.posicao.x = 0;
				lingua.posicao.x = 0;
				//pontaLingua.velocidade.x = 0;
			}
		}
		if(teclas['p']||teclas['P']){
			iniciarMusica("Elevator_Music-jj0ChLVTpaA.ogg",-1);
			tela = TELA_PAUSE;
		}
		if(teclas['r'] || teclas['R']){
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
				if(faseAtual < 3)
					iniciarMusica("Feeling Happy Sound Effect.ogg",-1);
				if(faseAtual == 3){
					iniciarMusica("QUEEN_-_We_Are_The_Champions_HQ-aRlk72bQK90.ogg",-1);
					tela = TELA_VITORIA;
				}
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
		if(vida <= 0){
			iniciarMusica("Only_Piano_-_Loneliness-vohFxJ982Ic.ogg",-1);
			tela = TELA_DERROTA;
			}
		
		break;

	case TELA_PROXIMAFASE:
		if(teclas['s']||teclas['S']){
			pararMusica();
			tela = TELA_JOGO;
		}
		break;
	case TELA_VITORIA:
		if(teclas[27]){
			tela = TELA_MENU;
			pararMusica();
			iniciarMusica("Eu to tranquilão - Mc Sapão.ogg",-1);
		}
		break;
	case TELA_DERROTA:
		if(teclas[27]){
			tela = TELA_MENU;
			pararMusica();
			iniciarMusica("Eu to tranquilão - Mc Sapão.ogg",-1);
		}
		break;
	case TELA_PAUSE:
		if(teclas['s']||teclas['S']){
			pararMusica();
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

    glutTimerFunc(33, atualiza, 0);
}

int main(int argc, char** argv){
	
	larguraJanela = 1200;
	alturaJanela = 800;
	//para iniciar a logo colocamos um delay para auxiliar 
	delay = 0;

    glutInit(&argc, argv);
    

    
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Pescaria");

    inicializa();

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaLiberada);
    glutMouseFunc(mouseClicado);
    glutDisplayFunc(desenha);
    //glutIdleFunc(atualiza);



    glutTimerFunc(0, atualiza, 0);

    glutMainLoop();

    return 0;
}


