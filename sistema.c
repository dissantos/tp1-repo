#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "personagem.h"
#include "sistema.h"

GLuint carregaTextura(const char* arquivo){
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

void escreveTexto(void * font, char *s, float x, float y, float z){
    int i;
    glRasterPos3f(x, y, z);

    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

void desenhaObjeto(OBJETO objAtual,GLuint idTextura){
    
    glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTextura);

    glPushMatrix();
        glTranslatef(objAtual.posicao.x, objAtual.posicao.y, 0);
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

void iniciarMusica(char const nome[40], int loop){
        Mix_Chunk *som = NULL;
        int canal;
   int canal_audio=2;
        int taxa_audio = 22050;
        Uint16 formato_audio = AUDIO_S16SYS;
        int audio_buffers = 4096;
        if(Mix_OpenAudio(taxa_audio, formato_audio, canal_audio, audio_buffers) != 0) {
                printf("Não pode inicializar audio: %s\n", Mix_GetError());
        }
       som = Mix_LoadWAV(nome);
        if(som == NULL) {
                printf("Não pode inicializar audio: %s\n", Mix_GetError());
        }
       Mix_HaltChannel(-1);
       canal = Mix_PlayChannel( -1, som, loop);
        if(canal == -1) {
                printf("Não pode inicializar audio: %s\n", Mix_GetError());
        }
}

void pararMusica(){
 Mix_HaltChannel(-1);

}


