#include "sistema.h"
#include "personagem.h"
#include "tela.h"
#include "menu.h"
#include <time.h>

OBJETO lingua;


int tela = TELA_MENU;


void inicializa()
{
    mundoX = 800;
    mundoY = 800;
    glClearColor(1, 1, 1, 1);
    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}



void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    iniciaMenu(0,0);
    glColor3f(1,1,1);
    
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
    if(tela == TELA_JOGO)
        switch (key)
        {
        case 27:
            exit(0);
           /*
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
            */


        }
    }


void atualiza()
{
    glutPostRedisplay();




    glColor3f(1,0,0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10,"Teste",0,-100,0);





    glutTimerFunc(25, atualiza, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
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

