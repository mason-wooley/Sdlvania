#include <math.h>

class Vector2D {
   public:
    // Constructors
    Vector2D();
    Vector2D(float x, float y);

    // Getters
    float getX();
    float getY();

    // Setters
    void setX(float val);
    void setY(float val);

    // Math operations
    float getLength();

   private:
    float x;
    float y;
};