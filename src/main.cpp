#include <SDL2/SDL.h>
#include "Game.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Surface* gHelloWorld = NULL;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KeyPressSurfaces::KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;
bool quit = false;
SDL_Event e;

SDL_Surface* loadSurface(std::string path)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}
bool LoadMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "D:/Maker/SDL2Game/vendor/image/press.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        SDL_Log( "Failed to load default image!\n" );
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "D:/Maker/SDL2Game/vendor/image/up.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
    {
        SDL_Log( "Failed to load up image!\n" );
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "D:/Maker/SDL2Game/vendor/image/down.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
    {
        SDL_Log( "Failed to load down image!\n" );
        success = false;
    }

    //Load left surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "D:/Maker/SDL2Game/vendor/image/left.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        SDL_Log( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "D:/Maker/SDL2Game/vendor/image/right.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        SDL_Log( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}

int main(int argc, char** argv) {
    SDL_Log("App start");

    Game* game = new Game();
    SDL_Log("init");
    if(!game->init(gWindow, gScreenSurface))
    {
        SDL_Log("Failed to initialize!\n");
    }
    else
    {
        // Load media
        if(!LoadMedia())
        {
            SDL_Log("Failed to load media!\n");
        }
        else
        {
            SDL_Log("main loop");
            //Set default current surface
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
            while (!quit)
            {
            while (SDL_PollEvent( &e) !=0)
            {
                if(e.type == SDL_QUIT)
                {
                    
                    quit = true;
                }else if(e.type == SDL_KEYDOWN)
                {
                 //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                            SDL_Log("UP");

                            case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                            SDL_Log("DOWN");;

                            case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                            break;

                            case SDLK_RIGHT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                            break;

                            default:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            break;
                        }
                    }
                }

            //apply the image
            SDL_BlitSurface(gHelloWorld, NULL,  gScreenSurface, NULL);
            
            // Update the surface
            SDL_UpdateWindowSurface(gWindow);

            }
        }
            SDL_Log("quit mainloop");
    }
    

    SDL_Log("quitting");
    //Free resources and close SDL
    game->Quit(gWindow, gHelloWorld);

    return 0;
}