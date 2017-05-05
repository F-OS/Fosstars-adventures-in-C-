#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
SDL_Surface* buffer;
SDL_Window* Window;
SDL_Renderer* Render;
SDL_Rect rectangle;
SDL_Rect rectangle1;
int positionx = 50;
int positiony = 50;
int sizex = 800;
int sizey = 800;
int cyan [4] = {0, 255, 255, 255};
int grey [4] = {50, 50, 50, 100};
bool loop = true;
int main()
{
	rectangle.x = 20;
	rectangle.y = 300;
	rectangle.w = 30;
	rectangle.h = 200;
	rectangle1.x = 755;
	rectangle1.y = 300;
	rectangle1.w = 30;
	rectangle1.h = 200;
	SDL_InitSubSystem(SDL_INIT_EVERYTHING);
	Window = SDL_CreateWindow("Test", positionx, positiony, sizex, sizey, SDL_WINDOW_OPENGL);
	Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(Render, sizex, sizey);
	SDL_RenderClear(Render);
	SDL_RenderFillRect(Render, &rectangle);
	SDL_RenderFillRect(Render, &rectangle1);
	cout << "RENDERED" << endl;
	SDL_RenderPresent(Render);
	while(loop = true)
		{
			SDL_Event event;
			while(SDL_PollEvent(&event))
				{
					if(event.type == SDL_QUIT)
						loop = false;
					else if(event.type == SDL_KEYDOWN)
						{
							switch(event.key.keysym.sym)
								{
									case SDLK_RIGHT:
										rectangle1.y += 10;
										SDL_RenderClear(Render);
                                        SDL_RenderFillRect(Render, &rectangle1);
                                        SDL_RenderFillRect(Render, &rectangle);
										SDL_RenderPresent(Render);
										break;
									case SDLK_LEFT:
										rectangle1.y -= 10;
										SDL_RenderClear(Render);
										SDL_RenderFillRect(Render, &rectangle1);
										SDL_RenderFillRect(Render, &rectangle);
										SDL_RenderPresent(Render);
										break;
									case SDLK_UP:
										rectangle.y += 10;
										SDL_RenderClear(Render);
										SDL_RenderFillRect(Render, &rectangle);
										SDL_RenderFillRect(Render, &rectangle1);
										SDL_RenderPresent(Render);
										break;

									case SDLK_DOWN:
										rectangle.y -= 10;
										SDL_RenderClear(Render);
										SDL_RenderFillRect(Render, &rectangle);
										SDL_RenderFillRect(Render, &rectangle1);
										SDL_RenderPresent(Render);
										break;
								}

						}
				}

		}
	return 0;
}
