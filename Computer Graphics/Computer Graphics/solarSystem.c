#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300, 300, -300, 300);
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
        draw_pixel(x + p, -y - q);
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

void ellipseMidPoint(int xCenter, int yCenter, int Rx, int Ry)
{
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;

    ellipsePlotPoints(xCenter, yCenter, x, y);

    // Region 1
    p = round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while (px < py)
    {
        x++;
        px += twoRy2;
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
    }

    // Region 2
    p = round(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
    while (y > 0)
    {
        y--;
        py -= twoRx2;
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
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }
}

void draw()
{
    //orbits
    glColor3f(0.0, 1.0, 1.0);
    ellipseMidPoint(0, 0, 50, 30);//1
    ellipseMidPoint(0, 0, 70, 50);//2
    ellipseMidPoint(0, 0, 90, 70);//3
    ellipseMidPoint(0, 0, 110, 90);//4
    ellipseMidPoint(0, 0, 130, 110);//5
    ellipseMidPoint(0, 0, 150, 130);//6
    ellipseMidPoint(0, 0, 170, 150);//7
    ellipseMidPoint(0, 0, 190, 170);//8

    //Planets

    //1. Sun
    glColor3f(1.0, 1.0, 0.0);
    bresenhamCircleDraw(0,0,20);
    //2. Mercur
    glColor3f(1.0, 0.0, 0.0);
    bresenhamCircleDraw(50,0,8);
    //3. Venus
    glColor3f(0.0, 0.0, 1.0);
    bresenhamCircleDraw(-70,0,9);
    //4. Earth
    glColor3f(0.0, 1.0, 0.0);
    bresenhamCircleDraw(90,0,10);

    //5. Mars
    glColor3f(1.0, 0.0, 1.0);
    bresenhamCircleDraw(-110,0,8);
    //6. Jupiter
    glColor3f(1.0, 1.0, 1.0);
    bresenhamCircleDraw(130,0,8);
    //7. Saturan
    glColor3f(1.0, 1.0, 0.0);
    bresenhamCircleDraw(-150,0,8);
    //8. Uranus
    glColor3f(1.0, 1.0, 0.0);
    bresenhamCircleDraw(170,0,8);
    //9. Neptune
    glColor3f(1.0, 1.0, 0.0);
    bresenhamCircleDraw(-190,0,8);

    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Ellipse drawing code");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}