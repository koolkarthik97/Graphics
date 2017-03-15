#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void circlee(int radius,int xc,int yc);
void rotat(int n, float c[][3], float ra);
void multi(int n, float b[][3], float c[][3], float a[][3]);
void dis(int n, float c[][3])
{
    float maxx, maxy;
    int i;
    maxx= getmaxx();
    maxy= getmaxy();
    maxx/=2;
    maxy/=2;
    i=0;
    while(i<n-1)
    {
        line(maxx+c[i][0], maxy-c[i][1], maxx+c[i+1][0], maxy-c[i+1][1]);
        i++;
    }
    i=n-1;
    line(maxx+c[i][0], maxy-c[i][1], maxx+c[0][0], maxy-c[0][1]);
    setcolor(15);
    line(0, maxy, maxx*2,maxy);
    line(maxx,0,maxx,maxy*2);
    setcolor(WHITE);
}
int main()
{
     int gDriver=DETECT,gMode;
     initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
     int radius,xc,yc;
    // cout<<endl<<"enter centre point:";
    // cout<<endl<<"XC:";
    // cin>>xc;
    //  cout<<endl<<"YC:";
   //  cin>>yc;
   //  cout<<endl<<"radius:";
   //  cin>>radius;
     cleardevice();
     float c[10][3];
     int i;
     circlee(100,0,0);
     for(i=0;i<3;i++)
        {
            printf("Enter coordinates of %d vertex \n",i+1);
            scanf("%f%f",&c[i][0],&c[i][1]);
            c[i][2]=1;
        }
    dis(3,c);

        rotat(3,c,45);
     rotat(3,c,90);
      rotat(3,c,135);
       rotat(3,c,180);
        rotat(3,c,225);
         rotat(3,c,270);
          rotat(3,c,315);
           rotat(3,c,360);
     getch();
     return 0;
}
void multi(int n, float b[][3], float c[][3], float a[][3])
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
        {
            a[i][j]=0;
    }
    for(i=0;i<n;i++)
    for(j=0;j<3;j++)
     for(k=0;k<3;k++)
     {
            a[i][j]+=c[i][k]*b[k][j];
    }
}
void rotat(int n, float c[][3], float ra)
{
    int i=0,j;
    float b[10][3], xp, yp, a[10][3];
    xp = 0;//pivot point
   yp = 0;
  
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            b[i][j]=0;
   
        b[0][0]=cos(ra*3.14/180);
        b[1][1]=cos(ra*3.14/180);
        b[0][1]=sin(ra*3.14/180);
        b[1][0]=-sin(ra*3.14/180);
        b[2][0] = (-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
         b[2][1]= (-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
        // b[0][2]=50;//-(50*cos(ra*3.14/180))-(50*sin(ra*3.14/180));
      //  b[1][2]=50;//+(50*sin(ra*3.14/180))-(50*cos(ra*3.14/180));
         b[2][2]=1;
            multi(3,b,c,a);

    setcolor(WHITE);
    dis(n,a);
}
void circlee(int radius,int xc,int yc)
{
     int p,x,y;
    float maxx, maxy;
    int i;
    maxx= getmaxx();
    maxy= getmaxy();
    maxx/=2;
    maxy/=2;
    line(0, maxy, maxx*2,maxy);
    line(maxx,0,maxx,maxy*2);
     xc=maxx+xc;
     yc=maxy-yc;
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
                                                            
