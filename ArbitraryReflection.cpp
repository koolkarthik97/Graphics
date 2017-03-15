#include<iostream>
#include<graphics.h>
#include<math.h>
#include<process.h>
using namespace std;
float b[10][3],a[10][3];
void dispp(int n, float c[][3])
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
  //  line(0, maxy, maxx*2,maxy);
   // line(maxx,0,maxx,maxy*2);
    setcolor(WHITE);
}
void mull(int n, float b[][3], float c[][3], float a[][3])
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
void reflection(int n, float c[][3]);
void translation(int n, float c[][3], float tx, float ty)
{
    int i;
    for(i=0;i<n;i++)
    {
        c[i][0] = c[i][0]+tx;
        c[i][1]=c[i][1]+ty;
    }
}
void rotation90(int n, float c[][3], float ra)
{
    int i=0,j;
    float b[10][3], xp, yp, a[10][3];
    xp = c[0][0];
    yp = c[0][1];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            b[i][j]=0;
    b[0][0]=cos(ra*3.14/180);
    b[1][1]=cos(ra*3.14/180);
    b[0][1]=sin(ra*3.14/180);
    b[1][0]=-sin(ra*3.14/180);
    b[2][0] = (-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
    b[2][1]= (-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
    b[2][2]=1;
    mull(n,b,c,a);
    setcolor(WHITE);
    dispp(n,a);
     reflection(n,a);
}
void invrotation90(int n, float c[][3], float ra)
{
    int i=0,j;
    float b[10][3], xp, yp, a[10][3];
    xp = c[0][0];
    yp = c[0][1];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            b[i][j]=0;
    b[0][0]=cos(ra*3.14/180);
    b[1][1]=cos(ra*3.14/180);
    b[0][1]=sin(ra*3.14/180);
    b[1][0]=-sin(ra*3.14/180);
    b[2][0] = (-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
    b[2][1]= (-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
    b[2][2]=1;
    mull(n,b,c,a);
    setcolor(WHITE);
    dispp(n,a);
   
}
void rotation(int n, float c[][3],float xp,float yp, float cos,float sin)
{
    int i=0,j;
    float b[10][3], a[10][3];
    //xp = c[0][0];
    //yp = c[0][1];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            b[i][j]=0;
    b[0][0]=cos;
    b[1][1]=cos;
    b[0][1]=sin;
    b[1][0]=-sin;
    b[2][0] = (-xp*cos)+(yp*sin)+xp;
    b[2][1]= (-xp*sin)-(yp*cos)+yp;
    b[2][2]=1;
    mull(n,b,c,a);
    setcolor(WHITE);
 //   dispp(n,a);
    rotation90(n,a,90);
 //   dispp(n,a);

}


void reflection(int n, float c[][3])
{
    int i=0,ch,j;
   ch=1;
    dispp(n,c);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            b[i][j]=0;
            if(i==j)
                b[i][j]=1;
        }
    switch(ch)
    {
            case 1: b[1][1]=-1;
                    break;
            default : break;
    }
    
    mull(n,b,c,a);
    setcolor(WHITE);
    dispp(n,a);
    invrotation90(n,a,-90);
    
}
int main()
{
        int i,j,k,cho,n,gd=DETECT,gm;
        float h;
        float c[10][3],tx,ty,sx,sy,ra;
        float d[10][3];
        initgraph(&gd,&gm,"");
        printf("Enter number of vertices\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("Enter coordinates of %d vertex \n",i+1);
            scanf("%f%f",&c[i][0],&c[i][1]);
            c[i][2]=1;
        }
        d[0][0]=20;
        d[0][1]=20;
        d[0][2]=1;
        d[1][0]=100;
        d[1][1]=100;
        d[1][2]=1;
        setcolor(GREEN);
        dispp(2,d);
        setcolor(WHITE);
        dispp(n,c);
        float xx1=d[0][0];
        float yy1=d[0][1];
        float xx2=d[1][0];
        float yy2=d[1][1];
        h= sqrt((xx2-xx1)*(xx2-xx1) + (yy2-yy1)*(yy2-yy1));
        cout<<h;
        float kk=xx2-xx1;
        float b=yy2-yy1;
        float cosi=-kk/h;
        float sini=-b/h;
        translation(n,c,-xx1,-yy1);
        dispp(n,c);
        rotation(n,c,xx1,yy1,cosi,sini);
       
       getch();
        return 0;
}
    
