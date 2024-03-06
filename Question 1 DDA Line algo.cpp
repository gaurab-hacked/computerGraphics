#include <stdio.h>
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    float xIncrement, yIncrement;
    float x = x1, y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = (float)dx / (float)steps;
    yIncrement = (float)dy / (float)steps;

    for (int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += xIncrement;
        y += yIncrement;
    }

    delay(5000);
    closegraph();
}

int main() {
    int x1, y1, x2, y2;

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLine(x1, y1, x2, y2);

    return 0;
}

