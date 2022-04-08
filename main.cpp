#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

// Start SDL and create the window
bool init();

// Load media objects into the window
bool loadMedia();

// Release media and shut down SDL
void close();

// Globally declare window
SDL_Window* gWindow = NULL;

// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// The renderer to draw to
// SDL_Renderer* gRenderer = NULL;

// The image to load to the scren
SDL_Surface* gCharacter = NULL;

int main (int argc, char** argv) {

    init();





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

bool init() {
    // Initialization status
    bool success = true;

    // Initialize SDL
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        success = false;
    } else {
        // Create a window and store the reference to it
        gWindow = SDL_CreateWindow("Sdlvania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        
        // Fail if the window isn't created
        if ( gWindow == NULL ) {
            printf("Error: Failed to open window.\nSDL Error: '%s'\n", SDL_GetError());
            success = false;
        } else {
            // Get the screen surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }

        // Create a renderer and store the reference to it
        // gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

        // Fail if the renderer isn't created
        /*
        if ( !gRenderer ) {
            printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
            return 1;
        }
        */
    }
}