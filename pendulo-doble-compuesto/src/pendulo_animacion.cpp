#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
 
using namespace std;
void RK4(double *, double *, double , double , int ,void (*derivs)(double,double*,double*));
void derivada(double , double *, double *);
void pendulodoble(double , double*, double*);

int main()
{
double *y,x,h,*ynueva;
int i,Niteraciones,out1,nvar;
nvar=4;
out1=100;
y=new double[nvar];
ynueva= new double[nvar];
FILE *out;

//inicializar

h=1e-4;
x=0.0;
y[0]=M_PI/4;//theta 1 inicial
y[1]=M_PI/2;//theta 2 inicial
y[2]=0.0;//momentum 1 inicial
y[3]=0.0;//momentum 2 inicial
ynueva[0]=0.0;
ynueva[1]=0.0;
ynueva[2]=0.0;
ynueva[3]=0.0;
Niteraciones =1000e3;
out=fopen("animation.dat","w");
 fprintf( out, "%f\t%.16f\t%.16f\t%.16f\t%.16f\t%f\n%f\t%.16f\t%.16f\t%.16f\t%.16f\t%f\n", 1000.0,0.2*sin(y[0]),-0.2*cos(y[0]),0.2*sin(y[1])+0.2*sin(y[0]),-0.2*cos(y[1])-0.2*cos(y[0]),x, 0.0,0.0,0.0, 0.2*sin(y[0]),-0.2*cos(y[0]),x);

for (i=1; i<=Niteraciones; i++)
{
  RK4(ynueva, y,x,h,nvar,pendulodoble);
x=x+h;
y[0]=ynueva[0];
y[1]=ynueva[1];
y[2]=ynueva[2];
y[3]=ynueva[3];
if(i % out1 == 0)
  fprintf( out, "%f\t%.16f\t%.16f\t%.16f\t%.16f\t%f\n%f\t%.16f\t%.16f\t%.16f\t%.16f\t%f\n", 1001.0+i, 0.2*sin(y[0]),-0.2*cos(y[0]),0.2*sin(y[1])+0.2*sin(y[0]),-0.2*cos(y[1])-0.2*cos(y[0]),x, 0.0,0.0,0.0, 0.2*sin(y[0]),-0.2*cos(y[0]),x);
}

fclose(out);
delete [] y;
delete [] ynueva;
return 0;

}


void RK4(double *ynueva, double *y, double x, double h, int nvar,void(*derivs)(double x, double *y,double *dxdt))
{
double *k0,*k1,*k2,*k3,*z;
k0=new double[nvar];
k1=new double[nvar];
k2=new double[nvar];
k3=new double[nvar];
z=new double[nvar];

 (*derivs)(x,y,k0);

for(int i=0; i<nvar; i++)
z[i]=y[i]+k0[i]*h/2;
(*derivs)(x+h/2,z,k1);

for(int i=0; i<nvar; i++)
z[i]=y[i]+k1[i]*h/2;
 (*derivs)(x+h/2,z,k2);

for(int i=0; i<nvar; i++)
z[i]=y[i]+k2[i]*h;
 (*derivs)(x+h,z,k3);

for(int i=0; i<nvar; i++)
ynueva[i]=y[i]+(h/6)*(k0[i]+2*k1[i]+2*k2[i]+k3[i]);

delete [] k0;
delete [] k1;
delete [] k2;
delete [] k3;
delete [] z;
}



void pendulodoble(double x, double *y, double *dxdt)
{
  const double m=0.1;
  const double g=9.8;
  const double l=0.2;

  //y[0]posición barra 1 theta 1
  //y[1]//posición barra 2 theta 2
  //y[2]//momentum barra 1 p1
  //y[3]//momentum barra 2 p2
  
  dxdt[0]=(6/(m*l*l))*(2*y[2]-3*y[3]*cos(y[0]-y[1]))/(16-9*pow(cos(y[0]-y[1]),2));
  dxdt[1]=(6/(m*l*l))*(8*y[3]-3*y[2]*cos(y[0]-y[1]))/(16-9*pow(cos(y[0]-y[1]),2));
  dxdt[2]=-(0.5*m*l*l)*(dxdt[0]*dxdt[1]*sin(y[0]-y[1])+3*(g/l)*sin(y[0]));
  dxdt[3]=-(0.5*m*l*l)*(-dxdt[0]*dxdt[1]*sin(y[0]-y[1])+(g/l)*sin(y[1]));
  
}


