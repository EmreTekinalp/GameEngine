#include "display.h"


Display::Display(int width, int height, const char* title)
{
	// Initialize SDL first
	SDL_Init(SDL_INIT_EVERYTHING);

	// Set GL Attributes
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	// Check if window could be created, otherwise run SDL error
	if (m_window == NULL)
	{
		printf("Could not create window: %s\n", SDL_Error);
	}	

	GLenum status = glewInit();
	if (! status == GLEW_OK)
	{
		printf("Could not initialize glew: %s\n", SDL_Error);
	}

	m_closed = false;
}


Display::~Display(void)
{
    // Delete GLContext
    SDL_GL_DeleteContext(m_glContext);
    // Destroy window
    SDL_DestroyWindow(m_window);
    // Deinitialize SDL
    SDL_Quit();
}


bool Display::isClosed()
{
	return m_closed;
}


void Display::update()
{
	// swap the window with OpenGL
	SDL_GL_SwapWindow(m_window);

	SDL_Event event;
	while(SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			m_closed = true;
		}

	}
}


void Display::setupContent(float r, float g, float b, float a)
{
	while(!Display::isClosed())
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
		Display::update();
	} // end while create gl content
}