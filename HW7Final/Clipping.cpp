#include <GL/glut.h>
#include <iostream>

// Mendefinisikan bit kode untuk kode wilayah (region codes)
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Mendefinisikan batas-batas jendela clipping
const int xMin = 50;
const int xMax = 250;
const int yMin = 50;
const int yMax = 250;

// Fungsi untuk menghitung kode wilayah suatu titik (x, y)
int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < xMin) {
        code |= LEFT;
    }
    else if (x > xMax) {
        code |= RIGHT;
    }

    if (y < yMin) {
        code |= BOTTOM;
    }
    else if (y > yMax) {
        code |= TOP;
    }

    return code;
}

// Fungsi untuk memotong garis menggunakan algoritma Cohen-Sutherland
void cohenSutherland(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        }
        else if (code1 & code2) {
            break;
        }
        else {
            int codeOut;
            double x, y;

            if (code1 != 0) {
                codeOut = code1;
            }
            else {
                codeOut = code2;
            }
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        glColor3f(0.0, 1.0, 0.0); // Warna hijau untuk garis hasil pemotongan
        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glEnd();
    }
}

// Fungsi untuk menampilkan scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Warna merah untuk garis asli
    glBegin(GL_LINES);
    glVertex2d(30, 80);
    glVertex2d(300, 200);
    glEnd();

    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk jendela clipping
    glBegin(GL_LINE_LOOP);
    glVertex2d(xMin, yMin);
    glVertex2d(xMax, yMin);
    glVertex2d(xMax, yMax);
    glVertex2d(xMin, yMax);
    glEnd();

    cohenSutherland(30, 80, 300, 200);

    glFlush();
}

// Fungsi untuk mengatur lingkungan OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 400, 0, 300);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Cohen-Sutherland Line Clipping");
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
