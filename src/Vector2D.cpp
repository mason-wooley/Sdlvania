#include <Vector2D.h>

Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
}

float Vector2D::getX() { return x; }

float Vector2D::getY() { return y; }

void Vector2D::setX(float val) { x = val; }

void Vector2D::setY(float val) { y = val; }

float Vector2D::getLength() { return sqrt(x * x + y * y); }
