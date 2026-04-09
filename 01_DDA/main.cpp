#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

int x1, y1, x2, y2;


void dL(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (1)
    {
        glVertex2i(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    glEnd();
}

// Display Function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    dL(x1, y1, x2, y2);

    glFlush();
}

// Initialization
void init()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 500, 0, 500);
}

// Main Function
int main(int argc, char** argv)
{
    printf("Enter first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
