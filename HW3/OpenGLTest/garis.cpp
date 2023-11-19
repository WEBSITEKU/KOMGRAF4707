#include <GLFW/glfw3.h>
#include <cmath>

void render(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    float X = x1;
    float Y = y1;
    for (int i = 0; i <= steps; i++) {
        glBegin(GL_POINTS);
        glVertex2f(X, Y);
        glEnd();
        glFlush(); // Memastikan semua titik telah digambar
        X += Xinc;
        Y += Yinc;
    }
}

int main() {

    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "DDA OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glOrtho(0, 800, 0, 600, -1, 1); //mengatur viewport
    int screenWidth = 800;
    int screenHeight = 600;
    int x1 = 4 + screenWidth / 2;
    int y1 = 7 + screenHeight /2;
    int x2 = 7 + screenWidth / 2;
    int y2 = 3 + screenHeight / 2;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        render(x1, y1, x2, y2);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}