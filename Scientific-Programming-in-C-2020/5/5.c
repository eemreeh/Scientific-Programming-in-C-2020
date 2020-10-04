#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x);

double funcd(double x, double y);

void Euler(double *res, double initx, double inity, double step, double end);

void RungeKutta2(double *res, double initx, double inity, double step, double end);

void RungeKutta4(double *res, double initx, double inity, double step, double end);


int main(){
	
	double initx,inity,step,end;
	double *res1,*res2,*res3;
	int i;
	
	printf("y(0.2) = %lf    and g(0.2, 0.8) = %lf\n",func(0.2),funcd(0.2,0.8));
	printf("Please Enter initial x0, initial y0, end point and step size point\n");
	scanf("%lf%lf%lf%lf",&initx,&inity,&end,&step);
	
	printf("x0 = %lf\ny0 = %lf\nEnd point = %lf\nStep size = %lf\n",initx,inity,end,step);
	
	res1 = (double *)malloc(((end-initx)/step + 1)*sizeof(double));
	res2 = (double *)malloc(((end-initx)/step + 1)*sizeof(double));
	res3 = (double *)malloc(((end-initx)/step + 1)*sizeof(double));

	Euler(res1,initx,inity,step,end);
	RungeKutta2(res2,initx,inity,step,end);
	RungeKutta4(res3,initx,inity,step,end);
	
	printf("\t\t\tEuler       MidPoint\tRunge4     Exact\n");
	for(i = 0;i<=((end-initx)/step);i++){
		printf("Step %2d  y(%lf)  %10lf  %10lf  %10lf %10lf\n",i,initx + i*step,*(res1 + i),*(res2 + i),*(res3 + i),func(initx + i*step));
	}
	
	
	free(res1);
	free(res2);
	free(res3);
	
	return 1;
}


double funcd(double x, double y){
	return (y*pow(x,3) - 0.1*y); 
}


double func(double x){
	return (exp(pow(x,4)/4 - 0.1*x));
}



void Euler(double *res, double initx, double inity, double step, double end){
	double x,y;
	
	y = inity;
	*res++ = y;
	x = initx-step;
	
	while((x += step) <= end){
		
		y += step*funcd(x ,y );
		*res++ = y;
	}
	
}


void RungeKutta2(double *res, double initx, double inity, double step, double end){
	double mid;
	double x,y;
	
	y = inity;
    *res++ = y;
    x = initx - step;
    
	while((x += step) <= end){

		mid = step*funcd(x,y);
		y += step*funcd(x + step/2.0,y + mid/2);
		*res++ = y;
	}
	
}



void RungeKutta4(double *res, double initx, double inity, double step, double end){
	double a,b,c,d;
	double x,y;
	
	y = inity;
	*res++ = y;
	x = initx - step;
	while((x += step) <= end){

		a = step*funcd(x,y);
		b = step*funcd(x + step/2.0,y + a/2.0);
		c = step*funcd(x + step/2.0,y + b/2.0);
		d = step*funcd(x + step,y + c);
		
		y += a/6.0 + b/3.0 + c/3.0 + d/6.0;
		*res++ = y;
	}
	
}













