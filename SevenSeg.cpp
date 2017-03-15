#include<iostream.h>
#include <graphics.h>
#include<math.h>
int dda(int x1,int x2,int y1, int y2)
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
             
int main3( )
{
    initwindow(400, 300, "First Sample");
    int num;
    cout<<"enter the number to be displayed"<<endl;
    cin>>num;
    switch(num)
    {
               case 0:
               {
                                                        
                          dda(10,100,10,10);
                          dda(100,100,10,200);
                          dda(100,10,200,200);
                          dda(10,10,200,10);
                          break;
               }
               case 1:{
                     dda(100,100,10,200);
                          break;}
               case 2:{
                       dda(10,110,10,10);
                       dda(110,110,10,110);
                       
                       dda(10,110,110,110);
                       
                       
                       dda(10,10,110,210);
                       dda(10,110,210,210);
                       break;
                    }
                       
}
    while (!kbhit( ))
    {
        delay(200);
    }
    return 0;
}
