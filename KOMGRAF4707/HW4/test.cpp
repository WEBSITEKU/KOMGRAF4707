#include <GLFW/glfw3.h>
#include <cmath>

void render(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    int X = x1;
    int Y = y1;

    while (true) {
        glBegin(GL_POINTS);
        glVertex2i(X, Y);
        glEnd();
        glFlush();

        if (X == x2 && Y == y2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            X += sx;
        }
        if (e2 < dx) {
            err += dx;
            Y += sy;
        }
    }
}

int main() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "Bresenham OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glOrtho(0, 800, 0, 600, -1, 1);
    int screenWidth = 800;
    int screenHeight = 600;
    int x1 = 4 + screenWidth / 2;
    int y1 = 7 + screenHeight / 2;
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
