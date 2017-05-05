#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
SDL_Surface* buffer;
SDL_Window* Window;
SDL_Renderer* Render;
SDL_Rect rectangle;
int main()
{
    int i;
    rectangle.x = 50;
    rectangle.y = 50;
    rectangle.w = 50;
    rectangle.h = 50;
    int positionx = 100;
    int positiony = 200;
    int sizex = 800;
    int sizey = 600;
    int r [7] = {148, 75, 0, 0, 255, 255, 255};
    int g [7] = {0, 0, 0, 255, 255, 127, 0};
    int b [7] = {211, 130, 255, 0, 0, 0, 0};
    SDL_InitSubSystem(SDL_INIT_EVERYTHING);
    Window = SDL_CreateWindow("Test", positionx, positiony, sizex, sizey, SDL_WINDOW_OPENGL);
    Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(Render, sizex, sizey);
    for(i;i < 9;i++)
    {
        if(i == 8)
        {
            i = 0;
        }
        SDL_SetRenderDrawColor(Render, r[i], g[i], b[i], 100);
        SDL_RenderClear(Render);
        SDL_RenderDrawRect(Render, &rectangle);
        SDL_RenderPresent(Render);
        SDL_Delay(1000);
    }
    SDL_Delay(5000);
}

