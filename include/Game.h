#ifndef __Game_H_
#define __Game_H_

#include <ngl/Camera.h>
#include <ngl/Transformation.h>
#include <ngl/Light.h>
#include <SDL2/SDL.h>
#include "Maze.h"
#include <QKeyEvent>

/// \Michael Woods
/// \version 1.0
/// \Maze
/// \This is the game class.
///

class Game
{
  public:

  Game();
  ~Game();
  void resize(int _w, int m);
  void draw();
  void update_objective();
  void loadMatricesToShader();

  private:
  Maze m_maze;
  ngl::Transformation m_transform;
  std::vector <ngl::Camera > m_cam;
   //----------------------------------------------------------------------------------------------------------------------
  float m_fov;
   //----------------------------------------------------------------------------------------------------------------------
   /// @brief aspect ratio of the camera
   //----------------------------------------------------------------------------------------------------------------------
   float m_aspect;
   //----------------------------------------------------------------------------------------------------------------------
   /// @brief an index into the active camera list
   //----------------------------------------------------------------------------------------------------------------------
   int m_cameraIndex;

};

#endif
