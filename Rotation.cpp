#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int t;
void dda(float x1,float y1,float x2, float y2)
{
            int x,y,k,steps,xc,yc,dx,dy;
            dx=x2-x1;
            dy=y2-y1;
            if(abs(dx)>abs(dy))
            steps=abs(dx);
            else
            steps=abs(dy);
            xc=(dx/steps);
            yc=(dy/steps);
            x=x1;
            y=y1;
            for(k=1;k<=steps;k++)
            {
                                x=xc+x;
                                y=yc+y;
                                circle(x,y,3);
            }
}


int main2()
{
    initwindow(1000,1000,"Transformation");
    int x1,y1,x2,y2,x3,y3,x4,y4;
      int nx1,ny1,nx2,ny2,nx3,ny3,nx4,ny4;
     x1=100;
    y1=150;
    x2=150;
    y2=200;
    x3=50;
    y3=200;
    
    line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
  line(x3,y3,x1,y1);
  //dda(x4,y4,x1,y1);
    int ang;
    printf("Enter rotation factor\n");
    scanf("%d",&ang);
    float t= (3.14*ang)/180;
 
    float t1=cos(t);
    float t2=sin(t);
    nx1=  abs(x1*t1-y1*t2);
    nx2=  abs(x2*t1-y2*t2);
   nx3= abs(x3*t1-y3*t2);
//  nx4=rotatex(x4,y4);
     ny1=  abs(x1*t2+y1*t1);
    ny2=  abs(x2*t2+y2*t1);
   ny3= abs(x3*t2+y3*t1);
//   ny4=rotatey(x4,y4);
  
    printf("%d %d\n%d %d\n%d %d\n%d %d\n",nx1,ny1,nx2,ny2,nx3,ny3,nx4,ny4);
      //printf("\n%f %f\n",cos(s),sin(s));
    line(nx1,ny1,nx2,ny2);
   line(nx2,ny2,nx3,ny3);
   line(nx3,ny3,nx1,ny1);
 //   dda(nx4,ny4,nx1,ny1);
    printf("Enter coordinates");
    int xr,yr;
    scanf("%d%d",&xr,&yr);
    int mx1,mx2,mx3,my1,my2,my3;
     mx1= xr+ abs((x1-xr)*cos(t)-(y1-yr)*sin(t));
    mx2=  xr+abs((x2-xr)*cos(t)-(y2-yr)*sin(t));
   mx3= xr+abs((x3-xr)*cos(t)-(y3-yr)*sin(t));
//  nx4=rotatex(x4,y4);
     my1= yr+ abs((x1-xr)*sin(t)+(y1-yr)*cos(t));
    my2= yr+ abs((x2-xr)*sin(t)+(y2-yr)*cos(t));
   my3= yr+ abs((x3-xr)*sin(t)+(y3-yr)*cos(t));
   line(mx1,my1,mx2,my2);
   line(mx2,my2,mx3,my3);
   line(mx3,my3,mx1,my1);
    printf("%d %d\n%d %d\n%d %d\n\n",mx1,my1,mx2,my2,mx3,my3);
    getch();
    return 0;
}
