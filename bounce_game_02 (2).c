#include <stdio.h>
#include <kipr/graphics.h>

void text()
{
  printf("Press Q to EXIT the game \n");
}

void bouncer(double bx)
{
  double by = 474;
  graphics_rectangle_fill(bx,by,bx+60,by+26,255,255,255);
  graphics_circle_fill(bx,by+13,13,255,255,255);
  graphics_circle_fill(bx+60,by+13,13,255,255,255);
  
  return;
}

double wall_bounce(double x, double Xrate)
{
  double radius = 15;
  if (x > (340-radius)) //right wall
    {
      Xrate = 0 - Xrate;
    }
    if (x < radius) //left wall
    {
      Xrate = 0 - Xrate;
    }
  
  return Xrate;
}

int main()
{
  text();
  double bx = 100;
  double x = 200;
  double y = 30;
  double Xrate = 8;
  double Yrate = 8;
  double radius = 15;
  int i = 0;
  
  graphics_open(340,630);
  
  while (get_key_state(KeyQ) == 0)
  {
    graphics_fill(0,0,0);
    graphics_circle_fill(x,y,radius,255,255,255);
    bouncer(bx);
    
    //moving the bouncer
     if (get_key_state(KeyRight) != 0)
    {
      bx = bx + 15;
    }
     if (get_key_state(KeyLeft) != 0)  
    {
      bx = bx - 15;
    }
    if(bx <= 13)
    {
      bx = 13;
    }
    if(bx>= (340-(13+60)))
    {
      bx = 340-(13+60);
    }
    
    Xrate = wall_bounce(x, Xrate);
    
    if(x >= (bx-13) && x <= (bx+13+60)) //bouncer
    {
      if(y >= 474)
      {
      Yrate = 0 - Yrate;
        i = i + 1;
      }
    }
    if(y < 15)
    {
      Yrate = 0 - Yrate;
    }
    
    //loosing the game
    if (y > (474 + 13))
    {
      i = 0;
      x = 50;
      y = 50;
    }
    
    if (i == 10)
    {
      Xrate = Xrate * 1.005;
      Yrate = Yrate * 1.005;
    }
    if (i == 20)
    {
      Xrate = Xrate * 1.005;
      Yrate = Yrate * 1.005;
    }
    if (i == 30)
    {
      Xrate = Xrate * 1.005;
      Yrate = Yrate * 1.005;
    }
   
    g_printInt(i, 2,145, 50, 255, 255, 255, 5.0); //printing the score to the screen
    
    x = x + Xrate;
    y = y + Yrate;
    graphics_update();
  }
  
  
  
  graphics_close();
  return 0;
}