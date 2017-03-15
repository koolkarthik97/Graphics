
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

typedef float Matrix3x3 [3][3];
Matrix3x3 theMatrix;
int NEdges;
float ptsIni[20][2];
float ptsFin[20][2];
float refpt[2];
float RotAngle;
float TransDistX,TransDistY;
float ScaleX,ScaleY;
int choice,choiceRef,choiceShear;
float slope,yIntercept;
float shearValue;

void matrixSetIdentity(Matrix3x3 m)
// Initialises the matrix as Unit Matrix
{
   int i, j;
   for (i=0; i<3; i++)
   for (j=0; j<3; j++)
   m[i][j] = (i == j);
}

void matrixPreMultiply(Matrix3x3 a , Matrix3x3 b)
// Multiplies matrix a times b, putting result in b
{
   int i,j;
   Matrix3x3 tmp;
   for (i = 0; i < 3; i++)
     for (j = 0; j < 3; j++)
       tmp[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j];
   for (i = 0; i < 3; i++)
     for (j = 0; j < 3; j++)
       theMatrix[i][j] = tmp[i][j];
}

void Translate(int tx, int ty)
{
   Matrix3x3 m;
   matrixSetIdentity(m);
   m[0][2] = tx;
   m[1][2] = ty;
   matrixPreMultiply(m, theMatrix);
}

void Scale(float sx , float sy)
{
   Matrix3x3 m;
   matrixSetIdentity(m);
   m[0][0] = sx;
   m[0][2] = (1 - sx)*refpt[0];
   m[1][1] = sy;
   m[1][2] = (1 - sy)*refpt[1];
   matrixPreMultiply(m , theMatrix);
}

void Rotate(float a)
{
   Matrix3x3 m;
   matrixSetIdentity(m);
   a = a*22/1260;
   m[0][0] = cos(a);
   m[0][1] = -sin(a) ;
   m[0][2] = refpt[0]*(1 - cos(a)) + refpt[1]*sin(a);
   m[1][0] = sin(a);
   m[1][1] = cos(a);
   m[1][2] = refpt[1]*(1 - cos(a)) - refpt[0]*sin(a);
   matrixPreMultiply(m , theMatrix);
}

void Reflect(int xy)
{
   Matrix3x3 m;
   matrixSetIdentity(m);
   if(xy == 2)
   m[1][1] = -1;
   if(xy == 3)
   m[0][0] = -1;
   matrixPreMultiply(m , theMatrix);
}

void Shear(int xy)
{
   Matrix3x3 m;
   matrixSetIdentity(m);
   if(xy == 1)
     m[0][1] = shearValue;
   if(xy == 2)
     m[1][0] = shearValue;
   matrixPreMultiply(m , theMatrix);
}void TransformPoints(void)
{
   int k;
   float tmp ;
   for (k = 0 ; k ");
  scanf("%d",&NEdges);
  printf("Enter %d Co-ordinate pairs \n",NEdges);
  int PlotCt;
  for(PlotCt=0 ; PlotCt");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:     printf("Enter reference point Co-ordinates:\n=>");
      scanf("%f %f",&refpt[0],&refpt[1]);
      printf("Enter Angle of Rotation\n=>");
      scanf("%f",&RotAngle);
      printf("Enter translation along X & Y\n=>");
      scanf("%f%f",&TransDistX , &TransDistY);
      printf("Enter Scaling ratios along X & Y\n=>");
      scanf("%f%f",&ScaleX , &ScaleY);
      break;
    case 2:     printf("Enter translation along X & Y\n=>");
      scanf("%f%f",&TransDistX , &TransDistY);
      break;
    case 3:     printf("Enter Angle of Rotation\n=>");
      scanf("%f",&RotAngle);
      printf("Enter reference point Co-ordinates:\n=>");
      scanf("%f %f",&refpt[0],&refpt[1]);
      break;
    case 4:     printf("Enter Scaling ratios along X & Y\n=>");
      scanf("%f%f",&ScaleX , &ScaleY);
      break;
    case 5:     printf("Enter your choice number for Reflection about:\n
                    1.Origin\n 2.X-axis\n 3.Y-axis\n 4.y = mx+c\n=>");
      scanf("%d",&choiceRef);
      if(choiceRef == 4)
      {
        printf("Enter m & c: \n=>");
        scanf("%f %f",&slope,&yIntercept);
      }
      break;      
    case 6:     printf("Enter your choice number to shear about:\n
                    1.x-axis\n 2.y-axis\n=>");
      scanf("%d",&choiceShear);
      printf("Enter shear value:\n=>");
      scanf("%f",&shearValue);
      break;
    default:    printf("Please enter a valid choice!!!\n");
      return 0;
  }
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
