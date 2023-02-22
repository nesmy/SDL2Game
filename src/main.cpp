#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Surface* gScreenSurface = NULL;
SDL_Window* gWindow = NULL;
SDL_Surface* gStretchedSurface = NULL;

SDL_Surface* loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		SDL_Log( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	else
	{
		//Convert surface to screen format
		//optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
        SDL_Log("loadSurface");
		//if( optimizedSurface == NULL )
		//{
			//SDL_Log( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		//}

		//Get rid of old loaded surface
		//SDL_FreeSurface( loadedSurface );
	}

	return loadedSurface;
}
bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load stretching surface
	gStretchedSurface = loadSurface( "D:/Maker/SDL2Game/vendor/image/pngfile.png" );
    SDL_Log("load start");
	if( gStretchedSurface == NULL )
	{
		SDL_Log( "Failed to load stretching image!\n" );
		success = false;
	}
    SDL_Log("Success");
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
        SDL_Log("Load media");
        // Load media
        if(!loadMedia())
        {
            SDL_Log("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;

            SDL_Log("main loop");
            //Set default current surface
            //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
            while (!quit)
            {
                
                //Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
                   
				}

                SDL_BlitSurface(gStretchedSurface, NULL,  gScreenSurface, NULL);
            
            // Update the surface
            SDL_UpdateWindowSurface(gWindow);

            }
        }
        SDL_Log("quit mainloop");
    }
    

    SDL_Log("quitting");
    //Free resources and close SDL
    game->Quit(gWindow, gStretchedSurface);

    return 0;
}