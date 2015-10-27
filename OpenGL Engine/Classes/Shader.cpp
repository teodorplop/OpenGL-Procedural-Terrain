#include "Shader.h"
#include "Utils/FileUtils.h"

GLuint Shader::compile(GLuint type, const char* source) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		std::string log(length, ' ');
		glGetShaderInfoLog(shader, length, &length, &log[0]);
		throw std::logic_error(log);
		return false;
	}

	return shader;
}

void Shader::compileShaders(const char* vertexSource, const char* fragmentSource) {
	vertexShader = compile(GL_VERTEX_SHADER, vertexSource);
	fragmentShader = compile(GL_FRAGMENT_SHADER, fragmentSource);

	prog = glCreateProgram();
	glAttachShader(prog, vertexShader);
	glAttachShader(prog, fragmentShader);
	glLinkProgram(prog);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	string vertexCode = FileUtils::GetFileContents(vertexFile);
	string fragmentCode = FileUtils::GetFileContents(fragmentFile);
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	compileShaders(vertexSource, fragmentSource);
}

Shader::~Shader() {
	glDetachShader(prog, vertexShader);
	glDetachShader(prog, fragmentShader);

	glDeleteProgram(prog);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLuint Shader::getProgram() {
	return prog;
}

void Shader::link() {
	glUseProgram(prog);
}
void Shader::unLink() {
	glUseProgram(0);
}