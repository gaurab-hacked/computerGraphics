#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void drawLine(int x0, int y0, int x1, int y1) {
    int dx, dy, p, x, y;

    // Calculate differences and initialize variables
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;

    // Plot the initial point
    putpixel(x, y, WHITE);

    // Iterate through each point and plot them
    while (x < x1) {
        if (p >= 0) {
            y += 1;
            p += 2 * dy - 2 * dx;
        } else {
            p += 2 * dy;
        }
        x += 1;
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int x0, y0, x1, y1;

    printf("Enter coordinates of the line: ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    initgraph(&gd, &gm, "");

    drawLine(x0, y0, x1, y1);

    delay(5000); // Delay for 5 seconds
    closegraph();
    return 0;
}

