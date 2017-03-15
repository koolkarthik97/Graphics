#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
void circler(int radius,int xc,int yc);
int main12()
{
     int gDriver=DETECT,gMode;
     initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
     int radius,xc,yc;
     cout<<endl<<"enter centre point:";
     cout<<endl<<"XC:";
     cin>>xc;
      cout<<endl<<"YC:";
     cin>>yc;
     cout<<endl<<"radius:";
     cin>>radius;
     cleardevice();
     circler(radius,xc,yc);
     getch();
     return 0;
}
void circler(int radius,int xc,int yc)
{
     int p,x,y;
     void drawl(int x,int y,int xc,int yc);
     p=1-radius;
     x=0;
     int cnt=0;
     y=radius;
     drawl(x,y,xc,yc);
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
             drawl(x,y,xc,yc);
            if(cnt==1||cnt==0)
    	       x+=2;
    	    if(cnt==9)
    	       cnt=0;
    	    else
    	       cnt++;
      }
}
                               
                 
                 
                 
void drawl(int x,int y,int xc,int yc)
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
                                                            
