#include <GL/glut.h>
#include <stdio.h>

// Get pixel color
void getPixel(int x, int y, float color[3])
{
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

// Set pixel color
void setPixel(int x, int y, float fillColor[3])
{
    glColor3f(fillColor[0], fillColor[1], fillColor[2]);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Boundary Fill (4-connected)
void boundaryFill(int x, int y, float fillColor[3], float boundaryColor[3])
{
    float color[3];
    getPixel(x, y, color);

    // Fill if pixel is not boundary and not already filled
    if ((color[0] != boundaryColor[0] ||
         color[1] != boundaryColor[1] ||
         color[2] != boundaryColor[2]) &&

        (color[0] != fillColor[0] ||
         color[1] != fillColor[1] ||
         color[2] != fillColor[2]))
    {
        setPixel(x, y, fillColor);

        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

// Draw boundary shape
void drawShape()
{
    glColor3f(1, 1, 1); // boundary color (white)

    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 100);
        glVertex2i(400, 100);
        glVertex2i(400, 400);
        glVertex2i(100, 400);
    glEnd();
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawShape();
    glFlush();
}

// Mouse click
void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float fillColor[3] = {1, 0, 0};      // red fill
        float boundaryColor[3] = {1, 1, 1};  // white boundary

        boundaryFill(x, 500 - y, fillColor, boundaryColor);
    }
}

// Init
void init()
{
    glClearColor(0, 0, 0, 0); // black background

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 500, 0, 500);
}

// Main
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Boundary Fill Algorithm");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
