#include<stdio.h>
#include<conio.h>
//#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
int pixels[2][4];
float xn1,xn2,yn1,yn2,x3,y3,m;
int xmin,ymin,xmax,ymax,x1,y1,x2,y2;
int choice,ed[20],num;
void su_co(int x1,int y1,int x2, int y2, int xmin, int ymin, int xmax, int ymax)
{
    int i,j,fl;
    for(i=0;i<2;i++)
        for(j=0;j<4;j++)
            pixels[i][j]=0;
    if(y1>ymax)
        pixels[0][0]=1;
    if(y1<ymin)
        pixels[0][1]=1;
    if(x1>xmax)
        pixels[0][2]=1;
    if(x1<xmin)
        pixels[0][3]=1;
    if(y2>ymax)
        pixels[1][0]=1;
    if(y2<ymin)
        pixels[1][1]=1;
    if(x2>xmax)
        pixels[1][2]=1;
    if(x2<xmin)
        pixels[1][3]=1;
    for(j=0;j<4;j++)
    {
        if(pixels[0][j]==0 && pixels[1][j]==0)
            continue;
        if(pixels[0][j]==1 && pixels[1][j]==1)
        {
            fl=3;
            break;
        }
        fl=2;
    }
    switch(fl)
    {
        case 1:line(320+x1,240-y1,320+x2,240-y2);
                break;
        case 2: m=(y2-y1)/(x2-x1);
                xn1=x1;
                yn1=y1;
                break;
        case 3:printf("Not visible");
                break;
        default:break;
    }
}
    
