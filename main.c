#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include "sistema.h"
#include "personagem.h"
#include <time.h>

OBJETO lingua;

OBJETO *moscas;

int spriteMoscaAtual = 0;

GLuint idPersonagem = 0;

char spriteMosca[]= {"mario.png"};

int quantidadeDeMoscas = 10;


double alturaLinguaBaixo = -10,alturaLinguaCima = 10,larguraLingua = 4,larguraPontaLingua = 5,alturaPontaLingua = 5;
double mundoEsquerda= 0, mundoDireita=100, mundoBaixo=-100,mundoCima=100, mundoProximo=-100,mundoLonge=100;

void inicializa()
{
    lingua.posicao.x = 50;
    lingua.posicao.y = -90;
    srand(time(NULL));
    moscas = malloc(sizeof(OBJETO)*10);
    for(int i = 0; i < 10; i++){
        moscas[i].posicao.x = rand()%100;
        moscas[i].posicao.y = rand()%200 -100;
        moscas[i].velocidade.x = 0;
        moscas[i].velocidade.y = 0;
    }

    idPersonagem = carregaTextura("mosca1.png");



    glClearColor(1, 1, 1, 1);

        glColor3f(1,0,0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10,"Teste",0,-100,0);

    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}


void desenhaCenarioFundo(){
    glColor3f(0,0.8,1);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(mundoEsquerda,mundoBaixo,0);
        glVertex3f(mundoDireita,mundoBaixo,0);
        glVertex3f(mundoDireita,mundoCima,0);
        glVertex3f(mundoEsquerda,mundoCima,0);
    glEnd();
}

void desenhaJogador(){


    glColor3f(1,0.6,0.9);


    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(lingua.posicao.x - larguraLingua,lingua.posicao.y + alturaLinguaBaixo,0);
        glVertex3f(lingua.posicao.x + larguraLingua,lingua.posicao.y + alturaLinguaBaixo,0);
        glVertex3f(lingua.posicao.x + larguraLingua,lingua.posicao.y + alturaLinguaCima,0);
        glVertex3f(lingua.posicao.x - larguraLingua,lingua.posicao.y + alturaLinguaCima,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(lingua.posicao.x - larguraPontaLingua, lingua.posicao.y - alturaPontaLingua,0);
        glVertex3f(lingua.posicao.x + larguraPontaLingua, lingua.posicao.y - alturaPontaLingua,0);
        glVertex3f(lingua.posicao.x + larguraPontaLingua, lingua.posicao.y + alturaLinguaCima,0);
        glVertex3f(lingua.posicao.x - larguraPontaLingua, lingua.posicao.y + alturaLinguaCima,0);


    glEnd();
    //glDisable(GL_TEXTURE_2D);

}

void desenhaMoscas(int x, int y, int w, int h,int vX,int vY) {
  glColor3f(1,1,1);

  glEnable(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D, idPersonagem);

  glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0);
      glVertex2i(x + vX, y + vY);
      glTexCoord2f(1,0);
      glVertex2i(x + w + vX, y + vY);
      glTexCoord2f(1,1);
      glVertex2i(x + w + vX, y + h + vY);
      glTexCoord2f(0,1);
      glVertex2i(x + vX, y + h + vY);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    desenhaCenarioFundo();

    desenhaJogador();

    for(int i = 0; i < quantidadeDeMoscas; i++)
        desenhaMoscas(moscas[i].posicao.x,moscas[i].posicao.y,7,7,moscas[i].velocidade.x,moscas[i].velocidade.y);

        glColor3f(1,0,0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10,"Teste",10,90,0);

    glutSwapBuffers();
}

void redimensiona(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(mundoEsquerda,mundoDireita,mundoBaixo,mundoCima,mundoProximo,mundoLonge);
    glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
    case 'a':
        if(lingua.posicao.x-larguraLingua >= mundoEsquerda)
            lingua.posicao.x-=2;
        break;
    case 'd':
        if(lingua.posicao.x+larguraLingua <= mundoDireita)
            lingua.posicao.x+=2;
        break;
    case 's':
        if(alturaLinguaCima >= mundoBaixo + 10){
            alturaLinguaCima-=2;
            alturaPontaLingua+=2;
            }
        break;
    case 'w':
        if(alturaLinguaCima <= 1.8*mundoCima){
            alturaLinguaCima+=2;
            alturaPontaLingua-=2;
        }
        break;


    }
}

void gerarMovimento(){
    double vel;
    srand(time(NULL));
    for(int i  = 0; i < 10; i++){
        vel = rand()%100;
        vel = (double)vel/10000;
        if(rand() % 2 == 0)
            vel *= -1;
        moscas[i].velocidade.x+= vel;
        vel = rand()%100;
        vel = (double)vel/10000;
        if(rand() % 2 == 0)
            vel*= -1;
        moscas[i].velocidade.y += vel;
    }

}

void testeMoscas(){
    double vel;
    srand(time(NULL));
    for(int i  = 0; i < quantidadeDeMoscas; i++){
        if(moscas[i].posicao.x + moscas[i].velocidade.x > mundoDireita || moscas[i].posicao.x + moscas[i].velocidade.x < mundoEsquerda || moscas[i].posicao.y + moscas[i].velocidade.y > mundoCima || moscas[i].posicao.y + moscas[i].velocidade.y < mundoBaixo){
            moscas[i].posicao.x = rand()%100;
            moscas[i].posicao.y = rand()%100;
            moscas[i].velocidade.x = 0;
            moscas[i].velocidade.y = 0;

        }

    }
}

void testeColisao(){

    for(int i  = 0; i < quantidadeDeMoscas; i++){
        if(moscas[i].posicao.x == lingua.posicao.x && moscas[i].posicao.y >= alturaPontaLingua && moscas[i].posicao.y <= alturaLinguaCima){
            OBJETO aux = moscas[i];
            moscas[i] = moscas[quantidadeDeMoscas - 1];
            moscas[quantidadeDeMoscas - 1] = aux;
            quantidadeDeMoscas--;
            printf("Pegou\n");
            if(quantidadeDeMoscas == 0)
            	printf("ganhou\n");
                //exit(0);
        }
    }

}

void atualiza()
{
    glutPostRedisplay();


    gerarMovimento();

    testeMoscas();

    testeColisao();

    glColor3f(1,0,0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10,"Teste",0,-100,0);

    //spriteMoscaAtual++;
    if(spriteMoscaAtual == 23)
        spriteMoscaAtual = 0;

    idPersonagem = 0;



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
    glutDisplayFunc(desenha);
    glutIdleFunc(atualiza);

    inicializa();

    glutTimerFunc(0, atualiza, 0);

    glutMainLoop();

    return 0;
}

