#include <GL/glut.h>
void draw(void)
{
//background color
glClearColor(0,0,0,1);
glClear(GL_COLOR_BUFFER_BIT );
//draw order
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
//simple buffer
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
glutInitWindowPosition(50,25);
glutInitWindowSize(500,250);
glutCreateWindow("TEST");
//call to the drawing function
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
