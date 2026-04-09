#include <stdio.h>
#include <GL/glut.h>
#include <math.h>


float x_start, y_start, x_end, y_end;

void display() {
    float dx, dy, steps, x_inc, y_inc, x, y;

    dx = x_end - x_start;
    dy = y_end - y_start;

    steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    // Increment values
    x_inc = dx / steps;
    y_inc = dy / steps;

    x = x_start;
    y = y_start;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    for (int i = 0; i <= steps; i++) {
        glVertex2f(x / 100.0, y / 100.0);
        printf("x = %.2f, y = %.2f\n", x, y);

        x += x_inc;
        y += y_inc;
    }

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 5, 0, 5);
}

int main(int argc, char** argv) {

    printf("Enter first point (x y): ");
    scanf("%f %f", &x_start, &y_start);

    printf("Enter second point (x y): ");
    scanf("%f %f", &x_end, &y_end);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
