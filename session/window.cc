#include "../includes/window.hh"

Window::Window(QWidget*parent):
  QGLWidget(QGLFormat(QGL::SampleBuffers), parent){

}
Window::~Window(){

}

void
Window::initializeGL(){

}

void 
Window::resizeGL(){

}

void 
Window::paintGL(){

}

void 
Window::timerEvent(QTimerEvent* event){

}

void
Window::mousePressEvent(QMouseEvent* event){

}

void
Window::mouseReleaseEvent(QMouseEvent* event){

}
