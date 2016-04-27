#include "Maze.h"
#include <iostream>
#include <ngl/Vec2.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Game.h"

//--------------------------------------------------------------------


void Maze::emptyGrid()
{
  for(int x = 0; x < m_maze_x; x++)
  {
    for(int z = 0; z < m_maze_z; z++)
    {
      if(x % 2 == 0)
      {
      //every 2 columns create a set of cells that are walls
        m_maze[x][z].setCellType(1);
        m_maze[x][z].setVisit(true);

      }

      if (z % 2 == 0)
      {
      //every 2 rows create a set of cells that are walls
        m_maze[x][z].setCellType(1);
        m_maze[x][z].setVisit(true);
      }

      else
      {
      //all other cells aren't walls
        m_maze[x][z].setCellType(0);
        m_maze[x][z].setVisit(true);
      }
     }
   }
}

//--------------------------------------------------------------------


void Maze::Maze_Setup(int m_maze_x, int m_maze_z)
{

   std::cout<<"Please enter the width of the maze"<<std::endl;
   std::cin>> m_maze_x;
   std::cout<<"Please enter length of the maze"<<std::endl;
   std::cin>> m_maze_z;
   std::cout<<"You entered dimensions " << m_maze_x<< "by" << m_maze_z<<std::endl;

   if (m_maze_x > 50)
   {
     m_maze_x = 50;
     std::cout<<"maze width value too large, width set to 50"<<std::endl;
   }
   if (m_maze_z > 50)
   {
    m_maze_z = 50;
    std::cout<<"maze length value too large, length set to 50"<<std::endl;
   }
    //m_maze_z = 50;
   //m_maze_x = 50;

   for(int x = 0 ; x < m_maze_x; x++)
   {
      for (int z=0; z < m_maze_z;  z++)
      {

        //iterates to create the border, setting the visited equal to true so the functions later won't affect them

        if( x == 0)   //first column e.g. eastern border
        {
          m_maze[x][z].setVisit(true);

        }

        if ( z == 0) //top row e.g. north border
        {

          m_maze[x][z].setVisit(true);

        }

          if (x == m_maze_x) // last column e,g. western border
        {

          m_maze[x][z].setVisit(true);

        }

          if ( z == m_maze_z) //last row e.g. southern border
        {
           m_maze[x][z].setVisit(true);
        }

        // fills the central part of the maze as not visited
        else
        {

          m_maze[x][z].setVisit(false);

        }
      }
   }

  //deep recursive search


  //initializing the stack for elements
  std::vector<ngl::Vec2> stack;

  //creating a vector for directions
  std::vector<int> m_direction;
  for(int x = 0; x < 4; x++)
  {
    m_direction.push_back(x);
  }


  bool maze_finished = false;

  //sets a flag on visited cells, when the bool is true then the cell's its checked have been visited, when false they have been unvisited
  //this is used to allow the program to know when it should pop a cell from a stack and go to the previous cell
  //bool setflag = false;
  int counter = 0;

  int rand_placement_x = rand() % m_maze_x;
  int rand_placement_z = rand() % m_maze_z;
  //places the element into the start of the list
  stack.push_back(ngl::Vec2(rand_placement_x,rand_placement_z));
  //while loop, finishes when the stack is empty
  while(maze_finished == false )
  //then it will go into the loop
  {
    //shuffle the vector of directions randomly
    std::random_shuffle(m_direction.begin(), m_direction.end());
    if ( m_maze[rand_placement_x][rand_placement_z].getVisit() == false)
    {

      //set the type of the cell to floor
      m_maze[rand_placement_x][rand_placement_z].setCellType(0);

      //set the cell to visited
      m_maze[rand_placement_x][rand_placement_z].setVisit(true);

      //if the direction is North and the north cell isn't visited
      if ((m_direction[0] == 1) && (m_maze[x][z+2].getVisit() == false))
      {
       //push_back to stack to place element at the top of the stack
        stack.push_back(ngl::Vec2(x,z+2));

         //destroy the wall
         Destroy_wall_North();

         //marked as visited
         m_maze[x][z+2].setVisit(true);

         //set as floor
         m_maze[x][z+2].setCellType(0);

         counter ++;
         z = z+2;
        }

      //east
      if ((m_direction[0] == 2) && (m_maze[x+2][z].getVisit() == false))
      {
        // push_back to stack to place element at the top of the stack
        stack.push_back(ngl::Vec2(x+2,z));

        //destroy wall OR mark as floor
        Destroy_wall_East();

        //marked as visited
        m_maze[x+2][z].setVisit(true);

        //set as floor
         m_maze[x+2][z].setCellType(0);

         counter ++;
         x = x+2;

      }

      //west
      if ((m_direction[0] == 3) && (m_maze[x-2][z].getVisit() == false))
      {
         //push_back to stack to place element at the top of the stack
         stack.push_back(ngl::Vec2(x-2,z));

         //destroy wall OR mark as floor
         Destroy_wall_West();

         //marked as visited
         m_maze[x-2][z].setVisit(true);

         //set as floor
         m_maze[x+2][z].setCellType(0);

         counter ++;
         x = x-2;

        }

      //south
      if ((m_direction[0] == 4) && (m_maze[x][z-2].getVisit() == false))
      {

        //push_back to stack to place element at the top of the stack
        stack.push_back(ngl::Vec2(x,z-2));

        //destroy wall OR mark as floor
        Destroy_wall_South();

        //marked as visited
        m_maze[x][z-2].setVisit(true);

        //set as floor
        m_maze[x][z-2].setCellType(0);

        counter ++;
        z = z-2;

      }

      else
      {
        //reshuffle vector for a new value of m_direction
        std::random_shuffle(m_direction.begin(), m_direction.end());
        counter ++;
      }
        //if the vector named stack is empty, the maze is complete

      if (counter == 4)
      {
        stack.pop_back();
      }
    }

    else
    {
      rand_placement_x = rand() % m_maze_x;
      rand_placement_z = rand() % m_maze_z;
    }

    if (stack.size() == 0)
    {
      maze_finished = true;
      return;
    }
  }
}


//--------------------------------------------------------------------


void Maze::Destroy_wall_North()
{
  m_maze[x][z+1].setCellType(0);
  m_maze[x][z+1].setVisit(true);
}

//--------------------------------------------------------------------


void Maze::Destroy_wall_East()
{
  m_maze[x+1][z].setCellType(0);
  m_maze[x+1][z].setVisit(true);
}

//--------------------------------------------------------------------


void Maze::Destroy_wall_West()
{
  m_maze[x][z-1].setCellType(0);
  m_maze[x][z-1].setVisit(true);
}

//--------------------------------------------------------------------


void Maze::Destroy_wall_South()
{
  m_maze[x-1][z].setCellType(0);
  m_maze[x-1][z].setVisit(true);
}

//--------------------------------------------------------------------

void Maze::Render_Maze(int m_maze_x,int m_maze_z)
{
  for (int x= 0; x <= m_maze_x; x++)
  {
    for (int z = 0; z <= m_maze_z;  z++)
    {
      if (m_maze[x][z].getCellType() == 1)
      {
        glTranslatef(x, 0, z);
        Game game;
        game.draw();

      }
    }
  }
}

//--------------------------------------------------------------------
void Maze::drawWall(){

  /*static const float Vertices[] = {
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
  };

  static const float Normals[] = {


  };

  static const float UV[] = {

  };

  //upload the data to the gpu
  GLuint vbo;
  glGenBuffers(1, &vbo);
  //make the VBO active
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  //copy the vertex data over to the VBO
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vertices), //size of the vertex in bytes
               Vertices,
               GL_STATIC_DRAW); //vertex data is to be uploaded once and used several times to draw the maze, won't be changed throughout
                                //the duration of the game.

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexShader, 1, "TextureVert.glsl", NULL);
  //compiling the vertex shader
  glCompileShader(vertexShader);

  //checking to see if the shader has compiled sucessfully
  GLint status;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

  char buffer[512];
  glGetShaderInfoLog(vertexShader, 512, NULL, buffer);

  //compiling the fragment shader

  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

 // glBindFragDataLocation(shaderProgram, 0, "outColour");
  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  //linking between vertex data and attributes
  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glVertexAttribPointer(posAttrib,  //input
                        3,       //3 pieces of data to input, x, y, z
                        GL_FLOAT,   //type of components
                        GL_FALSE,   //normalized or not
                        0,          //0 data between vertices, as we want them to follow after each other
                        0);  //offset from start of the array before attribute


  //enable the vertex attribute array
  glEnableVertexAttribArray(posAttrib);
 */



}




//--------------------------------------------------------------------

void Maze::Print_Maze_Test()
{
  for (x = 0; x <m_maze_x; x++)
  {
    for (z = 0; z <m_maze_z; z++)
    {
      if (m_maze[x][z].getCellType() == 1)
      {
        std::cout<<"#"<<std::endl;
      }
      if (x == m_maze_z)
      {
        std::cout<<"#/n"<<std::endl;
      }
      if (x == 0)
      {
        std::cout<<"#/n"<<std::endl;
      }
      if (z == m_maze_z)
      {
        std::cout<<"#/n"<<std::endl;
      }
      if (z == 0)
      {
        std::cout<<"#/n"<<std::endl;
      }
      else
      {
        std::cout<<"."<<std::endl;
      }
    }
  }
}

//--------------------------------------------------------------------

Maze::Maze()  //constructor
{

  m_wall = new ngl::Obj("models/cube.obj", "textures/wall.png");
  m_wall->createVAO();

  m_maze.resize(m_maze_x);
  for(int i=0;i<m_maze_x;i++)
  {
    m_maze[i].resize(m_maze_z);
  }
}


//--------------------------------------------------------------------

Maze::~Maze() //destructor
{
  for (int x = 0; x < m_maze_x; x ++)
  {
    for (int z = 0; z < m_maze_z; z++)
    {
      //m_wall = delete ngl::Obj("models/cube.obj"); ????????
      //delete m_maze[x][z].Cell
    }
  }
}

//--------------------------------------------------------------------
