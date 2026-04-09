#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// Animation status variables
float sunX = 0;
float sunY = 0;

int meghStatus = 0;
int sunStatus = 0;
int waterStatus = 0;
int carStatus = 0;
int birdsStatus = 0;
int windmillStatus = 0;
int fishStatus = 0;
int timeOfDay = 0; // 0=day, 1=evening, 2=night

float meghX = 0;
float meghY = 0;

float waterX = 0;
float waterY = 0;

float carX = 0;
float carY = 0;

float birdsX = 0;
float birdsY = 0;

float windmillAngle = 0;
float fishX = 0;

// Circle drawing function
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
    glFlush();
}

// Sky with time of day
void sky()
{
    if(timeOfDay == 0) { // Day
        glColor3ub(0, 191, 255);
    } else if(timeOfDay == 1) { // Evening
        glColor3ub(255, 140, 0);
    } else { // Night
        glColor3ub(25, 25, 112);
    }
    glBegin(GL_QUADS);
    glVertex2i(0, 255);
    glVertex2i(640, 255);
    glVertex2i(640, 480);
    glVertex2i(0, 480);
    glEnd();
}

// Stars at night
void stars()
{
    if(timeOfDay == 2) {
        glColor3ub(255, 255, 255);
        glPointSize(2);
        glBegin(GL_POINTS);
        for(int i = 0; i < 100; i++) {
            glVertex2i(rand() % 640, rand() % 200 + 280);
        }
        glEnd();
        glPointSize(1);
    }
}

void drawSun(int x)
{
    if(timeOfDay == 0) {
        glColor3ub(250, 250, 10);
    } else if(timeOfDay == 1) {
        glColor3ub(255, 100, 0);
    } else {
        glColor3ub(255, 255, 200);
    }
    DrawCircle(550, 350, 35, 1000);
}

// Cloud
void megh(int x)
{
    if(timeOfDay == 2) {
        glColor3ub(50, 50, 60);
    } else {
        glColor3ub(200, 220, 220);
    }
    DrawCircle(20, 400, 25, 2000);
    DrawCircle(50, 400, 35, 2000);
    DrawCircle(80, 400, 25, 2000);

    if(timeOfDay == 2) {
        glColor3ub(60, 60, 70);
    } else {
        glColor3ub(200, 201, 200);
    }
    DrawCircle(130, 420, 25, 2000);
    DrawCircle(160, 420, 35, 2000);
    DrawCircle(190, 420, 25, 2000);
    glFlush();
}

// River water animation
void water(int x)
{
    glColor3ub(169, 242, 242);
    glBegin(GL_LINES);
    for(int i = 0; i < 20; i++) {
        glVertex2i(100 + i*30 + (rand()%10), 220);
        glVertex2i(120 + i*30 + (rand()%10), 220);
        glVertex2i(50 + i*40, 240);
        glVertex2i(70 + i*40, 240);
    }
    glEnd();

    // Boat
    glColor3ub(150, 129, 117);
    glBegin(GL_QUADS);
    glVertex2i(20, 220);
    glVertex2i(60, 220);
    glVertex2i(70, 230);
    glVertex2i(10, 230);
    glEnd();

    glColor3ub(206, 175, 109);
    glBegin(GL_POLYGON);
    glVertex2i(27, 230);
    glVertex2i(57, 230);
    glVertex2i(57, 240);
    glVertex2i(27, 240);
    glEnd();

    glColor3ub(209, 102, 27);
    glBegin(GL_TRIANGLES);
    glVertex2i(57, 230);
    glVertex2i(90, 280);
    glVertex2i(50, 290);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(57, 230);
    glVertex2i(73, 290);
    glEnd();

    glFlush();
}

// Fish in water
void fish()
{
    if(fishStatus == 1) {
        glColor3ub(255, 100, 0);
        glPushMatrix();
        glTranslatef(fishX, 200, 0);
        DrawCircle(50, 200, 5, 20);
        glBegin(GL_TRIANGLES);
        glVertex2i(55, 200);
        glVertex2i(65, 196);
        glVertex2i(65, 204);
        glEnd();
        glPopMatrix();
    }
}

// Vera (dog)
void vera()
{
    // 1st vera
    glColor3ub(208, 216, 219);
    DrawCircle(200, 150, 10, 1000);

    glColor3ub(20, 50, 10);
    DrawCircle(212, 150, 5, 1000);

    glColor3ub(0, 0, 10);
    DrawCircle(212, 145, 2, 1000);

    glColor3ub(0, 0, 0);
    DrawCircle(215, 155, 2, 1000);
    DrawCircle(209, 155, 2, 1000);

    glColor3ub(0, 0, 10);
    glBegin(GL_LINES);
    glVertex2i(193, 130); glVertex2i(193, 142);
    glVertex2i(196, 130); glVertex2i(196, 140);
    glVertex2i(203, 130); glVertex2i(203, 140);
    glVertex2i(206, 130); glVertex2i(206, 142);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POINTS);
    glVertex2i(210, 150);
    glVertex2i(214, 150);
    glEnd();

    // 2nd vera
    glColor3ub(208, 216, 219);
    DrawCircle(240, 150, 10, 1000);

    glColor3ub(20, 50, 10);
    DrawCircle(230, 150, 5, 1000);

    glColor3ub(0, 0, 10);
    DrawCircle(230, 145, 2, 1000);

    glColor3ub(0, 0, 0);
    DrawCircle(233, 155, 2, 1000);
    DrawCircle(227, 155, 2, 1000);

    glColor3ub(0, 0, 10);
    glBegin(GL_LINES);
    glVertex2i(235, 130); glVertex2i(235, 142);
    glVertex2i(238, 130); glVertex2i(238, 140);
    glVertex2i(245, 130); glVertex2i(245, 140);
    glVertex2i(248, 130); glVertex2i(248, 143);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POINTS);
    glVertex2i(228, 150);
    glVertex2i(232, 150);
    glEnd();
    glFlush();
}

// House
void house()
{
    // Left home
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2f(59.301, 158.601);
    glVertex2f(54.468, 215.306);
    glVertex2f(72.641, 235.605);
    glVertex2f(91.973, 215.306);
    glVertex2f(90.233, 150.061441);
    glEnd();

    // Chal left shadow
    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex2f(48.365, 208.643);
    glVertex2f(72.641, 235.605);
    glVertex2f(74.935, 232.195);
    glVertex2f(52.774, 208.643);
    glEnd();

    // Right body
    glColor3ub(128, 128, 0);
    glBegin(GL_POLYGON);
    glVertex2f(90.233, 150.061441);
    glVertex2f(91.973, 215.306);
    glVertex2f(173, 212.5);
    glVertex2f(169, 157.735);
    glEnd();

    // Chal
    glColor3ub(169, 169, 169);
    glBegin(GL_POLYGON);
    glVertex2f(91.973, 215.306);
    glVertex2f(72.641, 235.605);
    glVertex2f(159.509, 235.605);
    glVertex2f(177.470, 212.005);
    glEnd();

    // Window
    glColor3ub(47,79,79);
    glBegin(GL_POLYGON);
    glVertex2f(65.450, 187.15);
    glVertex2f(63.981, 206.255);
    glVertex2f(80.167,206.438);
    glVertex2f(81.182, 186.398);
    glEnd();

    // Door
    glColor3ub(47,79,79);
    glBegin(GL_POLYGON);
    glVertex2f(121.982,154.535);
    glVertex2f(121.598,195.08);
    glVertex2f(142.981,194.08);
    glVertex2f(142.836, 157);
    glEnd();
}

// Land
void land()
{
    if(timeOfDay == 2) {
        glColor3ub(100, 90, 50);
    } else {
        glColor3ub(189, 183, 107);
    }
    glBegin(GL_QUADS);
    glVertex2i(0, 60);
    glVertex2i(640, 60);
    glVertex2i(640, 180);
    glVertex2i(0, 180);
    glEnd();
}

// Flowers on ground
void flowers()
{
    // Red flower
    glColor3ub(255, 0, 0);
    DrawCircle(100, 170, 4, 20);
    glColor3ub(255, 255, 0);
    DrawCircle(100, 170, 2, 20);

    // Yellow flower
    glColor3ub(255, 255, 0);
    DrawCircle(300, 165, 4, 20);
    glColor3ub(255, 165, 0);
    DrawCircle(300, 165, 2, 20);

    // Purple flower
    glColor3ub(128, 0, 128);
    DrawCircle(500, 168, 4, 20);
    glColor3ub(255, 255, 0);
    DrawCircle(500, 168, 2, 20);
}

// Fence
void fence()
{
    glColor3ub(160, 82, 45);
    for(int i = 400; i <= 550; i += 30) {
        glBegin(GL_QUADS);
        glVertex2i(i, 150);
        glVertex2i(i+5, 150);
        glVertex2i(i+5, 175);
        glVertex2i(i, 175);
        glEnd();
    }
    glBegin(GL_QUADS);
    glVertex2i(400, 160);
    glVertex2i(550, 160);
    glVertex2i(550, 163);
    glVertex2i(400, 163);
    glEnd();
}

// Tree
void tree()
{
    glColor3ub(0,128,0);
    DrawCircle(50, 280, 50, 2000);
    DrawCircle(50, 320, 35, 3000);
    glEnd();
    glFlush();

    glColor3ub(160,82,45);
    glBegin(GL_QUADS);
    glVertex2i(40, 155);
    glVertex2i(60, 155);
    glVertex2i(60, 245);
    glVertex2i(40, 245);
    glEnd();

    glColor3ub(160,82,45);
    glBegin(GL_QUADS);
    glVertex2i(40, 245);
    glVertex2i(50, 245);
    glVertex2i(40, 270);
    glVertex2i(30, 270);
    glEnd();

    glColor3ub(160,82,45);
    glBegin(GL_QUADS);
    glVertex2i(50, 245);
    glVertex2i(60, 245);
    glVertex2i(70, 270);
    glVertex2i(60, 270);
    glEnd();
    glFlush();
}

// Road
void road()
{
    glColor3ub(57, 51, 52);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 50);
    glVertex2i(0, 50);
    glEnd();
    glFlush();

    glColor3ub(200, 200, 200);
    glBegin(GL_QUADS);
    glVertex2i(0, 50);
    glVertex2i(640, 50);
    glVertex2i(640, 60);
    glVertex2i(0, 60);
    glEnd();

    glColor3ub(0,255,255);
    glBegin(GL_LINES);
    for(int i = 0; i <= 640; i += 50) {
        glVertex2i(i, 25);
        glVertex2i(i+40, 25);
    }
    glEnd();
    glFlush();
}

// River
void river()
{
    glColor3ub(142, 227, 227);
    glBegin(GL_QUADS);
    glVertex2i(0, 180);
    glVertex2i(640, 180);
    glVertex2i(640, 255);
    glVertex2i(0, 255);
    glEnd();
}

// Ship yard
void shipyard()
{
    glColor3ub(150, 129, 117);
    glBegin(GL_QUADS);
    glVertex2i(350, 195);
    glVertex2i(360, 183);
    glVertex2i(410, 183);
    glVertex2i(420, 195);
    glEnd();

    glColor3ub(206, 175, 109);
    glBegin(GL_QUADS);
    glVertex2i(370, 195);
    glVertex2i(400, 195);
    glVertex2i(400, 210);
    glVertex2i(370, 210);
    glEnd();

    glColor3ub(142, 27, 227);
    glBegin(GL_LINES);
    glVertex2i(340, 170);
    glVertex2i(340, 250);
    glVertex2i(340, 200);
    glVertex2i(350, 195);
    glEnd();
}

// Windmill
void windmill()
{
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2i(580, 180);
    glVertex2i(590, 180);
    glVertex2i(590, 240);
    glVertex2i(580, 240);
    glEnd();

    glPushMatrix();
    glTranslatef(585, 230, 0);
    glRotatef(windmillAngle, 0, 0, 1);

    glColor3ub(200, 200, 200);
    for(int i = 0; i < 4; i++) {
        glRotatef(90, 0, 0, 1);
        glBegin(GL_QUADS);
        glVertex2i(-5, 0);
        glVertex2i(5, 0);
        glVertex2i(5, 25);
        glVertex2i(-5, 25);
        glEnd();
    }
    glPopMatrix();

    if(windmillStatus == 1) {
        windmillAngle += 5;
        if(windmillAngle >= 360) windmillAngle = 0;
    }
}

// Mountain
void mountain()
{
    glColor3ub(205,133,63);
    glBegin(GL_QUADS);
    glVertex2i(0, 255);
    glVertex2i(640, 255);
    glVertex2i(640, 258);
    glVertex2i(0, 258);
    glEnd();
}

// Opposite village
void oposite_village()
{
    glColor3ub(128,0,0);
    glBegin(GL_LINES);
    glVertex2i(200, 255);
    glVertex2i(200, 270);
    glEnd();

    glColor3ub(0,128,0);
    DrawCircle(200, 270, 5, 5000);
    DrawCircle(200, 274, 3, 5000);
    glEnd();
    glFlush();

    glColor3ub(128,0,0);
    glBegin(GL_LINES);
    glVertex2i(250, 255);
    glVertex2i(250, 275);
    glEnd();

    glColor3ub(0,128,0);
    DrawCircle(250, 275, 5, 5000);
    DrawCircle(250, 279, 3, 6000);
    glEnd();
    glFlush();
}

// Hills
void hills()
{
    glColor3ub(154,205,50);
    glBegin(GL_TRIANGLES);
    glVertex2i(180, 255);
    glVertex2i(220, 290);
    glVertex2i(260, 255);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(180, 255);
    glVertex2i(220, 290);
    glVertex2i(220, 290);
    glVertex2i(260, 255);
    glEnd();

    glColor3ub(128,128,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(255, 255);
    glVertex2i(285, 280);
    glVertex2i(315, 255);
    glEnd();

    glColor3ub(154,205,50);
    glBegin(GL_TRIANGLES);
    glVertex2i(310, 255);
    glVertex2i(380, 320);
    glVertex2i(450, 255);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(310, 255);
    glVertex2i(380, 320);
    glVertex2i(380, 320);
    glVertex2i(450, 255);
    glEnd();
}

// Birds
void birds(int x)
{
    glColor3f(1.0, 0.0, 0.0);
    DrawCircle(60, 300, 3, 1000);
    DrawCircle(63, 300, 2, 1000);

    glBegin(GL_LINES);
    glLineWidth(5);
    glVertex2i(60, 300);
    glVertex2i(65, 307);
    glVertex2i(60, 300);
    glVertex2i(55, 307);
    glEnd();

    DrawCircle(70, 310, 3, 1000);
    DrawCircle(73, 310, 2, 1000);
    glBegin(GL_LINES);
    glVertex2i(70, 310);
    glVertex2i(75, 317);
    glVertex2i(70, 310);
    glVertex2i(65, 317);
    glEnd();

    DrawCircle(75, 290, 3, 1000);
    DrawCircle(78, 290, 2, 1000);
    glBegin(GL_LINES);
    glVertex2i(75, 290);
    glVertex2i(80, 297);
    glVertex2i(75, 290);
    glVertex2i(70, 297);
    glEnd();
}

// Car
void car(int x)
{
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(15,20);
    glVertex2f(15,103);
    glVertex2f(190,103);
    glVertex2f(195,20);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(90,103.7);
    glVertex2f(93,110);
    glVertex2f(127,110);
    glVertex2f(130,103.7);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(20,62);
    glVertex2f(20,98);
    glVertex2f(190.3,98);
    glVertex2f(192.5,62);
    glEnd();

    glColor3ub(64,224,208);
    glBegin(GL_POLYGON);
    glVertex2f(23,65);
    glVertex2f(23,95);
    glVertex2f(52,95);
    glVertex2f(52,65);
    glEnd();

    glColor3ub(0,255,0);
    glBegin(GL_POLYGON);
    glVertex2f(20,20);
    glVertex2f(20,62);
    glVertex2f(192.5,62);
    glVertex2f(195,20);
    glEnd();

    glColor3ub(0,0,0);
    DrawCircle(50, 20, 10, 6000);
    DrawCircle(71, 20, 10, 6000);
    DrawCircle(160, 20, 10, 6000);

    glColor3ub(255,255,255);
    DrawCircle(50, 20, 5, 6000);
    DrawCircle(71, 20, 5, 6000);
    DrawCircle(160, 20, 5, 6000);

    glColor3ub(0,0,0);
    DrawCircle(50, 20, 2, 6000);
    DrawCircle(71, 20, 2, 6000);
    DrawCircle(160, 20,2, 6000);
}

// Move car
void movecar()
{
    if(carStatus == 1) {
        carX += 3;
    }
    if(carX > 1000) {
        carX = -300;
    }
    glPushMatrix();
    glTranslatef(carX, carY, 0);
    car(1);
    glPopMatrix();
}

// Move cloud
void movemegh()
{
    if(meghStatus == 1) {
        meghX += 0.5;
    }
    if(meghX > 2000) {
        meghX = -200;
    }
    glPushMatrix();
    glTranslatef(meghX, meghY, 0);
    megh(1);
    glPopMatrix();
    glFlush();
}

// Move water
void movewater()
{
    if(waterStatus == 1) {
        waterX += 1;
    }
    if(waterX > 2000) {
        waterX = -200;
    }
    glPushMatrix();
    glTranslatef(waterX, waterY, 0);
    water(1);
    glPopMatrix();
    glFlush();
}

// Move fish
void movefish()
{
    if(fishStatus == 1) {
        fishX += 1.5;
        if(fishX > 640) {
            fishX = -100;
        }
    }
}

// Move sun
void moveSun()
{
    if(sunStatus == 1) {
        if(sunY >= 300)
            sunX = 300;
        else
            sunX -= 1.5;
        sunY += 0.5;
    }
    glPushMatrix();
    glTranslatef(sunX, sunY, 0);
    drawSun(1);
    glPopMatrix();
    glFlush();
}

// Move birds
void movebirds()
{
    if(birdsStatus == 1) {
        birdsX += 2;
    }
    if(birdsX > 2000) {
        birdsX = -200;
    }
    glPushMatrix();
    glTranslatef(birdsX, birdsY, 0);
    birds(1);
    glPopMatrix();
}

// Rainbow effect
void rainbow()
{
    if(sunStatus == 1 && sunY > 200 && timeOfDay == 0) {
        glLineWidth(3);
        for(int i = 0; i < 7; i++) {
            switch(i) {
                case 0: glColor3ub(255, 0, 0); break;
                case 1: glColor3ub(255, 127, 0); break;
                case 2: glColor3ub(255, 255, 0); break;
                case 3: glColor3ub(0, 255, 0); break;
                case 4: glColor3ub(0, 0, 255); break;
                case 5: glColor3ub(75, 0, 130); break;
                case 6: glColor3ub(148, 0, 211); break;
            }
            glBegin(GL_LINE_STRIP);
            for(float angle = 0; angle <= 180; angle += 10) {
                float rad = angle * 3.14159 / 180;
                float x = 320 + (150 + i*5) * cos(rad);
                float y = 400 + (150 + i*5) * sin(rad);
                glVertex2f(x, y);
            }
            glEnd();
        }
        glLineWidth(1);
    }
}

// Main display function
void myDisplay(void)
{
    sky();
    stars();
    hills();
    mountain();
    oposite_village();
    moveSun();
    rainbow();
    land();
    flowers();
    fence();
    vera();
    river();
    movewater();
    fish();
    movefish();
    shipyard();
    movebirds();
    tree();
    road();
    movemegh();
    house();
    movecar();
    windmill();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

// Keyboard controls
void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 'S': case 's': sunStatus = 1; break;
        case 'N': case 'n': sunStatus = 0; break;
        case 'C': case 'c': meghStatus = 1; break;
        case 'E': case 'e': meghStatus = 0; break;
        case 'R': case 'r': waterStatus = 1; break;
        case 'T': case 't': waterStatus = 0; break;
        case 'X': case 'x': carStatus = 1; break;
        case 'Y': case 'y': carStatus = 0; break;
        case 'B': case 'b': birdsStatus = 1; break;
        case 'G': case 'g': birdsStatus = 0; break;
        case 'W': case 'w': windmillStatus = 1; break;
        case 'Q': case 'q': windmillStatus = 0; break;
        case 'F': case 'f': fishStatus = 1; break;
        case 'H': case 'h': fishStatus = 0; break;
        case 'D': case 'd': timeOfDay = (timeOfDay + 1) % 3; break;
    }
}

// Mouse controls
void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glDisable(GL_LIGHT0);
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glEnable(GL_LIGHT0);
    }
}

// Initialize OpenGL
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[] = { 550.0f, 350.0f, 100.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    srand(time(NULL));
}

// Display controls
void displayControls()
{
    printf("\n========== SMART VILLAGE CONTROLS ==========\n");
    printf("S/s - Start Sun Movement\n");
    printf("N/n - Stop Sun Movement\n");
    printf("C/c - Start Cloud Movement\n");
    printf("E/e - Stop Cloud Movement\n");
    printf("R/r - Start Water/Boat Movement\n");
    printf("T/t - Stop Water/Boat Movement\n");
    printf("X/x - Start Car Movement\n");
    printf("Y/y - Stop Car Movement\n");
    printf("B/b - Start Birds Movement\n");
    printf("G/g - Stop Birds Movement\n");
    printf("W/w - Start Windmill\n");
    printf("Q/q - Stop Windmill\n");
    printf("F/f - Start Fish Movement\n");
    printf("H/h - Stop Fish Movement\n");
    printf("D/d - Change Time of Day (Day/Evening/Night)\n");
    printf("Left Mouse Button - Turn Lights OFF\n");
    printf("Right Mouse Button - Turn Lights ON\n");
    printf("============================================\n\n");
}

// Main function
int main(int argc, char** argv)
{
    displayControls();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(840, 680);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Smart Village Scenario");
    glutPostRedisplay();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    myInit();
    glutMainLoop();
    return 0;
}
