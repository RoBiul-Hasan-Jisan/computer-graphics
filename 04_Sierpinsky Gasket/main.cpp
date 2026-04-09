#include <GL/glut.h>

// Function to draw a triangle
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Recursive function for Sierpinski
void sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int depth)
{
    if (depth == 0)
    {
        drawTriangle(x1, y1, x2, y2, x3, y3);
        return;
    }

    // Midpoints
    float mx12 = (x1 + x2) / 2;
    float my12 = (y1 + y2) / 2;

    float mx23 = (x2 + x3) / 2;
    float my23 = (y2 + y3) / 2;

    float mx31 = (x3 + x1) / 2;
    float my31 = (y3 + y1) / 2;

    // Recursive calls (3 triangles)
    sierpinski(x1, y1, mx12, my12, mx31, my31, depth - 1);
    sierpinski(mx12, my12, x2, y2, mx23, my23, depth - 1);
    sierpinski(mx31, my31, mx23, my23, x3, y3, depth - 1);
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Main triangle
    sierpinski(100, 100, 400, 100, 250, 400, 2); // depth = 2

    glFlush();
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
    glutCreateWindow("Sierpinski Gasket (Depth 2)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
