#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N (int)(2000)
#define delta 0.1
#define PI 3.14159265359
#define PI2 pow(PI,2)
#define G1 4*PI2

double main(){
  srand48(1.0);
  double G=log10(G1);
  double *R;
  double *V;
  double *M;
  double *B;

  M=malloc(N*sizeof(double));
  M[0]=0;
  B=malloc(N*sizeof(double));
  B[0]=3;
  
  double Rx[8] = {0.324190175,-0.701534590,-0.982564148,1.104185888,3.266443877,-9.218802228,19.930781147,24.323085642};
  double Ry[8] = {0.090955208,-0.168809218,-0.191145980,-0.826097003,-3.888055863,1.788299816,-2.555241579,-17.606227355};
  double Rz[8] = {-0.022920510,0.037947785,-0.000014724,-0.044595990,-0.057015321,0.335737817,-0.267710968,-0.197974999};
  double Vx[8] = {-4.627851589,1.725066954,1.126784520,3.260215854,2.076140727,-0.496457364,0.172224285,0.664855006};
  double Vy[8] = {10.390063716,-7.205747212,-6.187988860,4.524583075,1.904040630,-2.005021061,1.357933443,0.935497207};
  double Vz[8] = {1.273504997,-0.198268558,0.000330572,0.014760239,-0.054374153,0.054667082,0.002836325,-0.034716967};

  R=malloc(8*sizeof(double));
  V=malloc(8*sizeof(double));

  int i;
  for(i==0;i<9;i++){
    double r=0;
    double v=0;
    r=pow(pow(Rx[i],2)+pow(Ry[i],2)+pow(Rz[i],2),1/2);
    v=pow(pow(Vx[i],2)+pow(Vy[i],2)+pow(Vz[i],2),1/2);
    R[i]=log10(r);
    V[i]=log10(v);
  }
  int j=1;
  for(j==1;j<N-1;j++){
    double p=0.0;
    double pa=0.0;
    double m=0.0;
    double b=0.0;
    m=M[j-1]+drand48()*2*delta-delta;
    b=B[j-1]+drand48()*2*delta-delta;
    
    int k;
    for(k==0;k<9;k++){
      p+=-(pow(V[k]-m*R[k]-b,2))/2;
      pa+=-(pow(V[k]-M[i-1]*R[k]-B[i-1],2))/2;
    }

    double a=exp(p-pa);
    double alpha=0.0;
    if(a<1.0){
      alpha=a;
    }else{
      alpha=1.0;
    }
    double r=drand48();
    if(r<alpha){
      M[j]=m;
      B[j]=b;
    }else{
      M[j]=M[j-1];
      B[j]=B[j-1];
    }
    printf("%f %f\n",-2*M[j]+1,2*B[j]-G);
  }
  return 0;
}
