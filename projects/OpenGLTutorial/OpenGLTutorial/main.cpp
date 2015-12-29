#include "display.h"
#include <GL\glew.h>
#include <iostream>

void main()
{
	Display watch(800, 600, "OpenGLYeah");

	while(!watch.isClosed())
	{
		glClearColor(0.0f, 0.15f, 0.32f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		watch.Update();
	}
}