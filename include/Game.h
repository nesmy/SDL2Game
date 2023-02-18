#pragma once

#include <SDL2\SDL.h>
#include <stdio.h>

class Game
{
    public:
    Game();
    ~Game();

    bool init(SDL_Window* window, SDL_Surface* screenSurface);
    bool LoadMedia(SDL_Surface* gHelloWorld);
    void Event();
    void Update();
    void Render();
    void Quit(SDL_Window* window, SDL_Surface* gHelloWorld);

    private:
    
    
    bool success;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    //The image we will load and show on the screen
    
    
};