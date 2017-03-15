#include<graphics.h>
void circlee(int radius,int xc,int yc)
{
     int p,x,y;
     void draw(int x,int y,int xc,int yc);
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
    
void semicirclee(int radius,int xc,int yc)
{
     int p,x,y;
     void sdraw(int x,int y,int xc,int yc);
     
     p=1-radius;
     x=0;
     y=radius;
     sdraw(x,y,xc,yc);
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
             sdraw(x,y,xc,yc);
      }
}                           
                 
                 
                   
void sdraw(int x,int y,int xc,int yc)
{
                             putpixel(xc+x,yc+y,12);
                             
                             putpixel(xc-x,yc+y,12);
                           
                              
                            
 }               
void draw(int x,int y,int xc,int yc)
{
                              putpixel(xc+x,yc+y,GREEN);
                              putpixel(xc+x,yc-y,12);
                              putpixel(xc-x,yc+y,5);
                              putpixel(xc-x,yc-y,RED);
                               putpixel(xc+y,yc+x,WHITE);
                              putpixel(xc-y,yc+x,YELLOW);
                              putpixel(xc+y,yc-x,3);
                              putpixel(xc-y,yc-x,BLUE);
                            
 }
 
 void bline(int xo, int yo, int xi, int yi)
 {
    int dx=xi-xo;
    int dy=yi-yo;
    int d=2*dy-dx;
    int incre=2*dy;
    int incrne=2*(dy-dx);
    int end;
    int x,y;
    if(xo>xi)
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
                            if(yo!=yi)
                                y--;
                           }
                    else
                    {
                        d+=incrne;
                        x++;
                            y++;
                        }
                    putpixel(x,y,WHITE);
                    }
                   
}
 int dda(int x1,int y1,int x2, int y2)
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
                                putpixel(x,y,WHITE);
            }
}
 int main()
 {
    int gDriver=DETECT,gMode;
     initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
     cleardevice();
     circlee(100,200,200);
     semicirclee(50, 200,200);
     bline(150,150,175,175);
     bline(125,175,150,150);
     bline(125,175,175,175);
   dda(125,175,175,175);
   
    bline(250,150,275,175);
     bline(225,175,250,150);
   bline(225,175,275,175);
     getch();
     return 0;
}
