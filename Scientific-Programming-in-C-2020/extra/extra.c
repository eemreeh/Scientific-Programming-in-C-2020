#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int x,y;
	int a,b;
	
	a = 15;
	b = 30;
	
	for(y=-30;y<30;y++){
		for(x=-30;x<30;x++){
			if(a>sqrt(x*x+y*y)){
				printf("* ");
			}else if(1>=(pow(x,2)/(b*b) + pow(y,2)/(a*a))){
				printf(", ");
			}else{
				printf("/ ");
			}
		}
		printf("\n");
	}	
	
	return 1;
}















