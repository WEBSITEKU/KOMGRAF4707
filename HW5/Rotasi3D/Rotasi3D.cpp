#include <GL/glut.h>

float angleX = 0.0f;
float angleY = 0.0f;
float scale = 1.0f;
float rotationSpeed = 1.0f;  // Kecepatan rotasi

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
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Transformasi objek 3D
    glTranslatef(0.0f, 0.0f, -5.0f);  // Translasi ke dalam layar
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);  // Rotasi terhadap sumbu X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);  // Rotasi terhadap sumbu Y
    glScalef(scale, scale, scale);  // Scaling

    // Rotasi objek secara otomatis
    angleX += rotationSpeed;
    angleY += rotationSpeed;

    // Gambar objek 3D di sini
    glutWireCube(1.0);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'x':
        angleX += 5.0f;
        break;
    case 'y':
        angleY += 5.0f;
        break;
    case 's':
        scale += 0.1f;
        break;
    case 'S':
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
    glutCreateWindow("Rotating 3D Object using GLUT");
    glutInitWindowSize(800, 600);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
