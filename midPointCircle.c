#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>


int ptx, pty, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+ptx, y+pty);
	glEnd();
}

void init (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

	
void midpointcircle()
{
 int x=0;
 int y=r;
 float decision = 5/4-r;
 while (r >= x)
	{
 	if(decision < 0)
		{
			x++;
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}  		
		 
void hello(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midpointcircle();

	glFlush ();
}



int main(int argc, char** argv){
    	printf("Enter the coordinates of the center:\n\n");
 	printf("X-coordinate : ");
	scanf("%d",&ptx);
	printf("\nY-coordinate : ");
	scanf("%d",&pty);
	printf("\nEnter Radius: ");
 	scanf("%d",&r);


        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(1366,768);
        glutInitWindowPosition(0,0);
        glutCreateWindow("CIRCLE");
        glutDisplayFunc(hello);
        //glutMouseFunc(mouse);
        init();
        glutMainLoop();
        return 0;
}
