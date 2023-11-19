#include <GL/glut.h>

bool isScaled = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Matriks transformasi scaling
    float matriksScaling[3][3] = { {0.5, 0.0, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.0, 1.0} };

    // Koordinat A(7,6) dan B(7,4)
    float koordinat[3][2] = { {4.0, 7.0}, {7.0, 3.0}, {1.0, 1.0} };

    // Hasil transformasi
    float hasil[3][2];

    // Melakukan operasi matriks jika sudah diklik
    if (isScaled) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                hasil[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    hasil[i][j] += matriksScaling[i][k] * koordinat[k][j];
                }
            }
        }
        glColor3f(0.1, 0.1, 0.1); // Mengubah warna titik menjadi abu abu setelah scaling
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                hasil[i][j] = koordinat[i][j];
            }
        }
        glColor3f(0.1, 0.0, 0.0); // Mengubah warna titik menjadi coklat sebelum scaling
    }

    // Menggambar titik hasil transformasi
    glBegin(GL_POINTS);
    glVertex2f(hasil[0][0], hasil[1][0]);
    glVertex2f(hasil[0][1], hasil[1][1]);
    glEnd();

    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isScaled = !isScaled;
        glutPostRedisplay();
    }
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(5.0);
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformasi Scaling");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    myinit();

    glutMainLoop();

    return 0;
}