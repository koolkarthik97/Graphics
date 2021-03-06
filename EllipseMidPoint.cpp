#include<stdio.h>
#include<graphics.h>

void ellipse(int xc, int yc, int rx, int ry)
{
    int gm= DETECT, gd;
    int x,y,p;
//    clrscr();
    initgraph(&gm, &gd, "C:\\TC\\BGI");
    x=0;
    y=ry;
    p = (ry*ry) - (rx*rx*ry) + ((rx*rx)/4);
    while((2*x*ry*ry) < (2*y*rx*rx))
    {
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
    
        if(p<0)
        {
                x++;
                p += (2*ry*ry*x) +(ry*ry);
        }
        else
        {
                x++;
                y--;
                p += (2*ry*ry*x + ry*ry) - (2*rx*rx*y);
        }
    }
    p = ((float)x+0.5)*((float)x+0.5)*ry*ry + ((y-1)*(y-1)*rx*rx) - (rx*rx*ry*ry);
    while(y>=0)
    {
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        
        if(p>0)
        {
            y--;
            p-=(2*rx*rx*y) + (rx*rx);
        }
        else
        {
            y--;
            x++;
            p+=(2*ry*ry*x) - (2*rx*rx*y) - (rx*rx);
        }
    }
    getch();
    closegraph();
}
int main()
{
    int xc,yc,rx,ry;
    printf("Enter center, x axis and y axis");
    scanf("%d%d%d%d",&xc,&yc,&rx,&ry);
    ellipse(xc,yc,rx,ry);
    getch();
    return 0;
}
