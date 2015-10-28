#include "Shader.h"
#include "Utils/FileUtils.h"

GLuint Shader::compile(GLuint type, const char* source) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		GLchar infoLog[1024];
		glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", type, infoLog);
	}

	return shader;
}

void Shader::compileShaders(const char* vertexSource, const char* fragmentSource) {
	vertexShader = compile(GL_VERTEX_SHADER, vertexSource);
	fragmentShader = compile(GL_FRAGMENT_SHADER, fragmentSource);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	GLint success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar errorLog[1024];
		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", errorLog);
	}

	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	string vertexCode = FileUtils::GetFileContents(vertexFile);
	string fragmentCode = FileUtils::GetFileContents(fragmentFile);
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	compileShaders(vertexSource, fragmentSource);
}

Shader::~Shader() {
	glDeleteProgram(shaderProgram);
}

GLuint Shader::getProgram() {
	return shaderProgram;
}

void Shader::use() {
	glUseProgram(shaderProgram);
}