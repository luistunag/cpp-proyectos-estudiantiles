#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "odeint.h"
using namespace std;

void pendulodoble(double, double *, double *);

int main()
{
  double *ystart,x1,x2,eps,hmin,h1;
  int nvar,nok,nbad;
  nvar =4;
  ystart=new double[nvar];
  //inicialización de datos
  nok=0;
  nbad=0;
  h1=10;
  ystart[0]=M_PI/4;//theta 1 incial
  ystart[1]=M_PI/2;//theta 2 inicial
  ystart[2]=0.0;//momentum 1 inicial
  ystart[3]=-0.0;//momentum 2 inicial
  x1=0;//tiempo inicial
  x2=100;//tiempo final
  eps=1e-6;
  hmin=1e-6;
  odeint(ystart, nvar,x1,x2,eps,h1,hmin,&nok,&nbad,pendulodoble,rkqs);
  cout << "nok="<<nok <<"   "<<"nbad="<<nbad<<endl;
  delete [] ystart;
  return 0;
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
