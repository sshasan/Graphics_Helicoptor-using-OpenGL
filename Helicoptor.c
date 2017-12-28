#include <GL/glut.h>
#include <math.h> 
#include <stdio.h>
#include <time.h>
#include <string.h>


float XX=300, YY = 300;
int delta =5;
int rot = 0;
int speed=0;
// Trajectory Equation

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	//gluOrtho2D (-400.0, 800.0, -400.0, 800.0);
	gluOrtho2D (0.0, 1000.0, 0.0, 1000.0);
}


void Name()
	{
		glRasterPos2f(700,750);
		char *s = "Syed Saud Hasan (1401054)";
		int j=0;

		while(j<strlen(s))
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(char)s[j]);
				j++;
			}

	}	

void Project()
	{
		glRasterPos2f(300,850);
		char *s = "-------> HELICOPTOR <-------";
		int j=0;

		while(j<strlen(s))
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(char)s[j]);
				j++;
			}

	}		

void coordinate()
	{
		int i=0;

		for(i=-400;i<1000;i++)
			{
				glVertex2f(i,30);
				glVertex2f(30,i);
			}// xy-axis

	}

void dash()
	{
		int i=0;

		for(i=-400;i<1000;i=i+50)
			{
				glVertex2f(i,20);
				glVertex2f(i,40);

				glVertex2f(20,i);
				glVertex2f(40,i);
			}// xy-axis

	}//dash	

void circle()
	{
		int i=0;
		
		for(i=0;i<1000;i++)
			{   glBegin(GL_LINES);
				glVertex2f(XX - 10*cos(3.14*i/180), YY + 10*sin(3.14*i/180));
				glVertex2f(XX + 10*cos(3.14*i/180), YY + 10*sin(3.14*i/180));
				glEnd();
			}		
		
	}



void hel()
	{
		
		YY = YY - 1.2;
		//main body
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		{	
		glVertex2f(XX+10,YY+10);
		glVertex2f(XX+170,YY+10);
		glVertex2f(XX+125,YY+90);
		glVertex2f(XX+10,YY+90);
		}glEnd();

		//window1
		//glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+100,YY+40);
		glVertex2f(XX+140,YY+40);
		glVertex2f(XX+125,YY+70);
		glVertex2f(XX+100,YY+70);
		}glEnd();

		//window2
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+20,YY+40);
		glVertex2f(XX+90,YY+40);
		glVertex2f(XX+86,YY+70);
		glVertex2f(XX+24,YY+70);
		}glEnd();

		//door1
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+100,YY+15);
		glVertex2f(XX+144,YY+15);
		glVertex2f(XX+139,YY+40);
		glVertex2f(XX+100,YY+40);
		}glEnd();

		//door2
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+20,YY+15);
		glVertex2f(XX+89,YY+15);	
		glVertex2f(XX+89,YY+40);
		glVertex2f(XX+20,YY+40);
		}glEnd();

		//tail
		glColor3f(1.0,0.5,0.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+10,YY+10);
		glVertex2f(XX+10,YY+40);	
		glVertex2f(XX-120,YY+34);
		glVertex2f(XX-130,YY+25);
		}glEnd();

		//wing1
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX-150,YY+25);
		glVertex2f(XX-130,YY+25);	
		glVertex2f(XX-120,YY+34);
		glVertex2f(XX-146,YY+90);
		}glEnd();

		//wing2
		glColor3f(0, 0, 1.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX-150,YY+25);
		glVertex2f(XX-130,YY+25);	
		glVertex2f(XX-146,YY-20);
		}glEnd();

		/*//base
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+40,YY+10);
		glVertex2f(XX+40,YY-35);	
		glVertex2f(XX+55,YY-35);
		glVertex2f(XX+55,YY-20);
		//glVertex2f(XX+120,YY-20);
		glVertex2f(XX+120,YY-20);
		glVertex2f(XX+120,YY-35);
		glVertex2f(XX+135,YY-35);
		glVertex2f(XX+135,YY+10);
		}glEnd();*/

		//base1
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+50,YY-30);
		glVertex2f(XX+80,YY-30);	
		glVertex2f(XX+80,YY+10);
		glVertex2f(XX+50,YY+10);
		}glEnd();

		//base2
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(XX+100,YY-30);
		glVertex2f(XX+130,YY-30);	
		glVertex2f(XX+130,YY+10);
		glVertex2f(XX+100,YY+10);
		}glEnd();

		//motor
		glColor3f(1.0,0,0.0);
		glBegin(GL_LINE_LOOP);
		{
		glVertex2f(XX+60,YY+90);
		glVertex2f(XX+88,YY+90);	
		glVertex2f(XX+80,YY+100);
		glVertex2f(XX+65,YY+100);
		}glEnd();

		//motorpipe
		glColor3f(0.0,1,0.0);
		glBegin(GL_LINE_LOOP);
		{
		glVertex2f(XX+77,YY+100);
		glVertex2f(XX+77,YY+130);	
		glVertex2f(XX+70,YY+130);
		glVertex2f(XX+70,YY+100);
		}glEnd();

		int x=-347, y=-175;

		if(rot%2==0)
		{	
		//blade21
		glColor3f(1.0,0,0.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(200+x+XX,230+y+YY);
		glVertex2f(210+x+XX,220+y+YY);
		glVertex2f(202+x+XX,200+y+YY);
		glVertex2f(210+x+XX,180+y+YY);
		glVertex2f(200+x+XX,170+y+YY);
		glVertex2f(190+x+XX,180+y+YY);
		glVertex2f(198+x+XX,200+y+YY);
		glVertex2f(190+x+XX,220+y+YY);
		}glEnd();
		}

		else{
		//blade22
		glColor3f(0.0,1,0.0);
		glBegin(GL_POLYGON);
		{
		glVertex2f(200+x+XX,201+y+YY);
		glVertex2f(220+x+XX,210+y+YY);
		glVertex2f(230+x+XX,200+y+YY);
		glVertex2f(220+x+XX,190+y+YY);
		glVertex2f(200+x+XX,198+y+YY);
		glVertex2f(180+x+XX,190+y+YY);
		glVertex2f(170+x+XX,200+y+YY);
		glVertex2f(180+x+XX,210+y+YY);
		
		}glEnd();
	}

			if(rot % 2==0)
		{
			//blade1
			glColor3f(0.0,1,0.0);
			glBegin(GL_LINE_LOOP);
			{
			glVertex2f(XX+73,YY+132);
			glVertex2f(XX+133,YY+130);	
			glVertex2f(XX+153,YY+125);
			glVertex2f(XX+133,YY+145);
			glVertex2f(XX+73,YY+135);
			glVertex2f(XX+13,YY+135);
			glVertex2f(XX-7,YY+115);
			glVertex2f(XX+13,YY+125);	
			
			}glEnd();
		}
		
		if(rot%2==1)	
		{

			//blade2
			glColor3f(1.0,0,0.0);
			glBegin(GL_POLYGON);
			{
			glVertex2f(XX+73,YY+132);
			glVertex2f(XX+133,YY+125);	
			glVertex2f(XX+153,YY+120);
			glVertex2f(XX+133,YY+140);
			glVertex2f(XX+73,YY+135);
			glVertex2f(XX+13,YY+140);
			glVertex2f(XX-7,YY+120);
			glVertex2f(XX+13,YY+125);	
			}glEnd();
		}		

	glFlush();
		}

void tree(int x, int y)
	{
		//rest1
		glColor3f(0.0,1,0);
		glBegin(GL_POLYGON);
		{
			glVertex2f(x+110,y+45 );
			glVertex2f(x+150,y+70 );
			glVertex2f(x+125,y+100 );
			glVertex2f(x+140,y+120);
			glVertex2f(x+105,y+170);
			glVertex2f(x+70,y+120 );
			glVertex2f(x+85,y+100);
			glVertex2f(x+60,y+70);
			glVertex2f(x+100,y+45 );
			glVertex2f(x+105,y+120);
		}glEnd();

		//stem1
		glColor3f(0.5,0.35,0.05);
		glBegin(GL_POLYGON);
		{
			glVertex2f(x+100,5 );
			glVertex2f(x+110,5 );
			glVertex2f(x+110,y+25 );
			glVertex2f(x+105,y+100);
			glVertex2f(x+100,y+25);
		}glEnd();

	}

void ball1( int r)
	{

		//glColor3f(1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 1.0, 0.0);
        int i=0,j=0;
        for(i=0;i<90000;i++)
        {
        	for(j=0;j<r;j++)
        	{
	        	glBegin(GL_POINTS);
	        	{	
	        		glVertex2f(XX+j*cos(i),j*sin(i)+YY);
	            }glEnd();
            }
        }
	}	

void ball(int x, int y, int r)
	{

		glColor3f(0, 0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 0.0, 0.0);
        int i=0,j=0;
        for(i=0;i<90000;i++)
        {
        	for(j=0;j<r;j++)
        	{
	        	glBegin(GL_POINTS);
	        	{	
	        		glVertex2f(x+j*cos(i),j*sin(i)+y);
	            }glEnd();
            }
        }
	}		



void cloud(int X, int Y)
	{
		ball(X+100,Y+100,20 );
		ball(X+100,Y+105,10 );
		ball(X+95,Y+100,30 );
		ball(X+110,Y+110,20);
		/*ball(X+ ,Y+ );
		ball(X+ ,Y+ );*/
	}

void mountain(int x, int y, int w)
	{
		glColor3f(0.5,0.35,0.05);
		glBegin(GL_POLYGON);
			{
				glVertex2f(120,0);
				glVertex2f(300,0);
				glVertex2f(200,300);
			}glEnd();
	}		

/*void Helipad()
	{
		glColor3f(0,1,1);
		glBegin(GL_POLYGON);
			{
				glVertex2f(500,0);
				glVertex2f(650,0);
				glVertex2f(650,100);
				glVertex2f(500,100);
			}glEnd();

				
		glColor3f(0,0,0);		
		glBegin(GL_LINES);
			{
				int i=0;
				for(i=500;i<650;i=i+15)
				{	
					glVertex2f(i,0);
					glVertex2f(i,100);
				}	

				for(i=0;i<100;i=i+15)
				{	
					glVertex2f(500,i);
					glVertex2f(650,i);
				}	
			}glEnd();
		}		*/


void Helipad()
	{
		glColor3f(0,1,1);
		glBegin(GL_POLYGON);
			{
				glVertex2f(500,0);
				glVertex2f(650,0);
				glVertex2f(650,100);
				glVertex2f(500,100);
			}glEnd();

		
		//dOOR fRAME		
		glColor3f(1,1,0);		
		glBegin(GL_POLYGON);
			{
				glVertex2f(550,1);
				glVertex2f(600,1);
				glVertex2f(600,80);
				glVertex2f(550,80);
			}glEnd();

		//DOOR
		glColor3f(.5,0.35,0.05);		
		glBegin(GL_POLYGON);
			{
				glVertex2f(550,1);
				glVertex2f(575,1);
				glVertex2f(575,60);
				glVertex2f(550,80);
			}glEnd();

		// hOME rOOF	
		glColor3f(1,0.35,0.05);		
		glBegin(GL_POLYGON);
			{
				glVertex2f(501,100);
				glVertex2f(651,100);
				glVertex2f(575,160);
			}glEnd();		

		
		/*glBegin(GL_LINES);
			{
				int i=0;
				for(i=500;i<650;i=i+15)
				{	
					glVertex2f(i,0);
					glVertex2f(i,100);
				}	

				for(i=0;i<100;i=i+15)
				{	
					glVertex2f(500,i);
					glVertex2f(650,i);
				}	
			}glEnd();*/
		}			

void backGround()
	{
		//Name();
		tree(0,0);
		tree(200,50);
		tree(300,10);
		tree(800,20);
		//cloud(100,100);
	}		

void SpecialKeys(int key, int x, int y)
	{
		if(key == GLUT_KEY_RIGHT)
			{
				XX = XX + delta;
			}
		else if(key == GLUT_KEY_LEFT)
			{
				XX = XX - delta;
			}

			
		else if(key == GLUT_KEY_UP)
			{
				if(YY < 750 )
				YY = YY + delta;
			}
				
	

		else if(key == GLUT_KEY_DOWN)
			{
				YY = YY - delta;
			}			
		glutPostRedisplay();	
	}

void Keys(unsigned char key, int x, int y)
	{
		if(key == '1')
			{
				speed=1;
			}
		else if(key == '2')
			{
				speed=2;
			}
		else if(key == '3')
			{
				speed=3;
			}		
		glutPostRedisplay();	
	}		

void Timer(int value)
{
	glutPostRedisplay();
	if(speed = 1)		
	glutTimerFunc(100,Timer,0);
    else if(speed == 2)
    glutTimerFunc(60,Timer,0);	
    else if(speed == 3)
    glutTimerFunc(1,Timer,0);	
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	
	rot++;	
	mountain(10,10,10);
	backGround();
	Name();
	Project();
	  
		hel();

	//}
	glEnd();

    Helipad();
	/*glBegin(GL_LINE_LOOP);  
	{
		

	}
	glEnd();*/	
		glFlush();
}


void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1200, 800);
	glutInitWindowPosition (300, 300);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutSpecialFunc(SpecialKeys);
	glutTimerFunc(0,Timer,0);
	glutKeyboardFunc(Keys);
	glutMainLoop();
}