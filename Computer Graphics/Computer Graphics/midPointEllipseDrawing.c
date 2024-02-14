#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
// inline int round(const float a) { return (a + 0.5); }
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}
void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{

    draw_pixel(xCenter + x, yCenter + y);
    draw_pixel(xCenter - x, yCenter + y);
    draw_pixel(xCenter + x, yCenter - y);
    draw_pixel(xCenter - x, yCenter - y);
}
void ellipseMidPoint(int xCenter, int yCenter, int Rx, int Ry)
{
    int k = 0;
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;
    int ptemp;

    ellipsePlotPoints(xCenter, yCenter, x, y);

    // Region 1
    p = round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while (px < py)
    {
        k++;
        px += twoRy2;
        x++;
        ptemp=p;
        if (p < 0)
        {
            p += Ry2 + px;
        }
        else
        {
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
        printf("%d\t%d\t(%d,%d)\t%d\t%d\n", k-1, ptemp, x, y, px, py);
    }

    // Region 2
    p = round(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
    while (y > 0)
    {
        k++;
        py -= twoRx2;
        y--;
        ptemp = p;
        if (p > 0)
        {
            p += Rx2 - py;
        }
        else
        {
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        printf("%d\t%d\t(%d,%d)\t%d\t%d\n", k-1, ptemp, x, y, px, py);
        ellipsePlotPoints(xCenter, yCenter, x, y);
        // k++;
    }
}

void draw()
{

    printf("k\tpk\t(x,y)\t2r^2x\t2r^2y\n");
    glColor3f(0.0, 1.0, 0.0);
    ellipseMidPoint(0, 0, 8, 6);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Ellipse drawing code");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}