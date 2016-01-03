#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <vector>
#include <string>

#include <SDL2\SDL.h>
#undef main // SDL_main.h is causing issues

#include <GL/glew.h>


class Display
{
public:
    Display(int width, int height, const char* title);
    virtual ~Display();

    // update function to swap between the two buffers and check event status
    void update();

    // getter function returning boolean quit status
    bool isClosed();

    // setup display function
    void drawBackground(float r, float g, float b, float a);
private:
    // copy constructor
    Display(Display& other) {}
    // assigment operator
    Display* Display::operator = (Display& other) {}

    // create window, glContext and SDL Event for PollEvent
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    SDL_Event m_event;

    // var to check PollEvent status
    GLfloat* gl_vertices;
    bool quit;
};

#endif DISPLAY_H
