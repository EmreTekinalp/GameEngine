#include "display.h"
#include <GLFW\glfw3.h>


void main(int argc, char* argv[])
{
    // call and create sdl/opengl window
    Display display(800, 600, "VisualStudio2015 - Baby");
    GLfloat verts[] =
    {
        +0.0f, 0.5f,
        -0.5f, -0.5f,
        +0.5f, -0.5f
    };
    display.initializeGL(verts, sizeof(verts) / sizeof(verts[0]));
    display.paintGL(0.8, 0.9, 0.7, 1.0);
}
