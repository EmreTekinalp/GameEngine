#include <iostream>
#include "display.h"


void main(int argc, char* argv[])
{
	Display display(800, 600, "FUck yeah SDL OpenGL");
    display.setupContent(0.9f, 0.14f, 0.4f, 1.0f);
}