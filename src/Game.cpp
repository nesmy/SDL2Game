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

				//Initialise SDL_ttf
				if(TTF_Init() == -1)
				{
					SDL_Log("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
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
		//Handle button events
        for( int i = 0; i < TOTAL_BUTTONS; ++i )
        {
           
			
        }
       
	}
	//Set texture based on current keystate
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	if( currentKeyStates[ SDL_SCANCODE_UP ] )
	{
		currentTexture = &gUpTexture;
	}
	else if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
	{
		currentTexture = &gDownTexture;
	}
	else if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
	{
		currentTexture = &gLeftTexture;
	}
	else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
	{
		currentTexture = &gRightTexture;
	}
	else
	{
		currentTexture = &gPressTexture;
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

	currentTexture->render(0,0,gRenderer);
	
   //Update screen
   SDL_RenderPresent(gRenderer);
}

void Game::Quit()
{
   //Free loaded image
   
   gUpTexture.free();
   
	gDownTexture.free();
 
	gLeftTexture.free();
 
	gRightTexture.free();

	gPressTexture.free();

	currentTexture->free();

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

	//Load sprites
	if( !gUpTexture.loadFromFile( "D:/Maker/SDL2Game/vendor/image/up.png", gRenderer ) )
	{
		SDL_Log( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !gDownTexture.loadFromFile( "D:/Maker/SDL2Game/vendor/image/down.png", gRenderer ) )
	{
		SDL_Log( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !gLeftTexture.loadFromFile( "D:/Maker/SDL2Game/vendor/image/left.png", gRenderer ) )
	{
		SDL_Log( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !gRightTexture.loadFromFile( "D:/Maker/SDL2Game/vendor/image/right.png", gRenderer ) )
	{
		SDL_Log( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !gPressTexture.loadFromFile( "D:/Maker/SDL2Game/vendor/image/press.png", gRenderer ) )
	{
		SDL_Log( "Failed to load button sprite texture!\n" );
		success = false;
	}

	
	return success;
}
