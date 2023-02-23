#include "Game.h"


int main(int argc, char** argv)
{
    Game* game = new Game();

    bool quit = false;
    SDL_Event e;
    SDL_Log("Init");
    game->init();
    while(!quit)
    {
        SDL_Log("Event");
        game->Event(e, quit);
        SDL_Log("Update");
        game->Update();
        SDL_Log("Render");
        game->Render();
    }
    SDL_Log("Quit");
    game->Quit();

    return 0;
}