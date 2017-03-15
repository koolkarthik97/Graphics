#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
/*float x1=100,y1=100,x2=100,y2=300;
float x,y,dx,dy,step,xinc,yinc;
int k;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
	step=abs(dx);
else
	step=abs(dy);
xinc=dx/step;
yinc=dy/step;

x=x1;
y=y1;

putpixel(x,y,1);
for(k=0;k<step;k++)
	{
	x+=xinc;
	y+=yinc;
	putpixel(x,y,1);
	}
*/
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
line(getmaxx()/2,0,getmaxx()/2,getmaxy());
getch();
return 0;
}
