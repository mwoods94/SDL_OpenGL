#include <ngl/NGLInit.h>
#include <ngl/ShaderLib.h>
#include "Game.h"
#include "Maze.h"
#include "player.h"
#include <ngl/Camera.h>




//--------------------------------------------------------------------


Game::Game()
{
  ngl::NGLInit::instance();
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	;      //white background
  //enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);



   ngl::ShaderLib *shader=ngl::ShaderLib::instance();

   std::string textureShader = "TextureShader";
   std::string ShaderVert = "ShaderVert";
   std::string ShaderFrag = "ShaderFrag";

   shader->createShaderProgram(textureShader);
   std::cout << shader->getProgramID(textureShader) << std::endl;

   shader->attachShader(ShaderVert,ngl::ShaderType::VERTEX);
   shader->attachShader(ShaderFrag,ngl::ShaderType::FRAGMENT);
   shader->loadShaderSource(ShaderFrag,"shaders/TextureVert.glsl");
   shader->loadShaderSource(ShaderFrag,"shaders/TextureFrag.glsl");

   shader->compileShader(ShaderFrag);
   shader->compileShader(ShaderFrag);
   shader->attachShaderToProgram(textureShader,ShaderFrag);
   shader->attachShaderToProgram(textureShader,ShaderFrag);

   shader->linkProgramObject(textureShader);
   shader->use(textureShader);

   Maze maze;
   maze.emptyGrid();
   draw();
   //maze.Maze_Setup(50 , 50);
  // maze.Render_Maze(1, 2);


}



//--------------------------------------------------------------------

Game::~Game()
{

}

//--------------------------------------------------------------------


void Game::loadMatricesToShader()
{
  m_fov=65.0;
  m_aspect=1024.0/768.0;

  player Player;

  Player.camera_position();

  ngl::ShaderLib *shader=ngl::ShaderLib::instance();

  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  ngl::Mat4 Matrix;
 // MV= Matrix *m_cam[m_cameraIndex].getViewMatrix();
 // MVP=  MV*m_cam[m_cameraIndex].getProjectionMatrix();
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setShaderParamFromMat4("MV",MV);
  shader->setShaderParamFromMat4("MVP",MVP);
  shader->setShaderParamFromMat3("normalMatrix",normalMatrix);

}

void Game::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  loadMatricesToShader();
  m_maze.getWall()->draw();

}

//--------------------------------------------------------------------

void Game::update_objective()
{

}

//--------------------------------------------------------------------

void Game::resize(int _w, int _h)
{

  glViewport(0,0, _w, _h);
  //now set the camera size values as the screen size has changed

}

//--------------------------------------------------------------------


