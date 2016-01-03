#include "mesh.h"

const char* vertexShaderCode =
    "#version 430\r\n"
    ""
    "in layout(location=0) vec3 position;"
    "in layout(location=1) vec3 vertexColor;"
    ""
    "out vec3 theColor;"
    ""
    "void main()"
    "{"
    "   gl_Position = vec4(position, 1.0);"
    "   theColor = vertexColor;"
    "}";

const char* fragmentShaderCode =
    "#version 430\r\n"
    ""
    "out vec4 daColor;"
    "in vec3 theColor;"
    ""
    "void main()"
    "{"
    "   daColor = vec4(theColor, 1.0);"
    "}";


Mesh::Mesh(GLfloat* vertices, unsigned int numVertices)
{
    m_drawCount = numVertices;
    // generate buffer
    glGenBuffers(1, &bufferID);
    // bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    // create buffer data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numVertices, vertices, GL_STATIC_DRAW);
    // enable vertex object attribute array, 0 is position, 1 is color
    glEnableVertexAttribArray(0);
    // Describe our data to opengl
    // GLuint index = describe the buffer index
    // GLint size = specify if we have a vec2, vec3 or vec4 with 2, 3 or 4
    // GLenum type = Specify the type of the position mostly GL_FLOAT
    // GLboolean normalized = Specify if you want to have the vertices nomralized
    // GLsizei stride = Is the distance from the beginning from the same attribute to the next same attribute
    // const void* pointer = Is the distance from the beginning from one attribute to the very next different attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));

    // install shader
    installShader();
}


Mesh::~Mesh()
{
}

void Mesh::installShader()
{
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // define shader code
    const char* adapter[1];
    adapter[0] = vertexShaderCode;
    glShaderSource(vertexShaderID, 1, adapter, 0);
    adapter[0] = fragmentShaderCode;
    glShaderSource(fragmentShaderID, 1, adapter, 0);

    // compile shader id codes
    glCompileShader(vertexShaderID);
    glCompileShader(fragmentShaderID);


    if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
    {
        return;
    } // check shader status

    // create and attach shaders to gl program
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    if (!checkProgramStatus(programID))
    {
        return;
    }

    // link the shaders to the program
    glUseProgram(programID);
}

void Mesh::draw()
{
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
}

bool Mesh::checkStatus(GLuint objectID,
                       PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
                       PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
                       GLenum statusType)
{
    // check compiler status
    GLint status;
    // get shader integer vector
    objectPropertyGetterFunc(objectID, statusType, &status);
    if (status != GL_TRUE)
    {
        GLint infoLogLength;
        // Check length of info log
        objectPropertyGetterFunc(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* buffer = new GLchar[infoLogLength];

        GLsizei bufferSize;
        getInfoLogFunc(objectID, infoLogLength, &bufferSize, buffer);
        std::cout << buffer << std::endl;
        delete [] buffer;
        return false;
    }
    return true;
}

bool Mesh::checkShaderStatus(GLuint shaderID)
{
    return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool Mesh::checkProgramStatus(GLuint programID)
{
    return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
}