#include <ngl/Vec3.h>
#include <ngl/NGLInit.h>
#include <ngl/Camera.h>

#include "player.h"

//--------------------------------------------------------------------

void player::camera_position()
{


  ngl::Camera cam;
  //vector positions of camera

  ngl::Vec3 CameraPos(0.0f, 0.0f, 3.0f);
  ngl::Vec3 look = 0.0f;
  ngl::Vec3 up(0,1,0);

  //setting the cameras shape and the position
  cam.set(CameraPos, look, up);
  cam.setShape(m_fov, m_aspect, 0.2f, 150.0f);
  m_cam.push_back(cam);


}

//--------------------------------------------------------------------

void player::keyPressEvent(QKeyEvent *_event)
{
  switch (_event->key())
    {
      case Qt::Key_W : { m_cam[m_cameraIndex].move(1, 0 , 0); break; }
      case Qt::Key_S : { m_cam[m_cameraIndex].move(-1, 0, 0); break; }
      case Qt::Key_A : { m_cam[m_cameraIndex].yaw(-3); break; }
      case Qt::Key_D : { m_cam[m_cameraIndex].yaw(3); break; }
    }

}
