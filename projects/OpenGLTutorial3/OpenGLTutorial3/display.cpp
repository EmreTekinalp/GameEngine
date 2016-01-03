#include "display.h"


Display::Display(int width, int height, const char* title)
{
    // initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // create opengl window and glContext
    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);

    if (m_window == NULL)
    {
        std::cerr << "Could not initialize SDL Window properly" << std::endl;
        return;
    } // end if error handling for window creation

    GLenum status = glewInit();
    if (!status == GLEW_OK)
    {
        std::cerr << "Could not initialize GLEW GL properly" << std::endl;
        return;
    } // end if error handling for glew initializing

    // set init quit state
    quit = false;
}

Display::~Display()
{
    // quit glContext
    SDL_GL_DeleteContext(m_glContext);
    // quit window
    SDL_DestroyWindow(m_window);
    // quit SDL
    SDL_Quit();
}

void Display::update()
{
    // swap buffers when calling update function
    SDL_GL_SwapWindow(m_window);

    while (SDL_PollEvent(&m_event) != 0)
    {
        if (m_event.type == SDL_QUIT)
        { 
            quit = true;
        } // end if user closes window set quit to true
    } // end while loop event if window is not closed
}

bool Display::isClosed()
{
    return quit;
}

void Display::drawBackground(float r, float g, float b, float a)
{
    // Color the background
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::OpenWindow(int argc, char* argv[])
{
    
}