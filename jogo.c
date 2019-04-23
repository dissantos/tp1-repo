#include "jogo.h"
#include "sistema.h"
#include "tela.h"
#include <time.h>
#include <math.h>

//inicia os valores das posicoes dos objetos
void iniciarPosicoes(){
	if(tela == TELA_JOGO){
		mundoX = 400;
		mundoY = 800;
	}
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
	switch(faseAtual){
		case 0:
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
			
			break;
		case 1:
		    fundoJogo[2].posicao.x = mundoX/2;
			fundoJogo[2].posicao.y = mundoY/2;
			fundoJogo[2].velocidade.y = velocidadeJogo;
			fundoJogo[2].velocidade.x = 0;
			fundoJogo[2].largura = mundoX;
			fundoJogo[2].altura = mundoY;
			
			fundoJogo[3].posicao.x = mundoX/2;
			fundoJogo[3].posicao.y = mundoY+mundoY/2;
			fundoJogo[3].velocidade.y = velocidadeJogo;
			fundoJogo[3].velocidade.x = 0;
			fundoJogo[3].largura = mundoX;
			fundoJogo[3].altura = mundoY;
			
			break;
		case 2:
		    fundoJogo[4].posicao.x = mundoX/2;
			fundoJogo[4].posicao.y = mundoY/2;
			fundoJogo[4].velocidade.y = velocidadeJogo;
			fundoJogo[4].velocidade.x = 0;
			fundoJogo[4].largura = mundoX;
			fundoJogo[4].altura = mundoY;
			
			fundoJogo[5].posicao.x = mundoX/2;
			fundoJogo[5].posicao.y = mundoY+mundoY/2;
			fundoJogo[5].velocidade.y = velocidadeJogo;
			fundoJogo[5].velocidade.x = 0;
			fundoJogo[5].largura = mundoX;
			fundoJogo[5].altura = mundoY;
			
			break;			
	}

	//inicializa paralax
	switch(faseAtual){
		case 0:
			galho.posicao.y = mundoY;
			galho.posicao.x = 100;
			galho.altura = 160;
			galho.largura = 200;
			break;
		case 2:
			asteroide.posicao.y = mundoY;
			asteroide.posicao.x = rand()%401;
			asteroide.altura = 160;
			asteroide.largura = 160;
			
			asteroide2.posicao.y = mundoY+rand()%400;
			asteroide2.posicao.x = rand()%401;
			asteroide2.altura = 160;
			asteroide2.largura = 160;
			break;
	}
    
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
    
    //inicializa posicao do galho para efeito paralax
    posicaoGalho = 0;
}

void desenharFundo(){

	switch(faseAtual){
		case 0:
			desenhaObjeto(fundoJogo[0],FundoFase1Textura[0]);	
			desenhaObjeto(fundoJogo[1],FundoFase1Textura[0]);
			
			break;
		case 1:
			desenhaObjeto(fundoJogo[2],FundoFase2Textura[0]);	
			desenhaObjeto(fundoJogo[3],FundoFase2Textura[0]);
			
			break;
		case 2:
			desenhaObjeto(fundoJogo[4],FundoFase3Textura[0]);	
			desenhaObjeto(fundoJogo[5],FundoFase3Textura[0]);
			
			break;			
	}
}

void desenharParalax(){
	switch(faseAtual){
		case 0:
			desenhaObjeto(galho,GalhoTextura[posicaoGalho]);
			break;
		case 2:
			desenhaObjeto(asteroide,AsteroideTextura[0]);
			desenhaObjeto(asteroide2,AsteroideTextura[0]);
			break;
	}
}

void desenharLingua(){
    glColor3f(1,0.6,0.9);


    desenhaObjeto(lingua,BaseLinguaTextura[0]);
    desenhaObjeto(pontaLingua,PontaLinguaTextura[0]);


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
		    vel = rand()%200;
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
				desenhaObjeto(moscas[i],moscaTextura[indiceDoSpriteMosca]);
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
				desenhaObjeto(abelhas[i],abelhasTextura[indiceDoSpriteAbelha]);

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
		desenhaObjeto(fada,FadaTextura[indiceDoSpriteFada]);
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
			desenhaObjeto(vidaDisplay,VidaTextura[0]);
			break;
		case 2:
			desenhaObjeto(vidaDisplay,VidaTextura[1]);
			break;
		case 1:
			desenhaObjeto(vidaDisplay,VidaTextura[2]);
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
			desenhaObjeto(telaAtual, TelasExtrasTextura[0]);
    		break;
    	case TELA_VITORIA:
			desenhaObjeto(telaAtual, TelasExtrasTextura[1]);
    		break;
    	case TELA_DERROTA:
			desenhaObjeto(telaAtual, TelasExtrasTextura[2]);
    		break;
    	case TELA_PAUSE:
			desenhaObjeto(telaAtual, TelasExtrasTextura[3]);
    		break;
    	case TELA_ESC:
			desenhaObjeto(telaAtual, TelasExtrasTextura[4]);
    		break;
    	case TELA_REINICIAR:
			desenhaObjeto(telaAtual, TelasExtrasTextura[5]);
    		break;
	}
	
	escreveTexto(   GLUT_BITMAP_HELVETICA_18  , "SCORE:" , 150,200,0);
	char pontuacao[5];
	sprintf(pontuacao,"%d",score);
	
	escreveTexto(  GLUT_BITMAP_HELVETICA_18  , pontuacao, 250,200,0 );

}


int testeColisao(OBJETO *obj){
	double distancia, raio1,raio2;
	if(obj->vaiDesenhar == 1){
		distancia = sqrt(pow((pontaLingua.posicao.x - obj->posicao.x),2) + pow((pontaLingua.posicao.y - obj->posicao.y),2));
		raio1 = sqrt(pow((pontaLingua.largura/2),2) + pow((pontaLingua.altura/2),2));
		raio2 = sqrt(pow((obj->largura/2),2) + pow((obj->altura/2),2));
		if(distancia <= (raio1 + raio2) ){
			obj->vaiDesenhar = 0;
			return 1;
		}
	}
	
	return 0;
}

void iniciaProximaFase(){
	switch(faseAtual){
		case 0:
			qtdDeAbelhas = 2;
			qtdDeMoscas = 20;
			iniciarPosicoes();
			
			break;
		case 1:
			qtdDeAbelhas = 4;
			qtdDeMoscas = 20;
			iniciarPosicoes();
			
			break;
		case 2:
			qtdDeAbelhas = 6;
			qtdDeMoscas = 20;
			iniciarPosicoes();
			
			break;			
	}
}

void iniciaJogo(){
    mundoX = 400;
    mundoY = 800;

    desenharFundo();
    desenharParalax();
    desenharLingua();
    desenharMoscas();
    desenharAbelha();
    desenharFada();
    desenharDisplay();
    //desenhaQtdDeMoscas();
}

