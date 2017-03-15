
#include<graphics.h>
#include<stdio.h>

void drawline(int x1,int y1,int x2,int y2);

int main11()
{
    initwindow(500,500,"line");
    int x1=1,x2=100,y1=100,y2=100;
    
    int dx=x2-x1;
     int dy=y2-y1;
     
     int p=2*dy-dx;
     int cnt=0;
     int x,y;
     x=x1;
     y=y1;
     
     putpixel(x,y,10);
     
     while(x<x2)
     {
                  x++;
                  if(p<0)
                  {
                         y1++;
                         p+=(2*dy)-(2*dx);
                  }
                  else
                  {
                      p+=2*dy;
                  }
                  if(cnt!=20)
                  {
                             putpixel(x,y,10);
                             cnt+=1;
                  }
                  else
                  {      cnt=0;
                         x+=5;
                  }
     }
     delay(50000);
     return 0;
}          
