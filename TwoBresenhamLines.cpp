#include<iostream>
#include<graphics.h>
using namespace std;
void bline(int xo,int yo,int xi, int yi)
{
    int dx=xi-xo;
    int dy=yi-yo;
    int d=2*dy-dx;
    int incre=2*dy;
    int incrne=2*(dy-dx);
    int x=xo;
    int y=yo;
    putpixel(x,y,5);
    while(x<xi){
                    if(d<0)
                    {
                           d+=incre;
                           x++;
                           y--;
                           }
                    else
                    {
                        d+=incrne;
                        x++;
                        y++;
                        }
                    putpixel(x,y,5);
                    }
}
int main9()
{
    initwindow(500,600,"bresenham");
   bline(100,100,200,200);
   bline(100,200,200,100);
    delay(50000);
    closegraph();
    return 0;
}    

