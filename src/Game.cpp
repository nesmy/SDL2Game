#include "Game.h"

Game::Game()
{}
Game::~Game()
{}

bool Game::init(SDL_Window* window, SDL_Surface* screenSurface)
{
    bool success = true;

     //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
        }
    }

    return success;
}

bool Game::LoadMedia(SDL_Surface* gHelloWorld)
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP("vendor/image/hello_world.bmp");
    if(gHelloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "vendor/image/hello_world.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void Game::Event()
{
}

void Game::Update()
{
}

void Game::Render()
{
}

void Game::Quit(SDL_Window* window, SDL_Surface* gHelloWorld)
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
