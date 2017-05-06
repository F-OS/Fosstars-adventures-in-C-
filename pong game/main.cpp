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
bool check_collision( SDL_Rect A, SDL_Rect B )
{
 //The sides of the rectangles
 int leftA, leftB;
 int rightA, rightB;
 int topA, topB;
 int bottomA, bottomB;

 //Calculate the sides of rect A
 leftA = A.x;
 rightA = A.x + A.w;
 topA = A.y;
 bottomA = A.y + A.h;

 //Calculate the sides of rect B
 leftB = B.x;
 rightB = B.x + B.w;
 topB = B.y;
 bottomB = B.y + B.h;

 if( bottomA <= topB )
  {
   return false;
  }

 if( topA >= bottomB )
  {
   return false;
  }

 if( rightA <= leftB )
  {
   return false;
  }

 if( leftA >= rightB )
  {
   return false;
  }

 return true;
}
int movement_logic()
{
 bool loop = true;
 int movementFactor = 15;
 int ball_movx = 1;
 int ball_movy = 0;
 int score = 0;
 int score1 = 0;
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
    }

   if(ball.y + ball.h >= 800)
    {
     ball_movy--;
    }

   if(check_collision(ball, rectangle) == true)
    {
     ball_movx++;
    }

   if(check_collision(ball, rectangle1) == true)
    {
     ball_movx--;
    }

   if(check_collision(ball, goal))
    {
     cout << "GOAL" << endl;
     ball.x = 400;
     ball.y = 400;
     ball_movx = 1;
     score++;
     cout << "The score is " << score << "to" << score1 << endl;

    }

   if(check_collision(ball, goal1))
    {
     cout << "GOAL" << endl;
     ball.x = 400;
     ball.y = 400;
     ball_movx = 1;
     score1++;
     cout << "The score is " << score << " to " << score1 << endl;
    }

   if(score >= 10)
    {
     cout << "Player 1 wins!!" << endl;
     return 0;
    }

   if(score1 >= 10)
    {
     cout << "Player 2 wins!!" << endl;
     return 0;
    }

   ball.x = ball_movx + ball.x;
   ball.y = ball_movy + ball.y;
   do_render();
   SDL_Delay(1);
  }

 return 0;
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
 movement_logic();
 return 0;
}
