#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x,double sigma);

double Trapezoid(double start, double end,double sigma, int num);

double funcp(double sigma);

double error(double start, double end, double num,double sigma);

double adapt(double start,double end,double tolerance, double sigma,int *panel);


int main(){
	double x, sigma,tolerance;
	int panel;
	printf("Sigma test%lf\n",func(0,4));
	printf("Trapezoidal test %lf\n",Trapezoid(0,20,4,10));	
//	printf("error test%lf\n",error(0,30,1,1));
	
	
	
	while(1){
		printf("\nPlease enter sigma and tolerance\n");
    	scanf("%lf",&sigma);
				
		if(sigma == 0)
			break;
	  	
	  	scanf("%lf",&tolerance);
		printf("\nFor sigma value %lf, integral result is %lf",sigma,adapt(0,30,tolerance,sigma,&panel));
		printf("and number of panel is %d\n",panel);
		
		
	}
	

	
	
	
	return 1;
}

double func(double x,double sigma){
	return (exp((-x*x)/(sigma*sigma))/sigma);
}


double funcp(double sigma){
	return (-2/pow(sigma,3));
}

double Trapezoid(double start, double end,double sigma, int num){
	double i = 0,a;
	double area = 0;
	double deltax = (end - start)/num;
	
	while(i < num){
		a = start+i*deltax;
    	area += ((func(a,sigma) + func(a+deltax,sigma))/2.0);
    	i++;
		}
	
	area *= deltax;
	return area;
}


double error(double start, double end, double num,double sigma){
	return (-pow((end - start),3)*funcp(sigma)/(12*num*num));
}


double adapt(double start,double end,double tolerance, double sigma,int *panel){
	int num = 1;
	
	while(error(start,end,num,sigma) > tolerance){
		num *= 2;	
		//return adapt(start,(start+end)/2,tolerance,sigma,panel) + adapt((start+end)/2,end,tolerance,sigma,panel);
	}
		
	
	*panel = num;
	return Trapezoid(start,end,sigma,num);
}


/*
IN THIS PROGRAM THESE FUNCTIONS ARE NOT USED. HOWEVER THESE METHODS ARE ALSO USABLE.

double LRectangle(double start, double end, int num){
	double i = 0;
	double area = 0;
	double deltax = (end - start)/num;
	
	while(i < num){
    			area += func(start + i*deltax);
    			i++;
			}
	
	area *= deltax;
	return area;
}

double RRectangle(double start, double end, int num){
	double i = 1;
	double area = 0;
	double deltax = (end - start)/num;
	
	while(i <= num){
    			area += func(start + i*deltax);
    			i++;
		}
	
	area *= deltax;
	return area;
}



double Simpson(double start, double end, int num){
	double i,x;
	double area = 0;
	double deltax = (end - start)/num;
	
	i = 0;
	while(i<num){
		x = start + i*deltax;
		area += func(x) + 4*func(x + deltax/2.0) + func(x + deltax);
		i++;
	} 
	return (deltax*area/6);
}



double SemiAdaptiveSimpson(double start, double end, int num, double tolerance){
	double check = tolerance + 1.0;
	double lowval, val;
	
	lowval = Simpson(start,end,num);
	while(check > tolerance){
		num *= 2;
		val = Simpson(start,end,num);
		check = fabs((val-lowval)/val);
		lowval = val;
	}
	
	return val;
}

double AdaptiveSimpson(double start, double end, int num, double tolerance){
	double check, val;
	val = Simpson(start,end,2*num);
	
	check = fabs((Simpson(start,end,num)-val)/val);
	
	if(check > tolerance){
		val = AdaptiveSimpson(start,(start + end)/2.0,num,tolerance) + AdaptiveSimpson((start + end)/2.0,end,num,tolerance);
	}
	
	return val;
}


*/



















