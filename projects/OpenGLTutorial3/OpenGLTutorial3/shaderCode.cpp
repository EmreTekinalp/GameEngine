const char* vertexShaderCode =
	"#version 430\r\n"
	""
	"in layout(location=0) vec3 position;"
	""
	"void main()"
	"{"
	"	gl_Position = vec4 position(position, 1.0);"
	"}";

const char* fragmentShaderCode =
	"#version 430\r\n"
	""
	"out vec4 daColor;"
	""
	"void main()"
	"{"
	"	daColor = vec4(0.0, 1.0, 0.0, 1.0);"
	"}";
