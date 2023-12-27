#include "OBJFile.h"
#include <GL/freeglut.h>

OBJFile model;


//чтение названия модели из файла., для тестов
string getFileName() {

	string filename;
	string buffer;
	ifstream getFile("model_name.txt");
	if (!getFile) {
		cout << "cannot find file - > model_name.txt." << endl;
		exit(-1);
	}
	getline(getFile, buffer);

	filename = buffer;
	getFile.close();
	return filename;
}


void init() {

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat light_pos[] = { -1.0f, 10.0f, 100.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20.0, 1.0, 1.0, 2000.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	model.loadOBJFile(getFileName());
}

float cameraDistance = 20;
float cameraAngleX = 30.0f;
float cameraAngleY = 0.0f;
int mouseX, mouseY;
bool isMouseDragging = false;

// Mouse callback for camera rotation
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			isMouseDragging = true;
			mouseX = x;
			mouseY = y;
		}
		else if (state == GLUT_UP) {
			isMouseDragging = false;
		}
	}
}

// Mouse motion callback for camera rotation
void motion(int x, int y) {
	if (isMouseDragging) {
		int deltaX = x - mouseX;
		int deltaY = y - mouseY;

		cameraAngleY += deltaX * 0.2f;
		cameraAngleX += deltaY * 0.2f;

		mouseX = x;
		mouseY = y;

		glutPostRedisplay();
	}
}


void updateCamera() {
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -cameraDistance);
	glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
	glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);
}


void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	updateCamera();

	model.draw();
	glutSwapBuffers();
}

void mouseWheel(int button, int dir, int x, int y) {
	if (dir > 0) {
		cameraDistance -= 5.0f;
	}
	else {
		cameraDistance += 5.0f;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glEnable(GL_MULTISAMPLE);
	glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
	glutSetOption(GLUT_MULTISAMPLE, 8);
	int POS_X = (glutGet(GLUT_SCREEN_WIDTH) - WIDTH) >> 1;
	int POS_Y = (glutGet(GLUT_SCREEN_HEIGHT) - HEIGTH) >> 1;
	glutInitWindowPosition(POS_X, POS_Y);
	glutInitWindowSize(WIDTH, HEIGTH);
	glutCreateWindow("Obj Viewer");
	init();    
	//glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMouseWheelFunc(mouseWheel);
	glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}