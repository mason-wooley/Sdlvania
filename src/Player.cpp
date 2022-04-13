#include <Player.h>

Player::Player() {
    texture = NULL;
    rect->w = 0;
    rect->h = 0;
}

void Player::setTexture(std::string path) { SDL_Surface* loadedSurface = IMG_Load(path.c_str()) }

void Player::updatePosition(float x, float y) {
    position.setX(x);
    position.setY(y);
}

SDL_Texture* Player::getTexture() { return texture; }