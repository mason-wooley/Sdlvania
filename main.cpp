#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

int main (int argc, char** argv) {
    // Exit the program if SDL fails to initialize
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    // Create a window and store the reference to it
    SDL_Window *window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    // Exit if the window fails to create
    if (!window) {
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    // Create a renderer and store the reference to it
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Exit if the renderer fails to create
    if (!renderer) {
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    bool running = true;

    // Game loop 
    while (running) {

        SDL_Event event;

        // Poll the event queue if events are queued
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    // Break the game loop on next iteration
                    running = false;
                    break;

                default:
                    break;
            }
        }

        // Set the render color to cyan
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        
        // Clear the screen of existing data and draw the render color
        SDL_RenderClear(renderer);

        // Update the screen with the drawn render data
        SDL_RenderPresent(renderer);
    }

    return 0;
}