#ifndef __Maze_H_
#define __Maze_H_

#include "Cell.h"
#include <vector>
#include <ngl/Obj.h>

/// \Michael Woods
/// \version 1.0
/// \Maze
/// \This is the maze class.
///

class Maze
{
  public:

  void Maze_Setup(int m_maze_x, int m_maze_z);
  void emptyGrid();
  Maze();  //constructor
  ~Maze(); //descructor
  void Destroy_wall_South();
  void Destroy_wall_West();
  void Destroy_wall_East();
  void Destroy_wall_North();
  void Render_Maze(int m_maze_x, int m_maze_z);
  void drawWall();
  void Print_Maze_Test();

  ngl::Obj* getWall(){return m_wall;}

  private:
  int x;
  int z;
  int m_maze_z;
  int m_maze_x;
  std::vector<std::vector<Cell>> m_maze;
  ngl::Obj *m_wall;
//  ngl::Vec3 m_wallPos;

};

#endif //end include guard


