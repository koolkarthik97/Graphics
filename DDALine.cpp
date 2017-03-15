#include<iostream>
#include<graphics.h>
int ddal(int x1,int x2,int y1, int y2)
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
      
int main4()
{
    initwindow(500,500,"lineDDA");
    ddal(100,400,200,500);
    delay(10000);
    return 0;
}
