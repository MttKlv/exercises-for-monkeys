#ifndef WINDOW_HH_
#define WINDOW_HH_

#include <QtOpenGL>
#include <QMouseEvent>
#include <iostream>

class Window : public QGLWidget{
public:
  Window(QWidget*parent);
  ~Window();

  void initizaliseGL();
  void resizeGL();
  void paintGL();
  void timerEvent(QTimerEvent*);
  void mousePressEvent(QMouseEvent*);
  void mouseReleaseEvent(QMouseEvent*);
};

#endif
