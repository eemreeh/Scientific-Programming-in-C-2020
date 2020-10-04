#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x);

void printArray(double a[50]);

int isRootPresent(double lpoint);

void findLBounds(double array[50],double low, double up);

double trisection(double start, double end,double tolerance);

double bisection(double start, double end, double tolerance );

void findRoots(double LBounds[50],double roots[50],double epsilon);

double LRectangle(double start, double end, double step);

void saveIntegrals(double roots[50],double integrals[50],double start,double end, double step );

double maxintegral(double start,double  end,double integrals[50],double roots[50],double *a,double *b);

int main(){
	double bounds[50] = {0};
	double roots[50] = {0};
	double integrals[50] = {0};
	double a,b;
	printf("f(0.00) = %lf\n",func(0.00));
	printf("f(2.20) = %lf\n",func(2.20));
	printf("isRootPresent(1.95,2.00) = %d\n",isRootPresent(1.95));
	printf("isRootPresent(2.05,2.10) = %d\n",isRootPresent(2.05));
	printf("isRootPresent(3.75,3.80) = %d\n",isRootPresent(3.75));
	
	findLBounds(bounds,0.00,2.20);
	printf("For (a,b)=(0.00,2.20) lower boundries are:\n");
	printArray(bounds);
	
	findLBounds(bounds,2.00,3.60);
	printf("For (a,b)=(2.00,3.60) lower boundries are:\n");
	printArray(bounds);

	printf("trisection(2.45,2.5,0.00001) = %lf\n",trisection(2.45,2.5,0.00001));
	printf("bisection(2.45,2.5,0.00001) = %lf\n",bisection(2.45,2.5,0.00001));
	
	printf("trisection(1.95,2.0,0.00001) = %lf\n",trisection(1.95,2.0,0.00001));
	printf("bisection(1.95,2.0,0.00001) = %lf\n",bisection(1.95,2.0,0.00001));
	
	findLBounds(bounds,0.00,2.20);
	findRoots(bounds,roots,0.00001);
	printf("For (a,b)=(0.00,2.20), roots are:\n");
	printArray(roots);
	
	findLBounds(bounds,2.00,3.60);
	findRoots(bounds,roots,0.00001);
	printf("For (a,b)=(2.00,3.60), roots are:\n");
	printArray(roots);
	
	printf("LeftRectangle(1.4588,1.9677,0.0001) = %lf\n",LRectangle(1.4588,1.9677,0.00001));
	printf("LeftRectangle(2.8056,3.1824,0.0001) = %lf\n",LRectangle(2.8056,3.1824,0.00001));

	findLBounds(bounds,0.00,2.20);
	findRoots(bounds,roots,0.00001);
	saveIntegrals(roots,integrals,0.00,2.20,0.00001);
	printf("For (a,b) = (0.00,0.20) integral of the regions are:\n");
	printArray(integrals);

	findLBounds(bounds,2.00,3.60);
	findRoots(bounds,roots,0.00001);
	saveIntegrals(roots,integrals,2.00,3.60,0.00001);
	printf("For (a,b) = (2.00,3.60) integral of te regions are:\n");
	printArray(integrals);
	
	findLBounds(bounds,0.00,2.20);
	findRoots(bounds,roots,0.00001);
	saveIntegrals(roots,integrals,0.00,2.20,0.00001);
	printf("Total integral over (a,b) = (0.00,2.20) is : %lf\n",maxintegral(0.00,2.20,integrals,roots,&a,&b));
	printf("Maximum integral region inside (a,b) = (0.00,2.20) is : (%lf,%lf)\n",a,b);
	
	findLBounds(bounds,0,1);
	findRoots(bounds,roots,0.00001);
	saveIntegrals(roots,integrals,0,1,0.00001);
	printf("Total integral over (a,b) = (0.00,2.20) is : %lf\n",maxintegral(0,1,integrals,roots,&a,&b));
	printf("Maximum integral region inside (a,b) = (0.00,2.20) is : (%lf,%lf)\n",a,b);
	
	
	return 1;
}


double func(double x){
	return (sin((M_PI/2)*x*x) + 0.2);
}



void printArray(double a[50]){
	int i;
	for(i = 0;a[i]!=0;i++){
		printf("%lf\n",a[i]);
	}
}



int isRootPresent(double lpoint){
	if(func(lpoint)*func(lpoint+0.05) < 0)
		return 1;
	else
		return 0;
}


void findLBounds(double array[50],double low, double up){
	int i;
	for(i=0;i<50;i++){
		array[i] = 0;
	}
	
	i = 0;
	
	for(;low<up;low+=0.05){
		if(isRootPresent(low)){
			array[i++] = low;
//			printf("%lf\n",low);
		}
	}
}


double trisection(double start, double end,double tolerance){
	double mid;
	double step;
	while((end-start)>tolerance){
		step = (end-start)/3;
		mid = start + step;
		if(func(start)*func(start+step) <= 0){
			end = start + step;
		}else if(func(mid)*func(mid+step) <= 0){
			start = mid;
			end = mid + step;
		}else if(func(end - step)*func(end) <= 0){
			start = end - step;
		}
	}
	return ((start + end)/2);
}

double bisection(double start, double end, double tolerance ){
	
	double mid;
	for(mid = (start + end)/2;(end-start)/2>tolerance;){
		mid = (start+end)/2.0;
		
		if(func(start)*func(mid)<= 0 ){
			end = mid;
		}else{
			start = mid;
		}
		
	}
	return mid;
}

void findRoots(double LBounds[50],double roots[50],double epsilon){
	int i;
	for(i=0;i<50;i++){
		roots[i] = 0;
	}
	
	for(i = 0;LBounds[i] != 0;i++){
		roots[i] = trisection(LBounds[i],LBounds[i]+0.05,epsilon);
	}
}


double LRectangle(double start, double end, double step){
	int i = 0;
	double area = 0;
	int num = (end-start)/step;
	
	
	for(i = 0;i<num;i++){
		area += step*func(start + i*step );
		//printf("%lf",area);
	}
	
	return area;
}


void saveIntegrals(double roots[50],double integrals[50],double start,double end, double step ){
	int i;
	for(i=0;i<50;i++){
		integrals[i] = 0;
	}
	
	integrals[0] = LRectangle(start,roots[0],step);
	
	for(i = 1;roots[i] != 0; i++){
		integrals[i] = LRectangle(roots[i-1],roots[i],step);
	}
	integrals[i] = LRectangle(roots[i-1],end,step);
}


double maxintegral(double start,double  end,double integrals[50],double roots[50],double *a,double *b){
	double temp = integrals[0];
	int i;
	for(i = 1;integrals[i]!=0;i++){
		if(integrals[i]>temp)
			temp = integrals[i];
	}
	
	for(i = 0;integrals[i] != temp;i++);
	
	if(i == 0){
		*a = start;
		*b = roots[0]; 
	}else{
		*a = roots[i];
		if(roots[i+1] == 0)
			*b= end;
		else{
			*b = roots[i+1];
		}
	}
	
	
	return LRectangle(start,end,0.00001);
}

