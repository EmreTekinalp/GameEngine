#include <iostream>
#include <Qt\qapplication.h>
#include <GL\glew.h>


void main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    std::cout << "Hello OPenFuckingGL" << std::endl;
    app.exec();
}