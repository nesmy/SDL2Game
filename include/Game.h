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
    LTexture gFooTexture;
    LTexture gBackgroundtextures;
    
    
    bool success;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    //The image we will load and show on the screen
    
};
    //Key press surfaces constants
    enum KeyPressSurfaces
    {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
    };