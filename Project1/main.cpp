#include <math.h>
#include <iostream>
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )


#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480

SDL_Event event;



	int main(int argc, char** argv) {

		SDL_Window* Window;
		SDL_Renderer* Renderer;
		SDL_Event event;
		int quit = 0;


			//Init
				if (SDL_Init(SDL_INIT_VIDEO) != 0) {
					SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
					return -1;
				}
			//Load
				Window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
				if (Window == NULL)
				{
					SDL_Log("Unable to create window: %s", SDL_GetError());
					return -1;
				}
			//Loop
				Renderer = SDL_CreateRenderer(Window, -1, 0);
				if (Renderer == NULL)
				{
					SDL_Log("Unable to create rendering context: %s", SDL_GetError());
					return -1;
				}

				SDL_SetRenderDrawColor(Renderer, 0, 0, 255, 255);

				SDL_RenderClear(Renderer);

				SDL_Rect rect = { 250, 175, 100, 100 };

				SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(Renderer, &rect);



				SDL_RenderPresent(Renderer);



				while (!quit) {

					while (SDL_PollEvent(&event)) {
						switch (event.type) {
						case SDL_KEYDOWN:
							break;
						case SDLK_ESCAPE:

							quit = 1;
							break;
						}
					}
				}
				
		return 0;
	}
