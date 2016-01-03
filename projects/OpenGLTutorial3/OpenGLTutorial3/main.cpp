#include "display.h"
#include "mesh.h"
#include <QtWidgets\qapplication.h>

void main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // call and create sdl/opengl window
    Display display(800, 600, "VisualStudio2015 - Baby");
    GLfloat verts[] =
    {
        +0.0f, +0.5f, +0.0f,
        +1.0f, +0.0f, +0.0f,
        -0.5f, -0.5f, +0.0f,
        +0.0f, +0.0f, +1.0f,
        +0.5f, -0.5f, +0.0f,
        +0.0f, +1.0f, +0.0f
    };
    Mesh mesh(verts, sizeof(verts) / sizeof(verts[0]));

    while (!display.isClosed())
    {
        // draw triangle
        //display.drawBackground(0.8, 0.9, 0.7, 1.0);
        mesh.draw();
        display.update();
    } // end while not window closed do opengl stuff
}
