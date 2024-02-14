#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}
void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void plotCirclePoints(int p, int q, int x, int y)
{
    draw_pixel(x + p, y + q);
    draw_pixel(y + p, x + q);
    draw_pixel(-y + p, x + q);
    draw_pixel(-x + p, y + q);
    draw_pixel(-x + p, -y + q);
    draw_pixel(-y + p, -x + q);
    draw_pixel(y + p, -x + q);
    draw_pixel(x + p, -y + q);
}
void bresenhamCircleDraw(int p, int q, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    while (x <= y)
    {
        draw_pixel(x + p, y + q);
        draw_pixel(y + p, x + q);
        draw_pixel(-y + p, x + q);
        draw_pixel(-x + p, y + q);
        draw_pixel(-x + p, -y + q);
        draw_pixel(-y + p, -x + q);
        draw_pixel(y + p, -x + q);
        draw_pixel(x + p, -y + q);
        if (d < 0)
        {
            d = d + 4 * x + 6;
            x = x + 1;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            x = x + 1;
            y = y - 1;
        }
    }
}

void midPointCircle(int p, int q, int r)
{
    int x = 0;
    int y = r;
    int d = 1 - r;
    plotCirclePoints(p, q, x, y);
    while (x < y)
    {
        x++;
        if (d < 0)
        {
            d += 2 * x + 1;
        }
        else
        {
            y--;
            d += 2 * (x - y) + 1;
        }
        plotCirclePoints(p, q, x, y);
    }
}

void draw()
{
    glColor3f(0.0, 1.0, 0.0);
    bresenhamCircleDraw(0, 0, 100);
    bresenhamCircleDraw(0, 0, 150);
    bresenhamCircleDraw(0, 0, 180);
    bresenhamCircleDraw(0, 0, 220);
    glColor3f(1.0, 0.0, 0.0);
    bresenhamCircleDraw(0, 170, 200);
    bresenhamCircleDraw(0, -170, 200);
    bresenhamCircleDraw(170, 0, 200);
    bresenhamCircleDraw(-170, 0, 200);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Circle Drawing");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}