#pragma once

#include <SDL2\SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
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
    TTF_Font* gFont = NULL;
    LButton gButtons[TOTAL_BUTTONS];
    //Mouse button sprites
    SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
    LTexture gButtonSpriteSheetTexture;
    
    
    bool success;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    //The image we will load and show on the screen
    
};
