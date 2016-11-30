#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define s 0.1
#define v 5
#define N (int)(25000)
#define delta 0.1

double main(){
  double *Xe;
  double *Ye;
  double *Ti;
  double *Tc;
  double *Ta;
  double *X;
  double *Y;
  double *T;
  srand48(1.0);
  Xe=malloc(6*sizeof(double));
  Ye=malloc(6*sizeof(double));
  Ti=malloc(6*sizeof(double));
  Tc=malloc(6*sizeof(double));
  Ta=malloc(6*sizeof(double));
  X=malloc(N*sizeof(double));
  X[0]=7.0;
  Y=malloc(N*sizeof(double));
  Y[0]=-1.0;

  Xe[0]=3.0;
  Xe[1]=4.0;
  Xe[2]=5.0;
  Xe[3]=3.0;
  Xe[4]=4.0;
  Xe[5]=5.0;
  
  Ye[0]=15.0;
  Ye[1]=15.0;
  Ye[2]=15.0;
  Ye[3]=16.0;
  Ye[4]=16.0;
  Ye[5]=16.0;

  Ti[0]=3.12;
  Ti[1]=3.26;
  Ti[2]=2.98;
  Ti[3]=3.12;
  Ti[4]=2.84;
  Ti[5]=2.98;
  printf("%f %f\n",X[0],Y[0]);
  int j=1;
  for(j==1;j<N-1;j++){
    float x=0.0;
    float y=0.0;
    x=X[j-1] + drand48()*2*delta - delta;
    y=Y[j-1] + drand48()*2*delta - delta;
    int i;
    double p=0.0;
    double pa=0.0;
    for(i==0;i<6;i++){
      double Xc=0.0;
      double Yc=0.0;
      double Xa=0.0;
      double Ya=0.0;
      Xc=pow((Xe[i]-x),2);
      Yc=pow((Ye[i]-y),2);
      Xa=pow((Xe[i]-X[j-1]),2);
      Ya=pow((Ye[i]-Y[j-1]),2);
      Tc[i]=pow(Xc+Yc,0.5)/v;
      Ta[i]=pow(Xa+Ya,0.5)/v;	
      p+=-pow((Ti[i]-Tc[i]),2)/(2*pow(s,2));
      pa+=-pow((Ti[i]-Ta[i]),2)/(2*pow(s,2));
    }
    double a=exp(p-pa);
    double alpha=0.0;
    if(a<1.0){
      alpha=a;
    }else{
      alpha=1;
    }
    double r=drand48();
    if(r<alpha){
      X[j]=x;
      Y[j]=y;
    }else{
      X[j]=X[j-1];
      Y[j]=Y[j-1];
    }
    printf("%f %f\n",X[j],Y[j]);
  }
  return 0;
}


