#pragma once

#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

#include "Entity.h"

#define WINDOW_WIDTH	1024
#define WINDOW_HEIGHT	768
#define MAX_KEYS		256
#define MAX_SHOTS		32
#define PLAYER_WIDTH	104
#define PLAYER_HEIGHT	82
#define PROJ_WIDTH		56
#define PROJ_HEIGHT		20

class Game
{
public:
	Game();
	~Game();

	bool Init();
	void Release();
	
	bool Input();
	bool Update();
	void Draw();

private:
	SDL_Window *Window;
	SDL_Renderer *Renderer;
	SDL_Surface *Surface;
	SDL_Texture *Texture_Spaceship;
	SDL_Texture *Texture_Shot;
	SDL_Texture *Texture_Background;

	Entity Player, Shots[MAX_SHOTS], Background;
	int idx_shot;
	int png_flag = IMG_INIT_PNG;

	enum KEY_STATE { KEY_IDLE, KEY_DOWN, KEY_REPEAT, KEY_UP	};
	KEY_STATE keys[MAX_KEYS]; 
};
