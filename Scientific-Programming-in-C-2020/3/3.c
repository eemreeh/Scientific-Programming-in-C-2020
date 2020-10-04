#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double R);

double func2(double T, double R);

double bisection(double T, double start, double end, double tolerance ,int* itr);


#define K(t) (t + 273.15)
#define C(t) (t - 273.15)

int main(){
	double T1,T2,T3,T4;
	double start, end, tolerance;
	int itr;
	
	printf("\nEnter the T1 value");
	scanf("%lf",&T1);
	
	printf("\nEnter the T2 value");
	scanf("%lf",&T2);
	
	printf("\nEnter the T3 value");
	scanf("%lf",&T3);
	
	printf("\nEnter the T4 value");
	scanf("%lf",&T4);


	
	printf("\nTemperature of R Test 1 :: %lf  C",C(func1(5000)));
	printf("\nTemperature of R Test 2 :: %lf  C",C(func1(25000)));


	printf("\nStart :: ");
	scanf("%lf",&start);
	
	printf("\nEnd :: ");
	scanf("%lf",&end);
	
	printf("\nTolerance :: ");
	scanf("%lf",&tolerance);

	
	printf("\nFor temperature %lf  Root is  %lf ",T1,bisection( T1,  start,  end,  tolerance ,&itr));
	printf("itreation %d",itr);
	printf("\nFor temperature %lf  Root is  %lf ",T2,bisection( T2,  start,  end,  tolerance  ,&itr));
	printf("itreation %d",itr);
	printf("\nFor temperature %lf  Root is  %lf ",T3,bisection( T3,  start,  end,  tolerance  ,&itr));
	printf("itreation %d",itr);
	printf("\nFor temperature %lf  Root is  %lf ",T4,bisection( T4,  start,  end,  tolerance  ,&itr));
	printf("itreation %d",itr);
	
	
	
	
	
	
	return 1;
}



double func1(double R){
	double T;
	
	T =  0.0011292 + 0.00023410*log(R)/log(M_E) + (8.7754/100000000)*pow(log(R)/log(M_E),3);

	return 1/T;
}

double func2(double T, double R){
	double res;
	
	res = -1/K(T) + 0.0011292 + 0.00023410*log(R)/log(M_E) + (8.7754/100000000)*pow(log(R)/log(M_E),3);

	return res;
}

double bisection(double T, double start, double end, double tolerance ,int* itr){
	
	double mid;
	int say = 0;
	for(mid = (start + end)/2;(end-start)/2>tolerance;){
		say++;
		mid = (start+end)/2.0;
		
		if(func2(T,start)*func2(T,mid)<= 0 ){
			end = mid;
		}else{
			start = mid;
		}
	
		
	}
	*itr = say;
	//printf("\n%d",say);

	return mid;
}












