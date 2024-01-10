#include <GL/glut.h>
#include <cmath>

void display() {

    int x1 = 10, y1 = 1;
    int x2 = 1, y2 = 10;

    glBegin(GL_POINT);

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
