#include <GL/glut.h>
#include <cmath>

void display() {

    int x1 = 4, y1 = 7;
    int x2 = 7, y2 = 3;

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glBegin(GL_POINTS);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    int x = x1;
    int y = y1;

    while (true) {
        glVertex2f(x, y);

        if (x == x2 && y == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err = err - dy;
            x = x + sx;
        }

        if (e2 < dx) {
            err = err + dx;
            y = y + sy;
        }
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
    glutCreateWindow("Algoritma Bresenham");

    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
