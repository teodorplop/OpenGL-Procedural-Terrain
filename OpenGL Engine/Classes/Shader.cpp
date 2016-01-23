#include "Shader.h"
#include "Utils/FileUtils.h"

GLuint Shader::Compile(GLuint type, const char* source) {
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

void Shader::CompileShaders(const char* vertexSource, const char* fragmentSource) {
	vertexShader = Compile(GL_VERTEX_SHADER, vertexSource);
	fragmentShader = Compile(GL_FRAGMENT_SHADER, fragmentSource);

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

	CompileShaders(vertexSource, fragmentSource);
}

Shader::~Shader() {
	glDeleteProgram(shaderProgram);
}

void Shader::Bind() {
	glUseProgram(shaderProgram);
}
void Shader::Unbind() {
	glUseProgram(0);
}

void Shader::SetUniformMatrix4fv(const char* name, const Matrix4& matrix) {
	GLint matrixID = glGetUniformLocation(shaderProgram, name);
	glUniformMatrix4fv(matrixID, 1, GL_TRUE, &matrix.elements[0][0]);
}
void Shader::SetUniform3f(const char* name, const Vector3& vector) {
	GLint vectorID = glGetUniformLocation(shaderProgram, name);
	glUniform3f(vectorID, vector.x, vector.y, vector.z);
}
void Shader::SetUniform1f(const char* name, const float& value) {
	GLint floatID = glGetUniformLocation(shaderProgram, name);
	glUniform1f(floatID, value);
}

void Shader::SetUniformDirectionalLight(const char* name, const DirectionalLight& light) {
	string baseName = name;
	SetUniform3f((baseName + ".color").c_str(), light.color.ToVector3());
	SetUniform1f((baseName + ".ambientIntensity").c_str(), light.ambientIntensity);
	SetUniform3f((baseName + ".direction").c_str(), light.direction);
	SetUniform1f((baseName + ".diffuseIntensity").c_str(), light.diffuseIntensity);
}