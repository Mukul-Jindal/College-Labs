#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
int X1, Y1, X2, Y2;
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
void print(int a, int b)
{
    printf(" (%d, %d)\n", a, b);
}
void linedda(int X1, int Y1, int X2, int Y2)
{
    float dy, dx, step, x, y, k, Xin, Yin;
    dx = X2 - X1;
    dy = Y2 - Y1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;

    x = X1;
    y = Y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (k = 1; k <= step; k++)
    {
        x = x + Xin;
        y = y + Yin;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        print(x, y);
    }
}
void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void bres_general(int x1, int y1, int x2, int y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (x2 < x1)
        incx = -1;
    incy = 1;
    if (y2 < y1)
        incy = -1;
    x = x1;
    y = y1;
    if (dx > dy)
    {
        draw_pixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            printf("%d\t%d\t", i, e);

            if (e >= 0)
            {
                y += incy;
                x += incx;
                e += inc1;
            }
            else
            {
                e += inc2;
                x += incx;
            }
            printf("%d\t%d\n", x, y);

            draw_pixel(x, y);
        }
    }
    else
    {
        draw_pixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            printf("%d\t%d\t", i, e);
            if (e >= 0)
            {
                x += incx;
                e += inc1;
                y += incy;
            }
            else
            {
                e += inc2;
                y += incy;
            }
            printf("%d\t%d\n", x, y);
            draw_pixel(x, y);
        }
    }
}
void draw1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(100, 100);
    glVertex2i(120, 100);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(100, 100);
    glVertex2i(100, 200);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(120, 100);
    glVertex2i(120, 180);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(120, 180);
    glVertex2i(170, 180);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(170, 180);
    glVertex2i(170, 200);
    glEnd();
    glFlush();
}
void draw(void)
{
    printf("x\tpk\tx(k+1)\ty(k+1)\n");
    glColor3f(0.0, 1.0, 0.0);
    // bres_general(20, 10, 30, 18);
    bres_general(100, 90, 200, 90);
    bres_general(100, 90, 150, 190);
    bres_general(200, 90, 150, 190);

    bres_general(100, 150, 200, 150);
    bres_general(100, 150, 150, 50);
    bres_general(200, 150, 150, 50);
    glFlush();
}
void draw2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(100, 100);
    glVertex2i(120, 100);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(100, 100);
    glVertex2i(100, 200);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(120, 100);
    glVertex2i(120, 180);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(120, 180);
    glVertex2i(170, 180);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(170, 180);
    glVertex2i(170, 200);
    glEnd();
    glFlush();
}

void draw3(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    linedda(100, 100, 120, 100);
    linedda(100, 100, 100, 200);
    linedda(120, 100, 120, 180);
    linedda(120, 180, 170, 180);
    linedda(100, 200, 170, 200);
    linedda(170, 180, 170, 200);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // glutInitWindowSize(600, 600);
    // glutInitWindowPosition(100, 100);
    // glutCreateWindow(" Line Drawing using Inbuit Line Function");
    // myInit();
    // glutDisplayFunc(draw2);

    // glutInitWindowSize(200, 200);
    // glutInitWindowPosition(100, 100);
    // glutCreateWindow("Using DDA Line Drawing");
    // myInit();
    // glutDisplayFunc(draw3);

    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
