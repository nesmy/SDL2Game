#pragma once

#include <SDL2\SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cmath>
#include "LTexture.h"
#include "LButton.h"

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
    LTexture gPromptTextTexture;
    TTF_Font* gFont;
    Uint32 startTime = 0;
    std::stringstream timeText;
    SDL_Color textColor = { 0,0,0,255};
    LTexture gTimeTextTexture;
    
    
    bool success;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    //The image we will load and show on the screen
    
};
