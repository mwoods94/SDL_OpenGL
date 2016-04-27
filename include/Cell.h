#ifndef __Cell_H_
#define __Cell_H_

#include <ngl/Vec2.h>

/// \Michael Woods
/// \version 1.0
/// \Cell
/// \This is the class for the maze cells
///
class Cell
{
  public:
  Cell();
  ~Cell();
  void setVisit(bool _value);
  //if set to true, cell has been visited, if cell visited is set to false, cell is unvisited
  bool getVisit();
  void setCellType(int _type);
  //if cell type is set to 1, Cell is a wall
  int getCellType();


  private:
  ngl::Vec2 m_cellCoordinates;
  bool m_visited;
  int m_cellType; //1 for wall, 0 for no wall
  // enum Player_objective_Position { Player_Start, Player_End, Position_Treasure};
}; // end of class

#endif //end include guard
