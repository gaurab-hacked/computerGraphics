#include <graphics.h>
#include <stdio.h>

// Function to draw a triangle and its reflection about the x-axis
void drawAndReflectTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
    // Draw the original triangle
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x0, y0);

    // Draw the reflected triangle about the x-axis
    line(x0, 480 - y0, x1, 480 - y1);
    line(x1, 480 - y1, x2, 480 - y2);
    line(x2, 480 - y2, x0, 480 - y0);
}

int main() {
    int gd = DETECT, gm;
    int x0, y0, x1, y1, x2, y2;

    printf("Enter coordinates of the triangle (x0 y0 x1 y1 x2 y2): ");
    scanf("%d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2);

    // Initialize graphics
    initgraph(&gd, &gm, "");

    // Set the window size
    setviewport(0, 0, 640, 480, 1);

    // Draw the original triangle and its reflection about the x-axis
    drawAndReflectTriangle(x0, y0, x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}

