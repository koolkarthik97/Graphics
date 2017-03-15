#include<iostream>
#include<graphics.h>
using namespace std;
void bbline(int xo, int yo, int xi, int yi)
 {
    int dx=xi-xo;
    int dy=yi-yo;
    int d=2*dy-dx;
    int incre=2*dy;
    int incrne=2*(dy-dx);
    int end;
    int x,y;
    if(xo>xi || yo>yi)
    {
        x=xi;
        y=yi;
        end=xo;
    }
    else
    {
        x=xo;
        y=yo;
        end=xi;
    }
     putpixel(x,y,5);
    while(x<=end){
                    if(d<0)
                    {
                           d+=incre;
                           x++;
                            if(yo!=yi) //for horizontal line yo=yi
                                y--; //for neg slope and not horizontal line
                           }
                    else
                    {
                        d+=incrne;
                        x++;
                        if(yo!=yi)
                            y++;
                        }
                    putpixel(x,y,WHITE);
                    }
                   
}
int main()
{
    initwindow(500,600,"bresenham");
    int xo,yo,xi,yi;
    cout<<"enter first coordinates"<<endl;
    cin>>xo>>yo;
    cout<<"enter second coordinates"<<endl;
    cin>>xi>>yi;
    bbline(xo,yo,xi,yi);
                    delay(50000);
                    closegraph();
                    return 0;
}    

