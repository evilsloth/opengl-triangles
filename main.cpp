#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include "triangle.h"
#include "main.h"

#define ROTATION_SPEED 0.05f
#define FLY_SPEED ROTATION_SPEED / 10.0f * 3.0f / 360.0f

std::list<Triangle> triangles;

void addTriangle(float x, float y, Color color)
{
    Triangle triangle(x, y, color);
    triangle.setRotationSpeed(-ROTATION_SPEED * 3.0f);
    triangle.setFlySpeed(FLY_SPEED);
    triangles.push_front(triangle);
}

void prepareTrianglesSection()
{
    addTriangle(-1.0f, 1.0f, {0.0f, 0.0f, 1.0f});
    addTriangle(-3.0f, 1.0f, {0.0f, 1.0f, 0.0f});
    addTriangle(-5.0f, 1.0f, {1.0f, 0.0f, 0.0f});
    addTriangle(-1.0f, 3.0f, {1.0f, 0.5f, 0.0f});
    addTriangle(-1.0f, 5.0f, {1.0f, 0.0f, 1.0f});
    addTriangle(-3.0f, 3.0f, {1.0f, 1.0f, 0.0f});
}

void drawAllTriangles(float time)
{
    for (Triangle triangle : triangles)
    {
        triangle.draw(time);
    }
}

int main(int argc, char **argv)
{
    prepareTrianglesSection();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(keySpecial);
    glutSpecialUpFunc(keySpecialUp);
    glutMainLoop();
}

void display(void)
{
    float time = glutGet(GLUT_ELAPSED_TIME);

    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -15.0f);

    glPushMatrix();
    glRotatef(ROTATION_SPEED * time, 0.0f, 0.0f, 1.0f);

    for (int i = 0; i <= 270; i += 90)
    {
        glRotatef(i, 0.0f, 0.0f, 1.0f);
        drawAllTriangles(time);
    }

    glPopMatrix();

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyPressed(unsigned char key, int x, int y)
{
}

void keyUp(unsigned char key, int x, int y)
{
}

void keySpecial(int key, int x, int y)
{
}

void keySpecialUp(int key, int x, int y)
{
}
