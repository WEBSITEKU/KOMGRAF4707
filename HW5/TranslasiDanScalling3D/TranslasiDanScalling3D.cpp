#include <GL/glut.h>

float translateX = 0.0f;
float translateY = 0.0f;
float scale = 1.0f;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Posisi kamera
    gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0);

    // Transformasi objek 3D
    glTranslatef(translateX, translateY, 0.0f);  // Translasi objek
    glScalef(scale, scale, scale);  // Scaling

    // Gambar objek 3D di sini
    glutWireCube(1.0);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        translateX += 0.1f;
        break;
    case 'a':
        translateX -= 0.1f;
        break;
    case 'w':
        translateY += 0.1f;
        break;
    case 's':
        translateY -= 0.1f;
        break;
    case 'i':
        scale += 0.1f;
        break;
    case 'k':
        scale -= 0.1f;
        break;
    case 27:  // ASCII untuk tombol Escape
        exit(0);
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Translating and scalling 3D Object using GLUT");
    glutInitWindowSize(800, 600);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
