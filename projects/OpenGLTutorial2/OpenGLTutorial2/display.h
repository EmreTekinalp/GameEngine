#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>

#include <SDL2\SDL.h>
#undef main
#include <GL/glew.h>

class Display
{
public:
    Display(int width, int height, const char* title);
    virtual ~Display(void);

    void update();
    bool isClosed();
    void setupContent(float r, float g, float b, float a);
protected:
private:
    Display(const Display& other) {}
    Display& Display::operator=(const Display& other) {}

    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_closed;
};

#endif DISPLAY_H
