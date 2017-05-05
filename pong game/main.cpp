#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
int dorender();
SDL_Rect rectangle;
SDL_Rect rectangle1;
SDL_Renderer * Render;
int load_vars_and_create_window_object()
{
  int positionx = 50;
  int positiony = 50;
  int sizex = 800;
  int sizey = 800;
  SDL_Window * Window;
  SDL_InitSubSystem(SDL_INIT_EVERYTHING);
  Window = SDL_CreateWindow("Test", positionx, positiony, sizex, sizey, SDL_WINDOW_OPENGL);
  Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
  SDL_RenderSetLogicalSize(Render, sizex, sizey);
  return 0;
}
int load_square_def()
{
  rectangle.x = 20;
  rectangle.y = 300;
  rectangle.w = 30;
  rectangle.h = 200;
  rectangle1.x = 755;
  rectangle1.y = 300;
  rectangle1.w = 30;
  rectangle1.h = 200;
  return 0;
}
int movement_logic() {
  bool loop = true;
  while (loop == true) {
    SDL_Event event;
    while (SDL_PollEvent( & event)) {
      if (event.type == SDL_QUIT)
        loop = false;
      else
      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
          rectangle1.y += 10;
          do_render();
          break;
        case SDLK_LEFT:
          rectangle1.y -= 10;
          do_render();
          break;
        case SDLK_UP:
          rectangle.y -= 10;
          do_render();
          break;
        case SDLK_DOWN:
          rectangle.y += 10;
          do_render();
          break;
        }
      }
    }
  }
  return 0;
}
int do_render()
{
  SDL_RenderClear(Render);
  SDL_RenderFillRect(Render, & rectangle1);
  SDL_RenderFillRect(Render, & rectangle);
  SDL_RenderPresent(Render);
  return 0;
}
int main()
{
  load_vars_and_create_window_object();
  load_square_def();
  do_render();
  movement_logic();
  return 0;
}
