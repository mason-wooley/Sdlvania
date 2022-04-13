#include <Player.h>
#include <SDL2/SDL.h>
#include <stdio.h>

#include <vector>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// Start SDL and create the window
bool init();

// Load media objects into the window
bool loadMedia();

// Release media and shut down SDL
void close();

// Globally declare window
SDL_Window *gWindow = NULL;

// The surface contained by the window
SDL_Surface *gScreenSurface = NULL;

// The renderer to draw to
// SDL_Renderer* gRenderer = NULL;

// The image to load to the screen
SDL_Surface *gCharacter = NULL;

int main(int argc, char **args) {
    // Start SDL
    if (init()) {
        // Load media
        if (!loadMedia()) {
            return 1;
        }
    } else {
        return 1;
    }

    bool running = true;

    // The rectangle defining the character position
    SDL_Rect *rect = new SDL_Rect();

    rect->x = SCREEN_WIDTH / 2 - gCharacter->w / 2;
    rect->y = SCREEN_HEIGHT / 2 - gCharacter->h / 2;

    int moveDirectionX = 0;
    int moveSpeed = 2;

    // Keyboard input
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    const Uint8 *prevState = state;

    // Game loop
    while (running) {
        // Get current keyboard state
        state = SDL_GetKeyboardState(NULL);

        SDL_Event event;

        // Poll the event queue if events are queued
        // Handle events on queue
        while (SDL_PollEvent(&event) != 0) {
            // User requests quit
            if (event.type == SDL_QUIT) {
                running = false;
                close();
                break;
            }
        }

        // Get X direction movement
        if (state[SDL_SCANCODE_RIGHT]) {
            moveDirectionX = 1;
        } else if (state[SDL_SCANCODE_LEFT]) {
            moveDirectionX = -1;
        } else {
            moveDirectionX = 0;
        }

        // Apply X direction movement
        rect->x += moveSpeed * moveDirectionX;

        // Clear the screen to black
        SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0x00, 0x00, 0x00));

        // Apply the image
        SDL_BlitSurface(gCharacter, NULL, gScreenSurface, rect);

        // Update the surface
        SDL_UpdateWindowSurface(gWindow);

        /*
        // Set the render color to cyan
        SDL_SetRenderDrawColor(gRenderer, 0, 255, 255, 255);

        // Clear the screen of existing data and draw the render color
        SDL_RenderClear(gRenderer);

        // Update the screen with the drawn render data
        SDL_RenderPresent(gRenderer);
        */

        prevState = state;
    }

    return 0;
}

bool init() {
    // Initialization status
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        success = false;
    } else {
        // Create a window and store the reference to it
        gWindow = SDL_CreateWindow("Sdlvania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

        // Fail if the window isn't created
        if (gWindow == NULL) {
            printf("Error: Failed to open window.\nSDL Error: '%s'\n", SDL_GetError());
            success = false;
        } else {
            // Get the screen surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }

        // Create a renderer and store the reference to it
        // gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

        // Fail if the renderer isn't created
        /*
        if ( !gRenderer ) {
            printf("Error: Failed to create renderer\nSDL Error: '%s'\n",
        SDL_GetError()); return 1;
        }
        */
    }
}

bool loadMedia() {
    // Load media status
    bool success = true;

    // Load character image
    gCharacter = SDL_LoadBMP("media/character.bmp");

    if (gCharacter == NULL) {
        printf("Error: Failed to load image '%s'.\nSDL Error: '%s'\n", "media/character.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close() {
    // Deallocate surface
    SDL_FreeSurface(gCharacter);
    gCharacter = NULL;

    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Quit SDL
    SDL_Quit();
}
