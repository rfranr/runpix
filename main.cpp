#include <iostream>

// include graphic 
#include <SDL2/SDL.h>

// include log4
#include "r/infrastructure/log/logger.h"
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"

// include ...
#include "engine/sprite.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

using namespace log4cxx;
using namespace log4cxx::helpers;
 
LoggerPtr logger(Logger::getLogger("runpix"));


int main(int argc, char **argv) {

    if (argc > 1)
    {
        // BasicConfigurator replaced with PropertyConfigurator.
        PropertyConfigurator::configure(argv[1]);
    }
    else
    {
        BasicConfigurator::configure();
    }

    std::cout << "Hello, World!" << std::endl;

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

    LOG4CXX_INFO(logger, "Entering application.")
    /* Main game loop */
    while (!SDL_QuitRequested()) {
        SDL_RenderClear(renderer);

        //
        r_sSprite sprite;
        sprite.x = 10;

        //testingComments(sprite.x);

        /* Place your simulation code and rendering code here */
        SDL_RenderPresent(renderer);
    }
    LOG4CXX_INFO(logger, "Exiting application.")
    
    /* Deinitialize everything */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

    return 0;
}


