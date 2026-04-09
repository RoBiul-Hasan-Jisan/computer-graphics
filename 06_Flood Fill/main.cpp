#include <GL/glut.h>
#include <stdio.h>

// Function to get pixel color
void getPixel(int x, int y, float color[3])
{
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

// Function to set pixel color
void setPixel(int x, int y, float fillColor[3])
{
    glColor3f(fillColor[0], fillColor[1], fillColor[2]);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Flood Fill (4-connected)
void floodFill(int x, int y, float oldColor[3], float newColor[3])
{
    float color[3];
    getPixel(x, y, color);

    // Check if current pixel matches old color
    if ((color[0] == oldColor[0]) &&
        (color[1] == oldColor[1]) &&
        (color[2] == oldColor[2]))
    {
        setPixel(x, y, newColor);

        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}

// Draw a boundary shape
void drawShape()
{
    glColor3f(1, 1, 1);
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

// Mouse click to fill
void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float oldColor[3] = {0, 0, 0};   // background (black)
        float newColor[3] = {1, 0, 0};   // fill color (red)

        floodFill(x, 500 - y, oldColor, newColor);
    }
}

// Init
void init()
{
    glClearColor(0, 0, 0, 0);

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
    glutCreateWindow("Flood Fill Algorithm");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
