#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define truckNumber 4
#define lanePoints 11

struct truck
{
    int oppositeTruckSide;
    float oppositeTruckY;
    int r, g, b;
}oppositeTrucks[truckNumber];

struct laneDivider
{
    int x;
    float y;
}laneDividers[lanePoints];

int random_gen(int minimum , int maximum){return (rand()%(maximum-minimum))+minimum;}
int truckSide = 0;
int truckMove = 0;
int point = 0;
int life = 3;
int count = 1;
float speed = 0.1;
void stringWrite(int x , int y , int font , char s[] , float r , float g , float b)
{
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    int len , i;
    len = (int)strlen(s);
        switch(font)
        {
            case 11: for(i=0;i<len;i++)
		    	        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , s[i]);
                    break;
            case 12: for(i=0;i<len;i++)
		    	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , s[i]);
                    break;
        }
}

void laneDividerGenerator()
{
    for(int i = 0 ; i<20 ; i++)
    {
        laneDividers[i].y=70*i;
    }
}

void truckGenerate()
{
    for(int i = 0 ; i<truckNumber ; i++)
    {
        oppositeTrucks[i].oppositeTruckSide = random_gen(0,3);
        oppositeTrucks[i].oppositeTruckY = 700+i*800*2;
        oppositeTrucks[i].r = random_gen(0,255);
        oppositeTrucks[i].g = random_gen(0,255);
        oppositeTrucks[i].b = random_gen(0,255);

        for (int j = 0; j < i; j++)
        {
            if (abs(oppositeTrucks[i].oppositeTruckY - oppositeTrucks[j].oppositeTruckY) < 250)
            {
                oppositeTrucks[i].oppositeTruckY += 250;
            }
        }
    }
}

void roadSide()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,0);
    glVertex2d(20,0);
    glVertex2d(20,10);
    glVertex2d(0,0);
    glEnd();

    glBegin(GL_POLYGON);
    glPopMatrix();
    glColor3ub(255,255,0);
    glVertex2d(0,0);
    glVertex2d(20,10);
    glVertex2d(20,45);
    glVertex2d(0,35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,35);
    glVertex2d(20,45);
    glVertex2d(20,80);
    glVertex2d(0,70);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,70);
    glVertex2d(20,80);
    glVertex2d(20,115);
    glVertex2d(0,105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,105);
    glVertex2d(20,115);
    glVertex2d(20,150);
    glVertex2d(0,140);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,140);
    glVertex2d(20,150);
    glVertex2d(20,185);
    glVertex2d(0,175);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,175);
    glVertex2d(20,185);
    glVertex2d(20,220);
    glVertex2d(0,210);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,210);
    glVertex2d(20,220);
    glVertex2d(20,255);
    glVertex2d(0,245);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,245);
    glVertex2d(20,255);
    glVertex2d(20,290);
    glVertex2d(0,280);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,280);
    glVertex2d(20,290);
    glVertex2d(20,325);
    glVertex2d(0,315);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,315);
    glVertex2d(20,325);
    glVertex2d(20,360);
    glVertex2d(0,350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,350);
    glVertex2d(20,360);
    glVertex2d(20,395);
    glVertex2d(0,385);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,385);
    glVertex2d(20,395);
    glVertex2d(20,430);
    glVertex2d(0,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,420);
    glVertex2d(20,430);
    glVertex2d(20,465);
    glVertex2d(0,455);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,455);
    glVertex2d(20,465);
    glVertex2d(20,500);
    glVertex2d(0,490);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,490);
    glVertex2d(20,500);
    glVertex2d(20,535);
    glVertex2d(0,525);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,525);
    glVertex2d(20,535);
    glVertex2d(20,570);
    glVertex2d(0,560);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,560);
    glVertex2d(20,570);
    glVertex2d(20,605);
    glVertex2d(0,595);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,595);
    glVertex2d(20,605);
    glVertex2d(20,640);
    glVertex2d(0,630);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,630);
    glVertex2d(20,640);
    glVertex2d(20,675);
    glVertex2d(0,665);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(0,665);
    glVertex2d(20,675);
    glVertex2d(20,700);
    glVertex2d(0,690);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(0,690);
    glVertex2d(20,700);
    glVertex2d(20,735);
    glVertex2d(0,725);
    glEnd();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,0);
    glVertex2d(600,0);
    glVertex2d(600,10);
    glVertex2d(580,0);
    glEnd();

    glBegin(GL_POLYGON);
    glPopMatrix();
    glColor3ub(255,255,0);
    glVertex2d(580,0);
    glVertex2d(600,10);
    glVertex2d(600,45);
    glVertex2d(580,35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,35);
    glVertex2d(600,45);
    glVertex2d(600,80);
    glVertex2d(580,70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,70);
    glVertex2d(600,80);
    glVertex2d(600,115);
    glVertex2d(580,105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,105);
    glVertex2d(600,115);
    glVertex2d(600,150);
    glVertex2d(580,140);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,140);
    glVertex2d(600,150);
    glVertex2d(600,185);
    glVertex2d(580,175);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,175);
    glVertex2d(600,185);
    glVertex2d(600,220);
    glVertex2d(580,210);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,210);
    glVertex2d(600,220);
    glVertex2d(600,255);
    glVertex2d(580,245);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,245);
    glVertex2d(600,255);
    glVertex2d(600,290);
    glVertex2d(580,280);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,280);
    glVertex2d(600,290);
    glVertex2d(600,325);
    glVertex2d(580,315);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,315);
    glVertex2d(600,325);
    glVertex2d(600,360);
    glVertex2d(580,350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,350);
    glVertex2d(600,360);
    glVertex2d(600,395);
    glVertex2d(580,385);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,385);
    glVertex2d(600,395);
    glVertex2d(600,430);
    glVertex2d(580,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,420);
    glVertex2d(600,430);
    glVertex2d(600,465);
    glVertex2d(580,455);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,455);
    glVertex2d(600,465);
    glVertex2d(600,500);
    glVertex2d(580,490);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,490);
    glVertex2d(600,500);
    glVertex2d(600,535);
    glVertex2d(580,525);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,525);
    glVertex2d(600,535);
    glVertex2d(600,570);
    glVertex2d(580,560);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,560);
    glVertex2d(600,570);
    glVertex2d(600,605);
    glVertex2d(580,595);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,595);
    glVertex2d(600,605);
    glVertex2d(600,640);
    glVertex2d(580,630);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,630);
    glVertex2d(600,640);
    glVertex2d(600,675);
    glVertex2d(580,665);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(580,665);
    glVertex2d(600,675);
    glVertex2d(600,700);
    glVertex2d(580,690);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2d(580,690);
    glVertex2d(600,700);
    glVertex2d(600,735);
    glVertex2d(580,725);
    glEnd();
    glPopMatrix();
}

void truck()
{
    glPushMatrix();
    glTranslatef(200.0*truckSide+100 , 100.0+truckMove , 0.0);
    glRotated(0,0,0,1);
    /*Rear Tyre 1*/
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-30,-35);
    glVertex2d(-30,-20);
    glVertex2d(30,-20);
    glVertex2d(30,-35);
    glEnd();
    /*Rear Tyre 2*/
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-30,-55);
    glVertex2d(-30,-40);
    glVertex2d(30,-40);
    glVertex2d(30,-55);
    glEnd();
    /*Front Tyre*/
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-30,10);
    glVertex2d(-30,25);
    glVertex2d(30,25);
    glVertex2d(30,10);
    glEnd();

    /*Truck Body*/
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex2d(-25,-60);
    glVertex2d(-25,30);
    glVertex2d(-15,40);
    glVertex2d(15,40);
    glVertex2d(25,30);
    glVertex2d(25,-60);
    glEnd();

    /*Truck front*/
    glBegin(GL_LINES);
    glColor3ub(15,92,13);
    glVertex2d(-15,40);
    glVertex2d(-5,20);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(15,92,13);
    glVertex2d(15,40);
    glVertex2d(5,20);
    glEnd();

    /*Truck top*/
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2d(-15,-5);
    glVertex2d(-15,10);
    glVertex2d(15,10);
    glVertex2d(15,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);
    glVertex2d(-23,-58);
    glVertex2d(-23,-10);
    glVertex2d(23,-10);
    glVertex2d(23,-58);
    glEnd();

    //truck lagguage
    glBegin(GL_POLYGON);
    glColor3ub(200,173,123);
    glVertex2d(-20,-33);
    glVertex2d(-20,-13);
    glVertex2d(20,-13);
    glVertex2d(20,-33);
    glEnd();

    /*Truck Luggage*/
    for(int i=-20;i<15;i+=11)
    {
        glBegin(GL_POLYGON);
        glColor3ub(200,173,123);
        glVertex2d(i,-53);
        glVertex2d(i,-43);
        glVertex2d(i+8,-43);
        glVertex2d(i+8,-53);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(-15,11);
    glVertex2d(-23,24);
    glVertex2d(23,24);
    glVertex2d(15,11);
    glEnd();

    /*Front window frame*/
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(-15,11);
    glVertex2d(-23,24);
    glVertex2d(23,24);
    glVertex2d(15,11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(-15,11);
    glVertex2d(-23,24);
    glVertex2d(23,24);
    glVertex2d(15,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(-22,-5);
    glVertex2d(-22,19);
    glVertex2d(-17,9);
    glVertex2d(-17,-5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(-22,-5);
    glVertex2d(-22,19);
    glVertex2d(-17,9);
    glVertex2d(-17,-5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(18,-5);
    glVertex2d(18,10);
    glVertex2d(23,20);
    glVertex2d(23,-5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(18,-5);
    glVertex2d(18,10);
    glVertex2d(23,20);
    glVertex2d(23,-5);
    glEnd();
    glPopMatrix();
}

void oppositeTruck(int i)
{
    glPushMatrix();
    glTranslatef(oppositeTrucks[i].oppositeTruckSide*200+100,oppositeTrucks[i].oppositeTruckY-=speed*1.0 , 0.0);
    glRotated(0,0,0,1);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-30,-35);
    glVertex2d(-30,-20);
    glVertex2d(30,-20);
    glVertex2d(30,-35);
    glEnd();
    /*Rear tyre 1*/
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-30,10);
    glVertex2d(-30,25);
    glVertex2d(30,25);
    glVertex2d(30,10);
    glEnd();
    /*Rear tyre 2*/
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2d(-30,-55);
    glVertex2d(-30,-40);
    glVertex2d(30,-40);
    glVertex2d(30,-55);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(oppositeTrucks[i].r,255,oppositeTrucks[i].b);
    glVertex2d(-25,-60);
    glVertex2d(-25,30);
    glVertex2d(-15,40);
    glVertex2d(15,40);
    glVertex2d(25,30);
    glVertex2d(25,-60);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,oppositeTrucks[i].g,0);
    glVertex2d(-15,-5);
    glVertex2d(-15,10);
    glVertex2d(15,10);
    glVertex2d(15,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);
    glVertex2d(-23,-58);
    glVertex2d(-23,-10);
    glVertex2d(23,-10);
    glVertex2d(23,-58);
    glEnd();

    //truck lagguage
    glBegin(GL_POLYGON);
    glColor3ub(200,173,123);
    glVertex2d(-20,-33);
    glVertex2d(-20,-13);
    glVertex2d(20,-13);
    glVertex2d(20,-33);
    glEnd();

    /*Truck Luggage*/
    for(int i=-20;i<15;i+=11)
    {
        glBegin(GL_POLYGON);
        glColor3ub(200,173,123);
        glVertex2d(i,-53);
        glVertex2d(i,-43);
        glVertex2d(i+8,-43);
        glVertex2d(i+8,-53);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(-15,11);
    glVertex2d(-23,24);
    glVertex2d(23,24);
    glVertex2d(15,11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(-15,11);
    glVertex2d(-23,24);
    glVertex2d(23,24);
    glVertex2d(15,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(-22,-5);
    glVertex2d(-22,19);
    glVertex2d(-17,9);
    glVertex2d(-17,-5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(-22,-5);
    glVertex2d(-22,19);
    glVertex2d(-17,9);
    glVertex2d(-17,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(18,-5);
    glVertex2d(18,10);
    glVertex2d(23,20);
    glVertex2d(23,-5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(18,-5);
    glVertex2d(18,10);
    glVertex2d(23,20);
    glVertex2d(23,-5);
    glEnd();
    glPopMatrix();
}

void road()
{
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2d(20,0);
    glVertex2d(20,700);
    glVertex2d(580,700);
    glVertex2d(580,0);
    glEnd();
}

void laneDivider()
{
    for(int i=0 ; i<lanePoints ; i++)
    {
        glPushMatrix();
        glTranslatef(200,laneDividers[i].y,0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2d(0,0);
        glVertex2d(0,40);
        glVertex2d(10,40);
        glVertex2d(10,0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(400,laneDividers[i].y,0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2d(0,0);
        glVertex2d(0,40);
        glVertex2d(10,40);
        glVertex2d(10,0);
        glEnd();
        glPopMatrix();
        laneDividers[i].y-=speed;
        if(laneDividers[i].y<-70)
        {
            laneDividers[i].y = 700;
            point++;
        }
    }
}

static void idle(void)
{
    for(int i= 0 ; i<truckNumber ; i++)
    {
        if(oppositeTrucks[i].oppositeTruckY<=-200)
        {
            oppositeTrucks[i].oppositeTruckSide = random_gen(0,3);
            oppositeTrucks[i].oppositeTruckY = 800;
        }
        if(oppositeTrucks[i].oppositeTruckSide == truckSide)
        {
            if(oppositeTrucks[i].oppositeTruckY<=truckMove+200 && oppositeTrucks[i].oppositeTruckY>=truckMove-5)
            {
                life--;
                oppositeTrucks[i].oppositeTruckY = 800+50;
            }
        }
    }
    glutPostRedisplay();
    count++;
    if(count%100==0)
    {
        speed+=.1;
    }
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    road();
    roadSide();
    laneDivider();
    truck();
    for(int i = 1 ; i<truckNumber ; i++)
    {
        oppositeTruck(i);
    }
    char str1[40];
    char str[] = "Score: ";
    sprintf(str1,"%d",point);
    strcat(str,str1);
    stringWrite(440,660,11,str,1,0.25,0);
    char str3[40];
    char str2[] = "Life: ";
    sprintf(str3,"%d",life);
    strcat(str2,str3);
    stringWrite(40,660,11 ,str2,1,0,1);
    if(life==0)
    {
        glutIdleFunc(NULL);
        stringWrite(250,330,12,"Game Over",1,0,0);
        stringWrite(230,300,12,"Press R to restart",0,1,0);
    }
    glutSwapBuffers();
}
void special(int key , int x , int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
            if(truckSide>0)
                {
                    truckSide--;
                }
            break;
        case GLUT_KEY_RIGHT:
            if(truckSide<2)
            {
                truckSide++;
            }
            break;
        case GLUT_KEY_UP:
            if(truckMove<600)
            {
                truckMove+=50;
            }
            break;
        case GLUT_KEY_DOWN:
            if(truckMove>0)
            {
                truckMove-=50;
            }
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key , int x , int y)
{
    switch(key)
    {
        case 'r':
            if(life==0)
            {
                life = 3;
                speed = 1;
                point = 0;
                truckMove = 0;
                truckSide = 1;
                glutIdleFunc(idle);
            }
            break;
        default:
            break;
    }
}

int main(int argc , char *argv[])
{
    glutInit(&argc , argv);
    truckGenerate();
    laneDividerGenerator();
    glutInitWindowSize(600,700);
    glutInitWindowPosition(400,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Truck Racing Game ");
    glutSpecialFunc(special);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    point = 0;
    truckMove = 0.0;
    glClearColor(1,1,1,1);
    glOrtho(0,600,0,700,0,600);
    glutMainLoop();
    return EXIT_SUCCESS;
}
