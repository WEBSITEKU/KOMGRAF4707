#include <GL/glut.h>
#include <math.h>

float Ax = 4.0f;
float Ay = 7.0f;
float Bx = 7.0f;
float By = 3.0f;

float angle = 12.0f;

void drawPoints() {
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(Ax, Ay);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(Bx, By);
    glEnd();
}

void drawLine() {
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(Ax, Ay);
    glVertex2f(Bx, By);
    glEnd();
}

void rotatePoints() {
#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif
    float angleInRadians = angle * (M_PI / 180.0f);
    float cosA = cos(angleInRadians);
    float sinA = sin(angleInRadians);

    float newX_A = Ax * cosA - Ay * sinA;
    float newY_A = Ax * sinA + Ay * cosA;
    float newX_B = Bx * cosA - By * sinA;
    float newY_B = Bx * sinA + By * cosA;

    Ax = newX_A;
    Ay = newY_A;
    Bx = newX_B;
    By = newY_B;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine();
    drawPoints();
    rotatePoints();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Rotation Example");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}