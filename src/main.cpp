# include <iostream>
#include "SDLOpenGl.h"
#include <ngl/NGLInit.h>

void initalizeGL();
void renderGL();

int main (int argc, char *argv[])
{
  SDLOpenGL window("test", 0, 0, 1024, 720);
  initalizeGL();
  while(true)
  {
    renderGL();
    window.swapWindow();
    SDL_Delay(10);
  }
}

void initalizeGL()
{
  ngl::NGLInit::instance();
  glClearColor(0.8, 0.8, 0.8, 1.0);
}

void renderGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
