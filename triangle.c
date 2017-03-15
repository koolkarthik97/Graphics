#include <GL/glut.h>
#include <GL/glu.h>
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-2,-2,-5.0);
		glVertex3f(2,0.0,-5.0);
		glVertex3f(0.0,2,-5.0);
	glEnd();
	glFlush();
	sleep(2);
        glColor3f(0.0f, 0.0f, 1.0f);
//translate
        glTranslatef(1.1f, 0.2f, 0.0f);
	glFlush();	
//rotate
	//glColor3f(1.0f, 0.0f, 1.0f);
	//glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
	//sleep(2);
	//glFlush();
        
	
	glutSwapBuffers();
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	// enter GLUT event processing loop
	glutMainLoop();

	return 1;
}
