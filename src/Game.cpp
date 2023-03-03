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
				//Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					SDL_Log( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
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
		else if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
		{
			startTime = SDL_GetTicks();
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
   //Set text to be rendered
   timeText.str("");
   timeText << "Milliseconds since start time" << SDL_GetTicks() - startTime;

   //Render text
   if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor, gRenderer, gFont ) )
	{
		SDL_Log( "Unable to render time texture!\n" );
	}
   //Clear screen
   SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
   SDL_RenderClear(gRenderer);

	//Render textures
	gPromptTextTexture.render( ( SCREEN_WIDTH - gPromptTextTexture.getWidth() ) / 2, 0 , gRenderer);
	gTimeTextTexture.render( ( SCREEN_WIDTH - gPromptTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gPromptTextTexture.getHeight() ) / 2 , gRenderer);
	
   //Update screen
   SDL_RenderPresent(gRenderer);
}

void Game::Quit()
{
    //Free loaded images
    gPromptTextTexture.free();
   

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

	//Open the font
	gFont = TTF_OpenFont("D:/Maker/SDL2Game/assets/lazy.ttf", 28);
	if(gFont == NULL)
	{
		SDL_Log("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else{

		//Set text color as black
		SDL_Color textColor = { 0,0,0,255};

		//Load prompt texture
		if( !gPromptTextTexture.loadFromRenderedText( "Please Enter to reset start time.", textColor, gRenderer, gFont ) )
		{
			SDL_Log( "Failed to load prompt texture!\n" );
			success = false;
		}

	}
	

	
	return success;
}
