#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strings
#include <time.h>
#include <math.h>

#ifdef WIN32
#include <windows.h> // inclui apenas no Windows
#include "gl/glut.h"
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int total=0;
float minx=-1000, maxx=1000;
float miny=-1000, maxy=1000;
float minz=-1000, maxz=1000;
float magmin=-10, magmax=10;

int width,height;
float deltax=0, deltay=0;
GLfloat angle=60, fAspect=1.0;
GLfloat rotX=0, rotY=0, rotX_ini=0, rotY_ini=0;
GLfloat obsX=0, obsY=0, obsZ=150, obsX_ini=0, obsY_ini=0, obsZ_ini=0;
int x_ini=0,y_ini=0,bot=0;

// Graphics function prototypes
void drawAll();
void drawRect(float x1, float y1, float x2, float y2);
void drawTri(float x1, float y1, float x2, float y2, float x3, float y3);
void drawCirc(float x1, float y1, float r);
void drawLine(float x1, float y1, float x2, float y2);
void draw3DPoint(float x1, float y1, float z1);
void init();
void clear();
void loop();
void keyboard(unsigned char key, int x, int y);
void draw();
void reshape(GLsizei w, GLsizei h);
void mouse(int button, int state, int x, int y);
void move(int x, int y);
void setprojection();

int main()
{
    // Leia o arquivo starcatalog.csv

	// Creates the graphics window
	init();

	// Starts the event loop - never returns
	loop();
}

void drawAll() {

    glPointSize(1);
    glBegin(GL_POINTS);

	// Faça um for na sua lista e envie as coordenadas
	// de cada estrela no glVertex3f!
	
    glColor3ub(255, 255, 255); // white
    // below: x, y, z
    glVertex3f(0,0,0);

    glEnd();
}

/**
 *
 * CODE TO ACCESS THE GRAPHICS LIBRARY (OPENGL)
 * There's NO NEED to change ANYTHING from here on
 *
*/

// Draw a rectangle
void drawRect(float x1, float y1, float x2, float y2) {
	glBegin(GL_QUADS);
	  glVertex2f(x1,y1);
	  glVertex2f(x2,y1);
	  glVertex2f(x2,y2);
	  glVertex2f(x1,y2);
	glEnd();
}

// Draw a triangle
void drawTri(float x1, float y1, float x2, float y2, float x3, float y3) {
	glBegin(GL_TRIANGLES);
	  glVertex2f(x1,y1);
	  glVertex2f(x2,y2);
	  glVertex2f(x3,y3);
	glEnd();
}

// Draw a circle
void drawCirc(float x1, float y1, float r) {

	float ang;
	ang = 0;

	// Use triangle fan to be more efficient
	glBegin(GL_TRIANGLE_FAN);
	// A vertex at the center
	glVertex2f(x1,y1);

	GLint circle_points = 20;
	for (int i = 0; i < circle_points; i++) {
		float angle = 2*3.1415926*i/circle_points;
		// ... and many vertices around it
		glVertex2f(x1+cos(angle)*r, y1+sin(angle)*r);
	}
	// This will guarantee that the circle will be closed
	glVertex2f(x1+cos(0)*r, y1+sin(0)*r);
	glEnd();
}

// Draw a line
void drawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	  glVertex2f(x1,y1);
	  glVertex2f(x2,y2);
	glEnd();
}

// Draw a point in 3D space
void draw3DPoint(float x, float y, float z) {
	glBegin(GL_POINTS);
	glVertex3f(x,y,z);
	glEnd();
}

// Clear the screen and initialise
void clear() {
	// Clear the screen with black
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Load the identity matrix
	glLoadIdentity();
}

// Initialisation
void init()
{
	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

	// Set GLUT operation mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Set starting window size
	glutInitWindowSize(400,400);

	// Create the window
	glutCreateWindow("Star Catalog Visualisation");

	// Set the drawing callback function
	glutDisplayFunc(draw);

	// Set the keyboard callback function
	glutKeyboardFunc (keyboard);

	// Set the resizing callback function
	glutReshapeFunc(reshape);

	// Set the mouse callback function
	glutMouseFunc(mouse);

	// Set the mouse motion callback
	glutMotionFunc(move);
}

// Enter event loop
void loop() {
	glutMainLoop();
}

// Drawing callback
void draw()
{
	clear();

	glColor3ub(200,200,200);	// light gray

	// Set observer and target
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);

	// Draw a cube around the universe
	glBegin(GL_LINE_LOOP);
	glVertex3f(minx,miny,minz);
	glVertex3f(maxx,miny,minz);
	glVertex3f(maxx,miny,maxz);
	glVertex3f(minx,miny,maxz);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(minx,maxy,minz);
	glVertex3f(maxx,maxy,minz);
	glVertex3f(maxx,maxy,maxz);
	glVertex3f(minx,maxy,maxz);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(minx,miny,minz);
	glVertex3f(minx,maxy,minz);
	glVertex3f(maxx,miny,minz);
	glVertex3f(maxx,maxy,minz);
	glVertex3f(maxx,miny,maxz);
	glVertex3f(maxx,maxy,maxz);
	glVertex3f(minx,miny,maxz);
	glVertex3f(minx,maxy,maxz);
	glEnd();

	// Draw all stars
	drawAll();

	// Show the drawing
	glutSwapBuffers();
}

// Keyboard callback
void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)		// ESC ?
		exit(0);

	// Redraw
	glutPostRedisplay();
}

// Set the perspective projection
void setprojection()
{
	// Set projection mode
	glMatrixMode(GL_PROJECTION);
	// Initialise matrix
	glLoadIdentity();
	// Set a perspective projection
	gluPerspective(angle,fAspect,0.1,100000);
	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay();
}

// Resizing callback
void reshape(GLsizei w, GLsizei h)
{
	if ( h == 0 ) h = 1;

	// Set the view dimensions
	glViewport(0, 0, w, h);

	// Compute aspect ratio
	fAspect = (GLfloat)w/(GLfloat)h;

	setprojection();
}

// Mouse callback
void mouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		// Save current values
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}

// Mouse motion callback
#define SENS_ROT	5.0
#define SENS_OBS	20.0
void move(int x, int y)
{
	// Left?
	if(bot==GLUT_LEFT_BUTTON)
	{
		// Compute deltas
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// And change angles
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Right?
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		// Compute deltas
		int deltaz = y_ini - y;
		// Change observer distance
		obsZ = obsZ_ini - deltaz/SENS_OBS;
	}
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		// Compute deltas
		int deltaz = y_ini - y;
		// Change observer distance
		obsZ = obsZ_ini - deltaz/SENS_OBS*100;

	}
	glutPostRedisplay();
}

