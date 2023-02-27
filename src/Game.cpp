#include "Game.h"

Game::Game()
{}
Game::~Game()
{}

bool Game::init()
{
   //Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		SDL_Log( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			SDL_Log( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void Game::Event(SDL_Event e)
{
    //Handle events on queue
	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			SDL_Log("Event");
			Close = true;
		}
		//On keypress change rgb values
		else if(e.type == SDL_KEYDOWN){
			
			
		}
       
	}
}

void Game::Update()
{
    // Load media
     if(!loadMedia())
     {
         SDL_Log("Failed to load media!\n");
     }
}

void Game::Render()
{
   //Clear screen
   SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
   SDL_RenderClear(gRenderer);

	//Render current farme
	SDL_Rect* currentClip = &gSpriteClips[frame / 4];
	gSpriteSheetTexture.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, gRenderer ,currentClip);

   //Update screen
   SDL_RenderPresent(gRenderer);

   //Go to next frame
   ++frame;

   //Cycle animation
   if( frame / 4 >= WALKING_ANIMATION_FRAMES)
   {
	frame = 0;
   }
}

void Game::Quit()
{
   //Free loaded image
   gSpriteSheetTexture.free();

   //Destroy window
   SDL_DestroyRenderer(gRenderer);
   SDL_DestroyWindow(window);
   window = NULL;
   gRenderer = NULL;

   //Quit SDL subsystems
   IMG_Quit();
   SDL_Quit();
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if(!gSpriteSheetTexture.loadFromFile("D:/Maker/SDL2Game/vendor/image/foo.png", gRenderer))
	{
		SDL_Log("Failed to load sprite sheet texture!\n");
		success = false;
	}
	else
    {
        //Set sprite clips
        gSpriteClips[ 0 ].x =   0;
        gSpriteClips[ 0 ].y =   0;
        gSpriteClips[ 0 ].w =  64;
        gSpriteClips[ 0 ].h = 205;

        gSpriteClips[ 1 ].x =  64;
        gSpriteClips[ 1 ].y =   0;
        gSpriteClips[ 1 ].w =  64;
        gSpriteClips[ 1 ].h = 205;
        
        gSpriteClips[ 2 ].x = 128;
        gSpriteClips[ 2 ].y =   0;
        gSpriteClips[ 2 ].w =  64;
        gSpriteClips[ 2 ].h = 205;

        gSpriteClips[ 3 ].x = 192;
        gSpriteClips[ 3 ].y =   0;
        gSpriteClips[ 3 ].w =  64;
        gSpriteClips[ 3 ].h = 205;
    }
    
	
	return success;
}
