#include <SDL2/SDL.h>
#include <Vector2D.h>

#include <string>

class Player {
   public:
    // Constructors
    Player();

    // Operations
    void setTexture(std::string path);
    void updatePosition(float x, float y);

    SDL_Texture *getTexture();

   private:
    Vector2D position;
    SDL_Texture *texture;
    SDL_Rect *rect;
};