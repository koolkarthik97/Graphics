#include <GL/glut.h>


int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800,600);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");
	glutMainLoop();
	return 0;

}
