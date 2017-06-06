#include "triangle.h"

Triangle::Triangle(float x, float y, Color color)
{
    this->x = x;
    this->y = y;
    this->color = color;

    float directionVectorLength = sqrt(x*x + y*y);
    directionX = x / directionVectorLength;
    directionY = y / directionVectorLength;
}

void Triangle::draw(float time)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glTranslatef(directionX * time * flySpeed, directionY * time * flySpeed, 0.0f);
    glRotatef(rotateSpeed * time, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(color.r, color.g, color.b);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glEnd();

    glPopMatrix();
}

void Triangle::setRotationSpeed(float rotateSpeed)
{
    this->rotateSpeed = rotateSpeed;
}

void Triangle::setFlySpeed(float flySpeed)
{
    this->flySpeed = flySpeed;
}