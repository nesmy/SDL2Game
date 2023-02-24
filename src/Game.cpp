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
			gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
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

   //Render background texture to screen
   gBackgroundtextures.render(0,0, gRenderer);

   //Render Foo' to the screen
   gFooTexture.render(640 / 2,480 / 2, gRenderer);

   //Update screen
   SDL_RenderPresent(gRenderer);
}

void Game::Quit()
{
   //Free loaded image
   gFooTexture.free();
   gBackgroundtextures.free();

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

	//Load Foo textute
	if(!gFooTexture.loadFromFile("D:/Maker/SDL2Game/vendor/image/foo.png", gRenderer))
	{
		SDL_Log("Failed to load Foo' texture image!\n");
		success = false;
	}

	//Load Background texture
	if(!gBackgroundtextures.loadFromFile("D:/Maker/SDL2Game/vendor/image/background.png", gRenderer))
	{
		SDL_Log("Failed to load background texture image!\n");
		success = false;
	}

	return success;
}
