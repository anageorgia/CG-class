//
//  main.cpp
//  ProjetoCG_2019.1_xcode
//
//  Created by Ana Geórgia Gama on 27/02/19.
//  Copyright © 2019 Ana Geórgia Gama. All rights reserved.
//

#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <math.h>
#include <stdbool.h>



// Camera
GLdouble angulo1 = M_PI/2;
GLdouble angulo2 = 0;

// distancia da camera para o objeto
GLdouble raio = 50;

//numero de vezes que vai girar e multiplica por pi/180 para deixar em rad
double giro = 5 * M_PI / 180;

GLfloat fAspect;

//usado para desenhar os arcos - partialDisk
GLUquadricObj *quadratic;

//porta
float right_door_angle = 0.0f;
float left_door_angle = 0.0f;


//-- Cores
void rgb(float r, float g, float b){
    glColor3f(r/255, g/255, b/255);
}

//-- Retângulo
void desenhaRetangulo(GLfloat x, GLfloat y, GLfloat z, GLfloat sx, GLfloat sy, GLfloat sz) {
    
    glPushMatrix();
    
    // Primeiro tira da origem
    glTranslatef(x, y, z);
    
    // Depois seta a dimensão
    glScalef(sx, sy, sz);
    
    // Desenha um cubo sólido
    glutSolidCube(1);
    
    glPopMatrix();
}


//-- Chão
void desenhaChao() {
    
    glPushMatrix();

    rgb(0,0,0);
    desenhaRetangulo(0, -4, -40,     //variáveis da translação de eixo
                     140, 0.3, 94);  //variáveis da escala - largura, espessura, cumprimento
    
    glPopMatrix();

}


//-- Semi-círculo da parede do fundo
void desenhaSemiCirculo() {
    
    glPushMatrix();
    
    rgb(255, 255, 240);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 26, -75);    //0
        glVertex3f(-30, 26, -75);  //1
        glVertex3f(-20, 35, -75);  //2
        glVertex3f(-10, 40, -75);  //3
        glVertex3f(10, 40, -75);   //4
        glVertex3f(20, 35, -75);   //5
        glVertex3f(30, 26, -75);   //6
    glEnd();
    
    glPopMatrix();
}


//-- Cruz da parede da frente
void desenhaCruz() {
    
    glPushMatrix();
    rgb(255, 218, 185);
    
    // Retângulo Vertical
    desenhaRetangulo(-25, 18.7, -2.9,
                     1, 35, 0.5);
    
    // Retângulo Horizontal
    desenhaRetangulo(-24.6, 28.7, -2.9,
                     12, 1, 0.5);
    
    glPopMatrix();
}


void desenhaMarquise() {
    
    glPushMatrix();
    
    //-- Parede frente-cima - Marquise
    //rgb(245, 245, 245);
    
    rgb(255, 218, 185);
    desenhaRetangulo(26, 26.6, 1.6,
                     87, 2, 14);
    
    rgb(245, 245, 220); //Beige

    //-- Suporte Reto Esquerda
    glBegin(GL_QUADS);
        glVertex3f(-10, -4, 6); //0
        glVertex3f(-12, -4, 6); //1
        glVertex3f(-12, 27, 6); //2
        glVertex3f(-10, 27, 6); //3
    glEnd();
    
    //-- Suporte Reto Direita
    glBegin(GL_QUADS);
        glVertex3f(32, -4, 6); //0
        glVertex3f(30, -4, 6); //1
        glVertex3f(30, 27, 6); //2
        glVertex3f(32, 27, 6); //3
    glEnd();
    
    //-- Suporte Inclinado Esquerda - Frente
    glBegin(GL_QUADS);
        glVertex3f(52, -4, 6); //0
        glVertex3f(50, -4, 6); //1
        glVertex3f(38, 27, 6); //2
        glVertex3f(40, 27, 6); //3
    glEnd();
    
    //-- Suporte Inclinado Esquerda - Trás
    glBegin(GL_QUADS);
        glVertex3f(52, -4, -4); //0
        glVertex3f(50, -4, -4); //1
        glVertex3f(38, 27, -4); //2
        glVertex3f(40, 27, -4); //3
    glEnd();
    
    //-- Suporte Inclinado Direita - Frente
    glBegin(GL_QUADS);
        glVertex3f(55, -4, 6); //0
        glVertex3f(53, -4, 6); //1
        glVertex3f(62, 27, 6); //2
        glVertex3f(64, 27, 6); //3
    glEnd();
    
    //-- Suporte Inclinado Direita - Trás
    glBegin(GL_QUADS);
        glVertex3f(55, -4, -4); //0
        glVertex3f(53, -4, -4); //1
        glVertex3f(62, 27, -4); //2
        glVertex3f(64, 27, -4); //3
    glEnd();
    
    
    glPopMatrix();
    
}



//-- Cobugol da parte de cima da frente
void desenhaCobugolFrente() {
    
    glPushMatrix();
    
    rgb(255, 218, 185);
    //rgb(250,235,215);

    // Canto Esquerdo
    desenhaRetangulo(-14, 32, -5.8,
                     1, 11, 0.5);
    
    
    desenhaRetangulo(-10, 33, -5.8,
                     1, 12.5, 0.5);
    
    
    desenhaRetangulo(-6, 33, -5.8,
                     1, 12.5, 0.5);
    
    
    desenhaRetangulo(-2, 33, -5.8,
                     1, 12.5, 0.5);
    
    
    desenhaRetangulo(2, 33, -5.8,
                     1, 12.5, 0.5);
    
    
    // Central - maior
    desenhaRetangulo(6, 33, -5.8,
                     1, 12.5, 0.5);
    
    
    desenhaRetangulo(10, 32.5, -5.8,
                     1, 12, 0.5);
    
    
    desenhaRetangulo(14, 32, -5.8,
                     1, 11, 0.5);
    
    
    desenhaRetangulo(18, 31, -5.8,
                     1, 9, 0.5);
    
    // Canto Direito
    desenhaRetangulo(22, 29.5, -5.8,
                     1, 6.5, 0.5);
    
    
    glPopMatrix();
    
}



//-- Desenha todas as paredes
void desenhaParedes() {
    
    glPushMatrix();
    
    //-- Parede direita
    rgb(245,245,245);
    desenhaRetangulo(30, 11, -40,
                     0.5, 30, 70);
    
    //-- Parede esquerda
    rgb(245, 245, 245);
    desenhaRetangulo(-30, 11, -40,
                     0.5, 30, 70);
    
    //-- Parede fundo
    rgb(255, 255, 240);
    desenhaRetangulo(0, 11, -75,
                     60, 30, 0.5);

    
//------------------------------------- Frente ------------------------------------- //
    
    //-- Parede frente-esquerda
    rgb(255, 255, 240);
    desenhaRetangulo(-17.5, 11, -4.8,
                     25, 30, 0.5);

    //-- Parede frente-direita
    rgb(255, 255, 240);
    desenhaRetangulo(28, 11, -4.8,
                     4, 30, 0.5);



    //-- Parede frente cruz
    rgb(255, 240, 220);
    desenhaRetangulo(-25, 18.7, -4.8,
                     15, 45, 4);


    desenhaCruz();

    desenhaMarquise();

    desenhaCobugolFrente();
    

//---------------------------------------------------------------------------------- //
    
    glPopMatrix();

}

// Face virada para esquerda
void desenhaJanela1(GLfloat x, GLfloat y, GLfloat z) {
    
    glPushMatrix();
    
    glTranslatef(x, y, z);
    
    rgb(139, 69, 19); //SaddieBrown
    // Fundo lado esquerdo
    glBegin(GL_QUADS);
        glVertex3f(-30.5, 4, -70);    //0
        glVertex3f(-30.5, 4, -45);   //1
        glVertex3f(-30.5, 15, -45);  //2
        glVertex3f(-30.5, 15, -70);   //3
    glEnd();
    
    rgb(224, 255, 255); //LightCyan
    glBegin(GL_QUADS);
        glVertex3f(-30.7, 6, -68);    //0
        glVertex3f(-30.7, 6, -46);    //1
        glVertex3f(-30.7, 13, -46);   //2
        glVertex3f(-30.7, 13, -68);   //3
    glEnd();
    
    
    
    glPopMatrix();

}

// Face virada para direita
void desenhaJanela2(GLfloat x, GLfloat y, GLfloat z) {
    
    glPushMatrix();
    
    glTranslatef(x, y, z);
    
    rgb(139, 69, 19); //SaddieBrown
    // Fundo lado esquerdo
    glBegin(GL_QUADS);
        glVertex3f(30.5, 4, -70);    //0
        glVertex3f(30.5, 4, -45);   //1
        glVertex3f(30.5, 15, -45);  //2
        glVertex3f(30.5, 15, -70);   //3
    glEnd();
    
    rgb(224, 255, 255); //LightCyan
    glBegin(GL_QUADS);
        glVertex3f(30.7, 6, -68);    //0
        glVertex3f(30.7, 6, -46);    //1
        glVertex3f(30.7, 13, -46);   //2
        glVertex3f(30.7, 13, -68);   //3
    glEnd();
    
    
    
    glPopMatrix();
    
}




//-- Arco
void umArco(GLfloat x, GLfloat y, GLfloat z, GLfloat sx, GLfloat sy, GLfloat sz) {
    
    glPushMatrix();
    
    // Primeiro tira da origem
    glTranslatef(x, y, z);
    
    // Depois seta a dimensão
    glScalef(sx, sy, sz);
    
    // Arcos
    // obj, raio interno, raio externo, slices, loop, angulo inicial, angulo final
    gluPartialDisk(quadratic, 43, 46, 30, 30, 0, 90);
    gluPartialDisk(quadratic, 43, 46, 30, 30, 0, -90);
    
    glPopMatrix();
    
}


//-- Desenha e posiciona todos os arcos
void desenhaArcos() {
    
    glPushMatrix();
    
    // Arco fundo
    rgb(255, 255,240);
    umArco(0, -4, -75.4,  //local
           0.9, 1, 1);    //tamanho
    
    // Arco meio-fundo
    rgb(255, 255,240);
    umArco(0, -4, -52.4,  //local
           0.9, 1, 1);    //tamanho
    
    // Arco meio-frente
    rgb(255, 255,240);
    umArco(0, -4, -28.4, //local
           0.9, 1, 1);   //tamanho
    
    // Arco frente
    rgb(255, 255,240);
    umArco(0, -4, -4.8, //local
           0.9, 1, 1);  //tamanho
    
    glPopMatrix();

}


//-- Teto
void desenhaTeto() {
    
    //Teto
    rgb(250,235,215); // AntiqueWhite
    glBegin(GL_QUAD_STRIP);
        glVertex3f(-30, 26, -4.8);    // 0
        glVertex3f(-30, 26, -75);     // 1
        glVertex3f(-20, 35, -4.8);    // 2
        glVertex3f(-20, 35, -75);     // 3
        glVertex3f(-10, 40, -4.8);    // 4
        glVertex3f(-10, 40, -75);     // 5
        glVertex3f(10, 40, -4.8);     // 6
        glVertex3f(10, 40, -75);      // 7
        glVertex3f(20, 35, -4.8);     // 8
        glVertex3f(20, 35, -75);      // 9
        glVertex3f(30, 26, -4.8);     // 10
        glVertex3f(30, 26, -75);      // 11
    glEnd();
    
}


//-- Porta
void desenhaPorta() {
    
    //-- Esquerda fixa
    //rgb(30,144,255); // azul
    rgb(201, 105, 30); //Chocolate
    
    glBegin(GL_QUADS);
        glVertex3f(2, -4, -5); //0
        glVertex3f(-6, -4, -5); //1
        glVertex3f(-6, 26, -5); //2
        glVertex3f(2, 26, -5); //3
    glEnd();
    
    //-- Esquerda móvel
    //rgb(147,112,216); // lilás
    rgb(201, 105, 30); //Chocolate
    
    glPushMatrix();
    glRotatef(left_door_angle, 0,1,0);
    glBegin(GL_QUADS);
        glVertex3f(10, -4, -5); //0
        glVertex3f(2, -4, -5); //1
        glVertex3f(2, 26, -5); //2
        glVertex3f(10, 26, -5); //3
    glEnd();
    glPopMatrix();
    
    //-- Direita móvel
    //rgb(255,0,0); // vermelho
    rgb(201, 105, 30); //Chocolate
    
    glPushMatrix();
    //glRotatef(right_door_angle, 0,1,0);
    glBegin(GL_QUADS);
        glVertex3f(18, -4, -5); //0
        glVertex3f(10, -4, -5); //1
        glVertex3f(10, 26, -5); //2
        glVertex3f(18, 26, -5); //3
    glEnd();
    glPopMatrix();
    
    //-- Direita fixa
    //rgb(255,165,0); // laranja
   
    glBegin(GL_QUADS);
        glVertex3f(26, -4, -5); //0
        glVertex3f(18, -4, -5); //1
        glVertex3f(18, 26, -5); //2
        glVertex3f(26, 26, -5); //3
    glEnd();
    
    
    //-- Vidros esquerda fixa
    rgb(255,255,255); // branco
    
    //-- Vidro esquerda fixa
    glBegin(GL_QUADS);
        glVertex3f(1, 2, -4.99); //0
        glVertex3f(-4, 2, -4.99); //1
        glVertex3f(-4, 23, -4.99); //2
        glVertex3f(1, 23, -4.99); //3
    glEnd();
    
    //-- Vidro esquerda móvel
    glPushMatrix();
    glRotatef(left_door_angle, 0,1,0);
    glBegin(GL_QUADS);
        glVertex3f(9, 2, -4.99); //0
        glVertex3f(3, 2, -4.99); //1
        glVertex3f(3, 23, -4.99); //2
        glVertex3f(9, 23, -4.99); //3
    glEnd();
    glPopMatrix();
    
    //-- Vidro direita móvel
    glPushMatrix();
    //glRotatef(left_door_angle, 0,1,0);
    glBegin(GL_QUADS);
        glVertex3f(17, 2, -4.99); //0
        glVertex3f(11, 2, -4.99); //1
        glVertex3f(11, 23, -4.99); //2
        glVertex3f(17, 23, -4.99); //3
    glEnd();
    glPopMatrix();
    
    //-- Vidro direita fixa
    glBegin(GL_QUADS);
        glVertex3f(19, 2, -4.99); //0
        glVertex3f(25, 2, -4.99); //1
        glVertex3f(25, 23, -4.99); //2
        glVertex3f(19, 23, -4.99); //3
    glEnd();
    
}




//---------------------------------------------------------------------------------------------------------------//
//                                                OBJETOS                                                        //
//---------------------------------------------------------------------------------------------------------------//



//-- Altar

void desenhaAltar() {
    
    glPushMatrix();
    
    //-- Batente - chão
    rgb(255,248,220);
    desenhaRetangulo(0, -3, -60,  //variáveis da translação de eixo
                     40, 2, 20);  //variáveis da escala - largura, espessura, cumprimento
    
    
    //-- Tampa da mesa
    rgb(201, 105, 30); //Chocolate
    
    desenhaRetangulo(0, 8, -58,   //variáveis da translação de eixo
                     30, 1, 10);  //variáveis da escala - largura, espessura, cumprimento
    
    //-- Base da mesa
    rgb(201, 105, 30); //Chocolate

    desenhaRetangulo(0, 2, -56,   //variáveis da translação de eixo
                     10, 11, 5);  //variáveis da escala - largura, espessura, cumprimento
    
    glPopMatrix();
    
}



//-- Bancos

void desenhaBanco(GLfloat x, GLfloat y, GLfloat z) {
    
    glPushMatrix();
    
    glTranslatef(x, y, z);
    
    
    //-- Primeiro banco esquerda
    
    rgb(201, 105, 30); //Chocolate
    
    //-- Assento
    desenhaRetangulo(-18, 0, -32,  //variáveis da translação de eixo
                     18, 1, 5);    //variáveis da escala - largura, espessura, cumprimento
    
    //-- Encosto
    desenhaRetangulo(-18, 5, -30,
                     18, 5, 0.3);
    
    
    //-- Pés ----------------------
    rgb(205, 133, 63); //Peru
    
    //Pé esquerdo frente
    desenhaRetangulo(-24, 0, -29.5,
                     1, 8, 0.5);
    
    //Pé esquerdo trás
    desenhaRetangulo(-24, -2, -33,
                     1, 4, 0.5);
    
    //Pé direito frente
    desenhaRetangulo(-12, 0, -29.5,
                     1, 8, 0.5);
    
    //Pé direito trás
    desenhaRetangulo(-12, -2, -33,
                     1, 4, 0.5);
    
    glPopMatrix();
    
}



void desenhaTapete() {
    
    rgb(165, 42, 42); //Brown
    
    glBegin(GL_QUADS);
        glVertex3f(5, -3.5, -7.5);  //0
        glVertex3f(-5, -3.5, -7.5); //1
        glVertex3f(-5, -3.5, -48.5);  //2
        glVertex3f(5, -3.5, -48.5);   //3
    glEnd();
    
    
}







//---------------------------------------------------------------------------------------------------------------//
//                                              FIM - OBJETOS                                                    //
//---------------------------------------------------------------------------------------------------------------//


// Função callback chamada para fazer o desenho
void desenha(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //--- Chão
    desenhaChao();
    
    //-- Paredes
    desenhaParedes();
    
    //-- Arcos
    desenhaArcos();
    
    //-- Teto
    desenhaTeto();
    
    //-- Fundo - semi-círculo
    desenhaSemiCirculo();
    
    
    //-- Porta
    desenhaPorta();
    
    
    //-- Janelas
    // Fundo esquerda
    desenhaJanela1(0, 0, 0);
    desenhaJanela2(-60, 0, 0);
    
    // Frente esquerda
    desenhaJanela1(0, 0, 35);
    desenhaJanela2(-60, 0, 35);
    
    // Fundo direita
    desenhaJanela2(0, 0, 0);
    desenhaJanela1(60, 0, 0);

    
    // Frente direita
    desenhaJanela2(0, 0, 35);
    desenhaJanela1(60, 0, 35);




    
    
    
    
    //-- Altar
    desenhaAltar();
    
    //-- Bancos
    // Frente esquerda
    desenhaBanco(0, 0, 0);
    
    //Meio esquerda
    desenhaBanco(0, 0, 8);
    
    //Fundo esquerda
    desenhaBanco(0, 0, 16);
    
    // Frente direita
    desenhaBanco(35, 0, 0);
    
    //Meio direita
    desenhaBanco(35, 0, 8);
    
    //Fundo direita
    desenhaBanco(35, 0, 16);
    
    desenhaTapete();
    
    
    
    glutSwapBuffers();
}

















void inicializa (void) {
    glClearColor(0.7, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    
    quadratic = gluNewQuadric();
    
}

void visao(void) {
    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    // Especifica posição do observador e do alvo
    gluLookAt(raio*sin(angulo2)*sin(angulo1), raio*cos(angulo1), raio*cos(angulo2)*sin(angulo1),
              0, 0, 0,
              0, 1, 0);
}

// Função usada para especificar o volume de visualização
void visualizacaoParams(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65, fAspect, 0.5, 500);
    visao();
}

void reshapeFunc(GLsizei w, GLsizei h) {
    if (h == 0) { h = 1; }
    
    glViewport(0, 0, w, h);
    fAspect = (GLfloat) w / (GLfloat) h;
    
    visualizacaoParams();
}

// Callback para gerenciar eventos do teclado para teclas especiais (F1, PgDn, entre outras)
void specialFunc(int key, int x, int y) {
    glLoadIdentity();
    
    switch (key) {
            
            // gira 360 graus para direita
        case GLUT_KEY_LEFT:
            angulo2 += giro;
            break;
            
            // gira 360 graus para direita
        case GLUT_KEY_RIGHT:
            angulo2 -= giro;
            break;
            
            // gira 180 graus para cima
        case GLUT_KEY_UP:
            if(angulo1 + giro <= M_PI) angulo1 += giro;
            break;
            
            // gira 180 graus para baixo
        case GLUT_KEY_DOWN:
            if(angulo1 - giro >= 0) angulo1 -= giro;
            break;
            
            // zoom in
        case 'p':
            if(raio + 1 > 3) raio -= 2;
            break;
            
            // zoom out
        case 'l':
            raio += 2;
            break;
        case 'o':
            if(right_door_angle < 90.0f || left_door_angle < 90.0f){
                //right_door_angle +=2.0f;
                
                left_door_angle += 2.0f;
                right_door_angle += 2.0f;
                
            }
            glutPostRedisplay();
            break;
        case 'c':
            //if(right_door_angle >= 2.0f) right_door_angle -=2.0f;
            
            if(right_door_angle >=2.0f || left_door_angle >=2.0f){
                
                left_door_angle -= 2.0f;
                right_door_angle -= 2.0f;
                
            }
            
            glutPostRedisplay();
            break;
            
    }
    
    angulo1 = angulo1 - ((int) (angulo1 / (2 * M_PI)));
    
    gluLookAt(raio * sin(angulo2) * sin(angulo1), raio * cos(angulo1), raio * cos(angulo2) * sin(angulo1),
              0, 0, 0,
              0, 1, 0);
    
    glutPostRedisplay();
}


// Programa Principal
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280,800);
    glutCreateWindow("Capela do Hospital do Açúcar");
    glutDisplayFunc(desenha);
    glutReshapeFunc(reshapeFunc);
    glutSpecialFunc(specialFunc);
    inicializa();
    //timer(0);
    glutMainLoop();
}
