#include "jogo.h"
#include "sistema.h"
#include "tela.h"
#include <time.h>
#include <math.h>

//inicia os valores das posicoes dos objetos
void iniciarPosicoes(){
//inicializa lingua
    lingua.posicao.x = 200;
    lingua.posicao.y = 0;
    lingua.velocidade.x = 4;
    lingua.velocidade.y = 4;
    lingua.largura = 50;
    lingua.altura = 50;
    pontaLingua.posicao.x = lingua.posicao.x - 3;
    pontaLingua.posicao.y = lingua.altura - 5;
    pontaLingua.velocidade.x = 4;
    pontaLingua.velocidade.y = 4;
    pontaLingua.altura = 50;
    pontaLingua.largura = 50;
    
    velocidadeJogo = 3;

//inicializa fundo do jogo
    fundoJogo[0].posicao.x = mundoX/2;
	fundoJogo[0].posicao.y = mundoY/2;
	fundoJogo[0].velocidade.y = velocidadeJogo;
	fundoJogo[0].velocidade.x = 0;
	fundoJogo[0].largura = mundoX;
	fundoJogo[0].altura = mundoY;
	
	fundoJogo[1].posicao.x = mundoX/2;
	fundoJogo[1].posicao.y = mundoY+mundoY/2;
	fundoJogo[1].velocidade.y = velocidadeJogo;
	fundoJogo[1].velocidade.x = 0;
	fundoJogo[1].largura = mundoX;
	fundoJogo[1].altura = mundoY;
    
    //inicia moscas
    moscas = malloc(sizeof(OBJETO) * qtdDeMoscas);
    for(int i = 0; i < qtdDeMoscas; i++){
		moscas[i].posicao.x = rand()%401;
		moscas[i].posicao.y = rand()%1001+150;
		moscas[i].velocidade.x = 0;
		moscas[i].velocidade.y = velocidadeJogo;
		moscas[i].largura = 20;
		moscas[i].altura = 20;
		moscas[i].vaiDesenhar = 1;
	}
    
    
    //inicia abelhas
    abelhas = malloc(sizeof(OBJETO) * qtdDeAbelhas);
    for(int i = 0; i < qtdDeAbelhas; i++){
    	abelhas[i].posicao.y = rand()%1001+150;
		abelhas[i].velocidade.x = 0;
		abelhas[i].velocidade.y = velocidadeJogo;
		abelhas[i].largura = 20;
		abelhas[i].altura = 20;
		abelhas[i].vaiDesenhar = 1;
    }
    
    //inicia fada
    fada.posicao.y = rand()%1000+700;
    fada.velocidade.x = 0;
    fada.velocidade.y = velocidadeJogo;
    fada.largura = 20;
    fada.altura = 15;
    fada.vaiDesenhar = 1;
}

void desenharFundo(){
	desenhaObjeto(fundoJogo[0],"fundoJogo1.png");
	
	desenhaObjeto(fundoJogo[1],"fundoJogo1.png");
	

}

void desenharLingua(){
    glColor3f(1,0.6,0.9);


    desenhaObjeto(lingua,"baseLingua.png");
    desenhaObjeto(pontaLingua,"pontaLingua.png");


    glEnd();
}

void desenharMoscas(){
	double vel;
	char spriteMosca[][23] = {"mosca (0).png","mosca (1).png","mosca (2).png","mosca (3).png","mosca (4).png","mosca (5).png",
							  "mosca (6).png","mosca (7).png","mosca (8).png","mosca (9).png","mosca (10).png","mosca (11).png",
							  "mosca (12).png","mosca (13).png","mosca (14).png","mosca (15).png","mosca (16).png","mosca (17).png",
							  "mosca (18).png","mosca (19).png","mosca (20).png","mosca (21).png","mosca (22).png"};

    srand(time(NULL));
    for(int i  = 0; i < qtdDeMoscas; i++){
    	if(moscas[i].vaiDesenhar == 1){	
		    vel = rand()%100;
		    if(rand() % 2 == 0)
		        vel *= -1;
		    vel = (double)vel/100;
		    
		    moscas[i].posicao.x+= vel;
		    //moscas[i].posicao.y -= 2;
		    if(moscas[i].posicao.y + moscas[i].velocidade.y<= 0 || moscas[i].posicao.x + moscas[i].velocidade.x <= 0 || moscas[i].posicao.x + moscas[i].velocidade.x >= 400){
		    	moscas[i].posicao.y = 800;
		    	moscas[i].posicao.x = rand()%401;
		    	//moscas[i].velocidade.x = 0;
		    	//moscas[i].velocidade.y = 0;
		    }
			// corrigir essa parte 
				desenhaObjeto(moscas[i],spriteMosca[indiceDoSpriteMosca]);
				//printf("x: %lf\ny :%lf\n",moscas[i].posicao.x, moscas[i].posicao.y);
		}
	}
}

void desenharAbelha(){
	double velocidade;
	char spriteAbelhas[][6] = {"1.png","2.png","3.png","4.png","5.png","6.png"};

    srand(time(NULL));
    for(int i  = 0; i < qtdDeAbelhas; i++){
    	if(abelhas[i].vaiDesenhar == 1){	
		    velocidade = rand()%100;
		    if(rand() % 2 == 0)
		        velocidade *= -1;
		    velocidade = (double)velocidade/100;
		    
		    abelhas[i].posicao.x+= velocidade;

		    if(abelhas[i].posicao.y + abelhas[i].velocidade.y<= 0 || abelhas[i].posicao.x + abelhas[i].velocidade.x <= 0 || abelhas[i].posicao.x + abelhas[i].velocidade.x >= 400){
		    	abelhas[i].posicao.y = 800;
		    	abelhas[i].posicao.x = rand()%401;
		    	
		    }
				desenhaObjeto(abelhas[i],spriteAbelhas[indiceDoSpriteAbelha]);

		}
	}
}

void desenharFada(){
	double velocidade;
	char spriteFada[][20] = {"fada(1).png","fada(2).png","fada(3).png"};
	srand(time(NULL));
	if(fada.vaiDesenhar){
		velocidade = rand()%100;
		if(rand()%2 == 0)
			velocidade *= -1;
		velocidade = (double)velocidade/100;
		fada.posicao.x += velocidade;
		if(fada.posicao.y + fada.velocidade.y<= 0 || fada.posicao.x + fada.velocidade.x <= 0 || fada.posicao.x + fada.velocidade.x >= 400){
			fada.posicao.y = rand()%500 + 800;
			fada.posicao.x = rand()%401;
		}
		desenhaObjeto(fada,spriteFada[indiceDoSpriteFada]);
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


void desenharTelaExtra(){
	OBJETO telaAtual;
	telaAtual.posicao.x = mundoX/2;
	telaAtual.posicao.y = mundoY/2;
	telaAtual.velocidade.x = 0;
	telaAtual.velocidade.y = 0;
	telaAtual.altura = mundoY;
	telaAtual.largura = mundoX;
	
	switch(tela){
		case TELA_PROXIMAFASE:
			desenhaObjeto(telaAtual, "telaProximaFase.png");
    		break;
    	case TELA_VITORIA:
			desenhaObjeto(telaAtual, "telaVitoria.png");
    		break;
    	case TELA_DERROTA:
			desenhaObjeto(telaAtual, "telaFimDeJogo.png");
    		break;
    	case TELA_PAUSE:
			desenhaObjeto(telaAtual, "telaPause.png");
    		break;
    	case TELA_ESC:
			desenhaObjeto(telaAtual, "telaESC.png");
    		break;
    	case TELA_REINICIAR:
			desenhaObjeto(telaAtual, "telaReinicio.png");
    		break;
	}
	
	escreveTexto(   GLUT_BITMAP_HELVETICA_18  , "SCORE:" , 150,200,0);
	char pontuacao[5];
	sprintf(pontuacao,"%d",score);
	
	escreveTexto(  GLUT_BITMAP_HELVETICA_18  , pontuacao, 250,200,0 );

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
	for(int i = 0; i < qtdDeAbelhas; i++){
		if(abelhas[i].vaiDesenhar == 1){
			distancia = sqrt(pow((pontaLingua.posicao.x + pontaLingua.velocidade.x - abelhas[i].posicao.x + abelhas[i].velocidade.x),2) + 									pow((pontaLingua.posicao.y + pontaLingua.velocidade.y - abelhas[i].posicao.y + abelhas[i].velocidade.y),2));
			raio1 = sqrt(pow((pontaLingua.largura/2),2) + pow((pontaLingua.altura/2),2));
			raio2 = sqrt(pow((abelhas[i].largura/2),2) + pow((abelhas[i].altura/2),2));
			if(distancia <= (raio1 + raio2) ){
				abelhas[i].vaiDesenhar = 0;
				vida--;
				score -=  15;
			}
		}
	}
	
	if(fada.vaiDesenhar == 1){
			distancia = sqrt(pow((pontaLingua.posicao.x + pontaLingua.velocidade.x - fada.posicao.x + fada.velocidade.x),2) + 									pow((pontaLingua.posicao.y + pontaLingua.velocidade.y - fada.posicao.y + fada.velocidade.y),2));
			raio1 = sqrt(pow((pontaLingua.largura/2),2) + pow((pontaLingua.altura/2),2));
			raio2 = sqrt(pow((fada.largura/2),2) + pow((fada.altura/2),2));
			if(distancia <= (raio1 + raio2) ){
				fada.vaiDesenhar = 0;
				vida = 3;
				score +=  50;
			}
	}
}



void iniciaProximaFase(){
	switch(faseAtual){
		case 0:
			qtdDeAbelhas = 2;
			qtdDeMoscas = 10;
			iniciarPosicoes();
			
			break;
		case 1:
			qtdDeAbelhas = 4;
			qtdDeMoscas = 8;
			iniciarPosicoes();
			
			break;
		case 2:
			qtdDeAbelhas = 6;
			qtdDeMoscas = 6;
			iniciarPosicoes();
			
			break;
    
			
	}
}

void iniciaJogo(){
    mundoX = 400;
    mundoY = 800;
    

    desenharFundo();
    desenharLingua();
    desenharMoscas();
    desenharAbelha();
    desenharFada();
    desenharDisplay();
    //desenhaQtdDeMoscas();
}


