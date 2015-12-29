#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2\SDL.h>
#undef main

#include <string>


class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display(void);
	void Update();
	bool isClosed();
protected:
private:
	Display(const Display& other) {}
	void operator=(const Display& other) {}

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

#endif