#include <GL/glut.h>
#include <cmath>

void display() {

    int x1 = 4, y1 = 7;
    int x2 = 7, y2 = 3;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = dx > dy ? dx : dy;

    float xIncrement = (float)(x2 - x1) / steps;
    float yIncrement = (float)(y2 - y1) / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        glVertex2f(x, y);
        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
    glFlush();
}

void myinit() {
    glPointSize(5.0);
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Algoritma DDA");

    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
