#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define N (int)(20000)
#define D 0.1

double main(){
  srand48(1.0);
  double *datos;
  double *T;
  double *X;
  double *Y;
  double *Y1;
  double *betta;
  double *alpha;
  double *Y2;
  double *delta;
  double *gamma;
  datos=malloc(294*sizeof(double));
  T=malloc(94*sizeof(double));
  X=malloc(94*sizeof(double));
  Y=malloc(94*sizeof(double));
  Y1=malloc(93*sizeof(double));
  Y2=malloc(93*sizeof(double));  
   
  FILE *file;
	file = fopen("lotka_volterra_obs.dat", "r");
	if (file)
	{
		const size_t line_size = 100;
		char* line = malloc(line_size);
		int i=0;
		while (fgets(line, line_size, file) != NULL) 
		{
			char *token = strtok(line, " "); 

			while (token != NULL)
			{
				double temp = strtod(token, NULL); 
				datos[i]=temp;
				i=i+1;
				token = strtok(NULL, " ");
			}
		}
		free(line); 
		fclose(file);
	}
	int j=6;
	for(j==6;j<293;j=j+3){
	  T[j-6]=datos[j];
	  X[j-6]=datos[j+1];
	  Y[j-6]=datos[j+2];
	}
	
  betta=malloc(N*sizeof(double));
  betta[0]=drand48();
  alpha=malloc(N*sizeof(double));
  alpha[0]=drand48();
  delta=malloc(N*sizeof(double));
  delta[0]=drand48();
  gamma=malloc(N*sizeof(double));
  gamma[0]=drand48();
  printf("%f %f %f %f\n",betta[0],alpha[0],delta[0],gamma[0]);
  int k;
  for(k==0;k<94;k++){
    double dx=0.0;
    double dy=0.0;
    double dt=0.0;
    dx=X[k+1]-X[k];
    dy=Y[k+1]-Y[k];
    dt=T[k+1]-T[k];
    Y1[k]=dx/dt;
    Y2[k]=dy/dt;
  }
  int l=1;
  for(l==1;l<N-1;l++){
    double p1=0.0;
    double pa1=0.0;
    double p2=0.0;
    double pa2=0.0;
    double m1=0.0;
    double b1=0.0;
    double m2=0.0;
    double b2=0.0;
    
    m1=betta[l-1]+drand48()*2*D-D;
    b1=alpha[l-1]+drand48()*2*D-D;
    m2=delta[l-1]+drand48()*2*D-D;
    b2=gamma[l-1]+drand48()*2*D-D;
    
    int s;
    for(s==0;s<93;s++){
      p1=p1-(pow(Y1[s]+m1*Y[s]-b1,2))/2;
      pa1=pa1-(pow(Y1[s]-betta[l-1]*Y[s]-alpha[l-1],2))/2;
      p2=p2-(pow(Y2[s]+m2*Y[s]-b2,2))/2;
      pa2=pa2-(pow(Y2[s]-delta[l-1]*Y[s]+gamma[l-1],2))/2;
    }

    double a1=exp(p1-pa1);
    double alpha1=0.0;
    double a2=exp(p2-pa2);
    double alpha2=0.0;

    if(a1<1.0){
      alpha1=a1;
    }else{
      alpha1=1;
    }
    double r1=drand48();
    if(r1<alpha1){
      betta[l]=m1;
      alpha[l]=b1;
    }else{
      betta[l]=betta[l-1];
      alpha[l]=alpha[l-1];
    }

    if(a2<1.0){
      alpha2=a2;
    }else{
      alpha2=1;
    }
    double r2=drand48();
    if(r2<alpha2){
      delta[l]=m2;
      gamma[l]=b2;
    }else{
      betta[l]=betta[l-1];
      alpha[l]=alpha[l-1];
    }
    
    printf("%f %f %f %f\n",betta[l],alpha[l],delta[l],gamma[l]);
  }
  return 0;
}
