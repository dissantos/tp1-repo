#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "personagem.h"
#include "sistema.h"

GLuint carregaTextura(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

void escreveTexto(void * font, char *s, float x, float y, float z)
{
    int i;
    glRasterPos3f(x, y, z);

    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

void desenhaObjeto(OBJETO objAtual,const char* arquivo){

    GLuint idTextura = carregaTextura(arquivo);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, idTextura);

    glPushMatrix();
        glTranslatef(objAtual.posicao.x+objAtual.velocidade.x, objAtual.posicao.y + objAtual.velocidade.y, 0);
        glBegin(GL_TRIANGLE_FAN);
	    glTexCoord2f(0,0);
            glVertex3f(-objAtual.largura/2, -objAtual.altura/2,0);
	    glTexCoord2f(1,0);
            glVertex3f(objAtual.largura/2,  -objAtual.altura/2,0);
	    glTexCoord2f(1,1);
            glVertex3f( objAtual.largura/2,  objAtual.altura/2,0);
	    glTexCoord2f(0,1);
	    glVertex3f(-objAtual.largura/2,  objAtual.altura/2,0);
        glEnd();
    glPopMatrix();
    glEnd();
    glDisable(GL_TEXTURE_2D);


}
