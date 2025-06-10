#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define S1 94//Kcal/(mol-Ansgtrom^4)
#define S2 42//Kcal/mol
#define b 1 //ansgtrom
#define m1 16//masa oxigeno uma
#define m2 1//masa hidrogeno 1 uma
#define m3 1//masa hidrogeno 2 uma
#define thetabar 1.9106332 //theta barra
using namespace std;
void RK4(double *, double *, double , double , int ,void (*derivs)(double,double*,double*));
void molecula(double , double*, double*);

int main()
{
 double *y,x,h,*ynueva;
 int i,Niteraciones,out1,nvar;

 nvar=12;
 y=new double[nvar];
 ynueva= new double[nvar];
 out1=1;
 FILE *out;

//inicializacion de datos

 h=0.005;//tamaño de paso
 
 x=0.0;//tiempo inical
 
 y[0]=2.0;//velocidad inicial x hidrogeno 1
 y[1]=2.0;//velocidad inicial y  hidrogeno 1
 y[2]=1.00;//velocidad inicial x hidrogeno 2
 y[3]=2.0;//velocidad inicial y hidrogeno 2
 y[4]=2.9;//posicion inicial x hidrogeno 1
 y[5]=3.9;//posicion inicial y hidrogeno 1
 y[6]=3.9;//posicion inicial x hidrogeno 2 
 y[7]=2.8;//posicion inicial y hidrogeno 2
 y[8]=0.0;//velocidad inicial x oxigeno
 y[9]=0.0;//velocidad inicial y oxigeno 
 y[10]=3.0;//posicion inical x oxigeno 
 y[11]=3.0;//posicion inical y oxigeno

 ynueva[0]=0.0;
 ynueva[1]=0.0; 
 ynueva[2]=0.0;
 ynueva[3]=0.0;
 ynueva[4]=0.0;
 ynueva[5]=0.0;
 ynueva[6]=0.0;
 ynueva[7]=0.0;
 ynueva[8]=0.0;
 ynueva[9]=0.0;
 ynueva[10]=0.0;
 ynueva[11]=0.0;

 Niteraciones =5000;
 out=fopen("molecula.dat","w");
 fprintf( out, "%f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\n",  x,y[4],y[5],y[0],y[1],y[6],y[7],y[2],y[3],y[10],y[11],y[8] ,y[9]);


 for (i=0; i<Niteraciones; i++)
{
 
 RK4(ynueva, y,x,h,nvar,molecula);
 x=x+h;
 y[0] = ynueva[0];
 y[1] = ynueva[1];
 y[2] = ynueva[2];
 y[3] = ynueva[3];
 y[4] = ynueva[4];
 y[5] = ynueva[5];
 y[6] = ynueva[6];
 y[7] = ynueva[7];
 y[8] = ynueva[8];
 y[9] = ynueva[9];
 y[10] = ynueva[10];
 y[11] = ynueva[11];

 if(i % out1 == 0)
 fprintf( out, "%f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\t%.16f\n",  x,y[4],y[5],y[0],y[1],y[6],y[7],y[2],y[3],y[10],y[11],y[8] ,y[9]);
}
 cout<<cos(thetabar)<<endl;
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

void molecula(double x, double *y, double *dxdt)
{
 double f21x;//potencial x armonico de oxigeno a hidrogeno 1
 double f21y;//potencial y armonico de oxigeno a hidrogeno 1
 double f31x;//potencial x armonico de oxigeno a hidrogeno 2
 double f31y;//potencial y armonico de oxigeno a hidrogeno 2
 double fa2x;//fuerza angular x hidrogeno 1 
 double fa2y;//fuerza angular y hidrogeno 1
 double fa3x;//fuerza angular x hidrogeno 2
 double fa3y;//fuerza angular y hidrogeno 2
 double R1;
 double R2;
 double R3;
 double r2;
 double r3;
 double r1;
 double r32;
 double T2;
 double T3;
 double theta;

 r32=sqrt((y[6]-y[4])*(y[6]-y[4])+(y[7]-y[5])*(y[7]-y[5]));
 //r3=sqrt(y[6]*y[6]+y[7]*y[7]);//posicion de hidrogeno 2
 //r2=sqrt(y[4]*y[4]+y[5]*y[5]); //posicion de hidrogeno 1
 //r1=sqrt(y[10]*y[10]+y[11]*y[11]);//posicion oxigeno
 
 R2=sqrt((y[4]-y[10])*(y[4]-y[10])+(y[5]-y[11])*(y[5]-y[11]));
 R3=sqrt((y[6]-y[10])*(y[6]-y[10])+(y[7]-y[11])*(y[7]-y[11]));

 T2=sqrt((y[11]-y[5])*(y[11]-y[5])+(y[4]-y[10])*(y[4]-y[10]));
 T3=sqrt((y[7]-y[11])*(y[7]-y[11])+(y[10]-y[6])*(y[10]-y[6]));

 theta=acos(((R2*R2)+(R3*R3)-(r32*r32))/(2*R2*R3));

 f21x=-4*S1*R2*(R2*R2-b*b)*(y[4]-y[10])/R2;//fuerza armonica en x hidrogeno 1
 f21y=-4*S1*R2*(R2*R2-b*b)*(y[5]-y[11])/R2;//fuerza armonica en y hidrogeno 1
 f31x=-4*S1*R3*(R3*R3-b*b)*(y[6]-y[10])/R3;//fuerza armonica en x hidrogeno 2
 f31y=-4*S1*R3*(R3*R3-b*b)*(y[7]-y[11])/R3;//fuerza armonica en y hidrogeno 2 
 

 fa2x=2*S2*sin(theta)*(cos(theta)-cos(thetabar))*(y[11]-y[5])/T2;//fuerza x angular hidrogeno 1
 fa2y=2*S2*sin(theta)*(cos(theta)-cos(thetabar))*(y[4]-y[10])/T2;//fuerza y angular hidrogeno 1
 
 fa3x=2*S2*sin(theta)*(cos(theta)-cos(thetabar))*(y[7]-y[11])/T3;//fuerza angular x hidrogeno 2
 fa3y=2*S2*sin(theta)*(cos(theta)-cos(thetabar))*(y[10]-y[6])/T3;//fuerza angular y hidrogeno 2



//y[0] velocidad de x hidrogeno 1
//y[1] velocidad de y hidrogeno 1
//y[2] velocidad de x hidrogeno 2
//y[3] velocidad de y hidrogeno 2
//y[4] posición en x hidrogeno 1
//y[5] posición en y hidrogeno 1
//y[6] posición en x hidrogeno 2
//y[7] posicion en y hidrogeno 2
//y[8] velocidad de x oxigeno 
//y[9] velocidad en y oxigeno
//y[10] posicion en x oxigeno
//y[11] posicion en y oxigeno

 dxdt[0]=(f21x+fa2x)/m2;//derivada de x' hidrogeno 1
 dxdt[1]=(f21y+fa2y)/m2;//derivada de y' hidrogeno 1
 dxdt[2]=(f31x+fa3x)/m3;//derivada de x' hidrogeno 2
 dxdt[3]=(f31y+fa3y)/m3;//derivada de y' hidrogeno 2
 dxdt[4]=y[0];//derivada de x hidrogeno 1
 dxdt[5]=y[1];//derivada de y hidrogeno 1 	
 dxdt[6]=y[2];//derivada de x hidrogeno 2
 dxdt[7]=y[3];//derivada de y hidrogeno 2
 dxdt[8]=(-f21x-f31x-fa2x-fa3x)/m1;//derivada x' oxigeno
 dxdt[9]=(-f21y-f31y-fa2y-fa3y)/m1;//derivada y' oxigeno
 dxdt[10]=y[8];//derivada de x oxigeno
 dxdt[11]=y[9];//derivada de y oxigeno
}
