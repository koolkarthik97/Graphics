#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void ddall(int x1,int y1,int x2, int y2)
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

int main3()
{
    initwindow(1000,1000,"Transformation");
    int x1,y1,x2,y2,x3,y3;
    x1=200;
    y1=200;
    x2=200;
    y2=100;
    x3=100;
    y3=200;
    int nx1,nx2,nx3,ny1,ny2,ny3;
    ddall(x1,y1,x2,y2);
    ddall(x3,y3,x2,y2);
    ddall(x1,y1,x3,y3);
    int tx,ty;
    printf("Enter scaling factor\n");
    scanf("%d%d",&tx,&ty);
     x1*=tx;
     x2*=tx;
     x3*=tx;
    y1*=ty;
     y2*=ty;
    y3*=ty;
    ddall(x1,y1,x2,y2);
    ddall(x3,y3,x2,y2);
    ddall(x1,y1,x3,y3);
    int xf,yf;
    printf("Enter coordinates\n");
    scanf("%d%d",&xf,&yf);
    int mx1,mx2,mx3,my1,my2,my3;
    mx1= x1+ xf*(1-tx);
    mx2= x2+ xf*(1-tx);
    mx3= x3+ xf*(1-tx);
    
    my1= y1+ yf*(1-ty);
    my2= y2+ yf*(1-ty);
    my3= y3+ yf*(1-ty);
    printf("\n%d %d\n%d %d\n%d %d\n",mx1,my1,mx2,my2,mx3,my3);
     ddall(mx1,my1,mx2,my2);
    ddall(mx3,my3,mx2,my2);
    ddall(mx1,my1,mx3,my3);
    getch();
    return 0;
}
