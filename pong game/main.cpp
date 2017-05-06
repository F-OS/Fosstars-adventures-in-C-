#include <SDL2/SDL.h>
#include <thread>
#include <iostream>
using namespace std;
int do_render();
SDL_Rect rectangle;
SDL_Rect rectangle1;
SDL_Rect goal;
SDL_Rect goal1;
SDL_Rect ball;
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
 ball.x = 400;
 ball.y = 400;
 ball.w = 30;
 ball.h = 30;
 goal.x = 0;
 goal.y = 0;
 goal.w = 10;
 goal.h = 2000;
 goal1.x = 792;
 goal1.y = 0;
 goal1.w = 10;
 goal1.h = 2000;
 return 0;
}
bool collisiondetect(int testa_x, int testa_y, int testb_x, int testb_y, int sizea_x, int sizea_y, int sizeb_x, int sizeb_y)
{
 int aleft = testa_x;
 int bleft = testb_x;
 int atop = testa_y;
 int btop = testb_y;
 int aright = testa_x + sizea_x;
 int bright = testb_x + sizeb_x;
 int abottom = testa_y + sizea_y;
 int bbottom = testb_y + sizeb_y;

 if ( aleft > bright )
  return false;

 if ( aright < bleft )
  return false;

 if ( atop > bbottom )
  return false;

 if ( abottom < btop )
  return false;

 return true;
}
int movement_logic()
{
 bool loop = true;
 int movementFactor = 15;
 SDL_Event e;

 while ( loop )
  {
   while( SDL_PollEvent( &e ) )
    {
     const Uint8* keystates = SDL_GetKeyboardState(NULL);

     if(keystates[SDL_SCANCODE_UP])
      {
       rectangle.y -= movementFactor;
      }

     else
      if(keystates[SDL_SCANCODE_DOWN])
       {
        rectangle.y += movementFactor;
       }

      else
       if(keystates[SDL_SCANCODE_LEFT])
        {
         rectangle1.y += movementFactor;
        }

       else
        if(keystates[SDL_SCANCODE_RIGHT])
         {
          rectangle1.y -= movementFactor;
         }

     do_render();
    }

  }

 return 0;
}
int timepointlog()
{

}
int do_render()
{
 SDL_RenderClear(Render);
 SDL_RenderFillRect(Render, &rectangle1);
 SDL_RenderFillRect(Render, &rectangle);
 SDL_RenderFillRect(Render, &goal);
 SDL_RenderFillRect(Render, &goal1);
 SDL_RenderFillRect(Render, &ball);
 SDL_RenderPresent(Render);
 return 0;
}
int main()
{
 load_vars_and_create_window_object();
 load_square_def();
 do_render();
 thread(movement_logic);
 thread(timepointlog);
 return 0;
}
