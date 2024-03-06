#include <graphics.h>
#include <stdio.h>

// Function to draw a triangle
void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x0, y0);
}

// Function to translate a triangle by (dx, dy)
void translateTriangle(int *x0, int *y0, int *x1, int *y1, int *x2, int *y2, int dx, int dy) {
    *x0 += dx;
    *y0 += dy;
    *x1 += dx;
    *y1 += dy;
    *x2 += dx;
    *y2 += dy;
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

    // Draw the original triangle
    drawTriangle(x0, y0, x1, y1, x2, y2);

    // Translate the triangle by (2, 3)
    translateTriangle(&x0, &y0, &x1, &y1, &x2, &y2, 2, 3);

    // Draw the translated triangle
    drawTriangle(x0, y0, x1, y1, x2, y2);

    delay(5000); // Delay for 5 seconds
    closegraph();
    return 0;
}

