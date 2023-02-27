#pragma once

#include <SDL2\SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"

class Game
{
    public:
    Game();
    ~Game();

    bool init();
    
    void Event(SDL_Event e);
    void Update();
    void Render();
    void Quit();
    bool loadMedia();
    bool Close = false;

    private:
    SDL_Window* window;
    SDL_Renderer* gRenderer;
    LTexture gArrawTexture;

    double degrees = 0;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    
    
    bool success;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    //The image we will load and show on the screen
    
};
