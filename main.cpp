#include <iostream>

// include graphic 
#include <SDL2/SDL.h>
#include "r/infrastructure/graphics/graphics.h"
#include "r/infrastructure/log/logger.h"
#include "engine/sprite.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

using namespace r::infrastructure;

//! \brief HELLO
//! \param argc df
//! \param argv fdsf
//! \return
int main(int argc, char **argv) {

    Log::init(argv[1]);

    /* Declare window and renderer */
    SDL_Window * window;
    SDL_Renderer * renderer;

    /* Initialize SDL */
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("tests",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT,
                              0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Log::info("Entering application.");
    
    /* Main game loop */
    while (!SDL_QuitRequested()) {
        SDL_RenderClear(renderer);

        //
        r_sSprite sprite;
        sprite.x = 10;

        testingComments(sprite.x);

        /* Place your simulation code and rendering code here */
        SDL_RenderPresent(renderer);
    }
    
    Log::info("Exiting application.");
    
    /* Deinitialize everything */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


