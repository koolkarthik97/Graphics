#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void draw(int x,int y,int xc,int yc);
void circlee(int radius,int xc,int yc);
int main()
{
     int gDriver=DETECT,gMode;
     initgraph(&gDriver,&gMode,"");
     int radius,xc,yc;
     cout<<endl<<"enter centre point:";
     cout<<endl<<"XC:";
     cin>>xc;
      cout<<endl<<"YC:";
     cin>>yc;
     cout<<endl<<"radius:";
     cin>>radius;
     cleardevice();
     circlee(radius,xc,yc);
     getch();
     return 0;
}
void circlee(int radius,int xc,int yc)
{
     int p,x,y;
     p=1-radius;
     x=0;
     y=radius;
     draw(x,y,xc,yc);
     while(x<=y)
     {
             x++;
             if(p<0)
             {
                    p+=2*x+1;
             }
             else
             {
                    p+=2*(x-y)+1;
                    y--;
             }
             draw(x,y,xc,yc);
      }
}
                               
                 
                 
                 
void draw(int x,int y,int xc,int yc)
{
                              putpixel(xc+x,yc+y,12);
                              putpixel(xc+x,yc-y,12);
                              putpixel(xc-x,yc+y,12);
                              putpixel(xc-x,yc-y,12);
                               putpixel(xc+y,yc+x,12);
                              putpixel(xc-y,yc+x,12);
                              putpixel(xc+y,yc-x,12);
                              putpixel(xc-y,yc-x,12);
                            
 }
                                                            
