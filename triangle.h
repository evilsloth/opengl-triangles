#pragma once
#include <GL/glut.h>
#include <math.h> 

struct Color
{
    float r;
    float g;
    float b;
};

class Triangle
{
    float x;
    float y;
    Color color;
    float rotateSpeed;
    float flySpeed;
    float directionX;
    float directionY;

  public:
    Triangle(float x, float y, Color color);
    void draw(float time);
    void setRotationSpeed(float rotateSpeed);
    void setFlySpeed(float flySpeed);
};