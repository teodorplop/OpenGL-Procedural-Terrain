#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1200, 700);
	glutCreateWindow("Puncte & Segmente");
}