#include <graphics.h>
#include <stdio.h>

// Function to draw eight-way symmetric points
void drawSymmetricPoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

// Function to draw a circle using Midpoint Circle Drawing Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    drawSymmetricPoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawSymmetricPoints(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;

    printf("Enter center coordinates of the circle (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius of the circle: ");
    scanf("%d", &r);

    // Initialize graphics
    initgraph(&gd, &gm, "");

    // Draw the circle
    drawCircle(xc, yc, r);

    delay(5000); // Delay for 5 seconds
    closegraph();
    return 0;
}

