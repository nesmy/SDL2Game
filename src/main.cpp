#include <SDL2/SDL.h>
#include "Game.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Surface* gHelloWorld = NULL;
SDL_Window* window;
SDL_Surface* screenSurface;

int main(int argc, char** argv) {

    Game* game = new Game();

    if(!game->init(window, screenSurface))
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        // Load media
        if(!game->LoadMedia(gHelloWorld))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            //apply the image
            SDL_BlitSurface(gHelloWorld, NULL,  screenSurface, NULL);

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // Hack to get window to stay up
             SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }


    //Free resources and close SDL
    game->Quit(window, gHelloWorld);

    return 0;
}