#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <GL\glew.h>
#include <glm\glm.hpp>

class Vertex
{
public:
    Vertex(const glm::vec3& position)
    {
        this->position = position;
        this->color = glm::vec3(1.0, 0.0, 0.0);
    }

private:
    glm::vec3 position;
    glm::vec3 color;
};


class Mesh
{
public:
    Mesh(GLfloat* vertices, unsigned int numVertices);
    virtual ~Mesh();

    void installShader();
    bool checkStatus(GLuint objectID,
                     PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
                     PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
                     GLenum statusType);
    bool checkShaderStatus(GLuint shaderID);
    bool checkProgramStatus(GLuint programID);
    void draw();
private:
    Mesh(Mesh& other) {} // copy constructor
    void operator = (Mesh& other) {} // assignment operator

    // create bufferID
    GLuint bufferID;
    GLuint m_drawCount;
};

#endif