#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void ddal(int x1,int y1,int x2, int y2)
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

int main()
{
    initwindow(800,800,"Transformation");
    int x1,y1,x2,y2,x3,y3,x4,y4;
    x1=100;
    y1=100;
    x2=300;
    y2=100;
    x3=300;
    y3=300;
    x4=100;
    y4=300;
    ddal(x1,y1,x2,y2);
    ddal(x2,y2,x3,y3);
    ddal(x3,y3,x4,y4);
    ddal(x4,y4,x1,y1);
    int tx,ty;
    printf("Enter translation factor\n");
    scanf("%d%d",&tx,&ty);
     x1+=tx;
     x2+=tx;
     x3+=tx;
     x4+=tx;
     y1+=ty;
     y2+=ty;
      y3+=ty;
       y4+=ty;
    
   ddal(x1,y1,x2,y2);
    ddal(x2,y2,x3,y3);
    ddal(x3,y3,x4,y4);
    ddal(x4,y4,x1,y1);
    getch();
    return 0;
}
