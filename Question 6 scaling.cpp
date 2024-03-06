#include <graphics.h>
#include <stdio.h>

// Function to draw a triangle
void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x0, y0);
}

// Function to scale a triangle
void scaleTriangle(int *x0, int *y0, int *x1, int *y1, int *x2, int *y2, float sx, float sy) {
    *x0 *= sx;
    *y0 *= sy;
    *x1 *= sx;
    *y1 *= sy;
    *x2 *= sx;
    *y2 *= sy;
}

int main() {
    int gd = DETECT, gm;
    int x0, y0, x1, y1, x2, y2;
    float sx, sy;

    printf("Enter coordinates of the triangle (x0 y0 x1 y1 x2 y2): ");
    scanf("%d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2);

    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    // Initialize graphics
    initgraph(&gd, &gm, "");

    // Set the window size
    setviewport(0, 0, 640, 480, 1);

    // Draw the original triangle
    drawTriangle(x0, y0, x1, y1, x2, y2);

    // Scale the triangle
    scaleTriangle(&x0, &y0, &x1, &y1, &x2, &y2, sx, sy);

    // Draw the scaled triangle
    drawTriangle(x0, y0, x1, y1, x2, y2);

    delay(5000); // Delay for 5 seconds
    closegraph();
    return 0;
}

