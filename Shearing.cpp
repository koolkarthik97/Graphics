#include<iostream>
#include<graphics.h>
#include<math.h>
#include<process.h>
using namespace std;
void disp(int n, float c[][3])
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
void mul(int n, float b[][3], float c[][3], float a[][3])
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
void shearing(int n, float c[][3])
{
    float b[10][3], sh, a[10][3];
    int i=0,ch,j;
   // cleardevice();
    printf("1.X AXIS\n2.Y AXIS\nEnter the choice\n");
    scanf("%d",&ch);
    printf("Enter shear value\n");
    scanf("%f",&sh);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            b[i][j]=0;
    for(i=0;i<3;i++)
        b[i][i]=1;
    switch(ch)
    {
        case 1: b[1][0] = sh;
                break;
        case 2: b[0][1]=sh;
                break;
        default : break;
    }
    mul(n,b,c,a);
    disp(n,a);
}
int main1()
{
    int i,j,k,cho,gd=DETECT,gm,n;
    float c[10][3],tx,ty,sx,sy,ra;
    initgraph(&gd,&gm,"");
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter coordinates %d",i+1);
        scanf("%f%f",&c[i][0],&c[i][1]);
        c[i][2]=1;
    }
    setcolor(BLUE);
    disp(n,c);
    setcolor(WHITE);
    shearing(n,c);
    getch();
    closegraph();
      return 0;
}

