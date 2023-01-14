#include <stdio.h>
#include <stdbool.h>
#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>

// SDL Variables
int window_w = 512;
int window_h = 512;

int main(int argc, char *argv[])
{
    // Init SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Could not init SDL: %s\n", SDL_GetError() );
        exit(1);
    }

    // Creates SDL Window
    SDL_Window *window = SDL_CreateWindow(
        "Hello SDL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        window_w, window_h, SDL_WINDOW_OPENGL 
    );

    // Check if window failed to create
    if ( !window ) 
    {
        printf( "Failed to init window: %s\n", SDL_GetError() );
        exit(1);
    }

    // We must call SDL_CreateRenderer in order for draw calls to affect this window.
    SDL_Renderer* renderer;
    renderer = SDL_CreateRenderer(window, -1, 0);

    // Select the color for drawing. It is set to red here.
    SDL_SetRenderDrawColor(renderer, 54, 130, 151, 255);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(renderer);

    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    SDL_RenderPresent(renderer);

    // Update Loop
    bool running = true;
    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            else
            {
                // Game Loop
            }
        }
    }

}