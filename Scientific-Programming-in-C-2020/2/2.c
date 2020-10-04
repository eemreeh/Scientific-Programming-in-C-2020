#include <stdio.h>
#include <stdlib.h>


#define m1(i,j) (*(m1 + c1*i + j)) 

void show_matrix(double *matrix,int row, int column );

double m_det(int row, int column, double *matrix );

void m_minor(int q, double *matrix, double *output);

void m_cofactor(int q, double *matrix, double *output);

void m_trans(int row, int column, double *matrix, double *output);

double m_det4(double *matrix);

void m_adjoint(double *cofacmatrix, double *output, double det);

void m_mult(double *matrix, double *vector, double *result);


int main(){

	double *m1, *out, *res, *xres;
	int r1, c1;
	int i, j;
	double det;
	
	
	
	/*
	printf("Enter the row number:  ");
	scanf("%d",&r1);
	printf("\nEnter the column number:  ");
	scanf("%d",&c1);
	
	
	*/
	r1 = 4;
	c1 = 4;
	
	
	
	m1 = (double *)malloc(r1*c1*sizeof(double));
	out = (double *)malloc(r1*c1*sizeof(double));
	res = (double *)malloc(r1*sizeof(double));
	xres = (double *)malloc(r1*sizeof(double));
	
	printf("Enter the 4x4 matrix numbers:\n");
	
	for (i = 0 ; i<r1 ; i++){
		for (j = 0 ; j<c1 ; j++){
			scanf("%lf",&m1(i,j));
		}
	}
	
	
	
	printf("Enter the result vector numbers:\n");
	
	for (j = 0 ; j<c1 ; j++){
			scanf("%lf",(res + j));
	}
	
	show_matrix(m1 , r1, c1 );
	
	puts("");
	
	for (j = 0 ; j<c1 ; j++){
		printf("%.3lf   ",*(res + j));
	}
	
	det = m_det4(m1);
	
	printf("\nDeterminant of the matrix is %lf\n",det);
	
	if(det == 0){
		printf("\n ERROR Determinant must not be ZERO");
		return 1;
	}
	
	
	m_minor(r1 , m1, out);
	puts("\nMinor matrix\n");
	show_matrix(out , r1, c1 );
	
	
	puts("\nCofactor matrix\n");
	m_cofactor(r1, out, m1);
	show_matrix(m1 , r1, c1 );
	
	
	puts("\nInverse matrix\n");
	m_adjoint(m1,out,det);
	show_matrix(out , r1, c1 );
	
	
	m_mult( out, res, xres);
	
	for(i=0;i<r1;i++){
		printf("\n[X] vector is %lf",*(xres+i));
	}
	
	
	#undef m1
	free(m1);
	free(res);
	free(xres);
	free(out);
	return 1;
}

void show_matrix(double *matrix,int row, int column ){
	int i, j;
	for (i=0;i<row;i++){
		for (j = 0;j<column;j++){
			printf("%-+10.3lf",*(matrix + i*column + j));
		}
		puts("");
	}
}



double m_det(int row, int column, double *matrix ){
	//*(matrix + i*column + j)
	
	double result;
	
	
	result = 0;

	if(row == 2 && column == 2){
		result = *(matrix + 0*column + 0)**(matrix + 1*column + 1) - *(matrix + 0*column + 1)**(matrix + 1*column + 0);
		
	}
	else if(row == 3 && column == 3){
		result = *(matrix + 0*column + 0) * (*(matrix + 1*column + 1)**(matrix + 2*column + 2) - *(matrix + 2*column + 1)**(matrix + 1*column + 2)) 
		- *(matrix + 0*column + 1)*(*(matrix + 1*column + 0)**(matrix + 2*column + 2) - *(matrix + 2*column + 0)**(matrix + 1*column + 2)) 
		+ *(matrix + 0*column + 2)*(*(matrix + 1*column + 0)**(matrix + 2*column + 1) - *(matrix + 2*column + 0)**(matrix + 1*column + 1));
	}
	
	return result;
}



void m_minor(int q, double *matrix, double *output){
	int i, j, k, l;
	int k2, l2;
	
	double *temp = (double *)malloc((q-1)*(q-1)*sizeof(double));
	
	for(i = 0;i<q ;i++){
		for(j = 0;j<q ;j++){
			
			for(k = 0;k<q - 1;k++){
				k2 = 0;
				l2 = 0;
				for(l = 0;l<q-1;l++){
					if(k >= i)
						k2 = 1;
					if(l >= j)
						l2 = 1;
					*(temp + k*(q-1) + l) = *(matrix + (k+k2)*q + l + l2);
				}
				
			}
			//show_matrix(temp , q-1, q-1 );
		//	printf("%lf\n",m_det((q-1),(q-1),temp));
			*(output + i*q + j) = m_det(q-1,q-1,temp);
			
		}
	}
	
	
}



void m_cofactor(int q, double *matrix, double *output){
	//input matrix is minor matrix
	int i, j, k;
	
	for (i = 0 ; i<q ; i++){
		for (j = 0 ; j<q ; j++){
			k = ((i+j)%2 == 0)? 1 : -1;   
			*(output + i*q + j) = *(matrix + i*q + j) * k;
		}
	}
}



void m_trans(int row, int column, double *matrix, double *output){
	//hata mesajý ekle
	int i, j;
	for (i=0;i<row;i++){
		for (j = 0;j<column;j++){
			*(output + j*row + i) = *(matrix + i*column + j);
		}
	}

	
}



double m_det4(double *matrix){
	int i, j, k;
	int m, n;
	double result = 0;
	double *m2 = (double*)malloc(4*4*sizeof(double));
	
	
	
	for(k = 0; k<4 ;k++){
		for(i = 0;i<3;i++){
			for(j = 0;j<3;j++){

				m = i +1;
				
				if (j >= k)
					n = j +1;
				else 
					n = j;	
				
				*(m2 + 3*i + j) = *(matrix + 4*m + n);
				
			}
		}
		
		if (k%2 == 0)
			result += *(matrix + k)*m_det(3,3,m2);
		else
			result -= *(matrix + k)*m_det(3,3,m2);
	}
	
	
	return result;
	
}



void m_adjoint(double *cofacmatrix, double *output, double det){
	int i, j, k;
	
	double *temp = (double *)malloc(4*4*sizeof(double));
	
	m_trans(4,4,cofacmatrix, temp);
	
	for(i = 0;i<4;i++){
		for(j = 0;j<4;j++){
			*(output + 4*i + j) = *(temp + 4*i + j)/det;
			
		}
	}
	
	
}


void m_mult(double *matrix, double *vector, double *result){
	int i, j, k;
	
	
	for(i=0;i<4;i++){
			*(result + i) = 0; 
	}
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			*(result + i) += *(matrix + 4*i + j) *  *(vector + j);  
		}
	}
	
	
	
}


/* 
* EXTRA FUNCTION WHICH IS CRAMER FUNCTION. THIS FUNCTION IS NOT USED IN THIS PROGRAM                

void m_cramer(int row, int column, double *matrix, double *vector){
	
	int i, j, k;
	double Det;
	
	double *m1 = (double *)malloc(column*row*sizeof(double));
	double *res = (double *)malloc(column*sizeof(double));
	
	Det = m_det(row, column , matrix);
	
	for(k=0;k<column;k++){
		
		for(i = 0; i<row ; i++){
			for(j = 0; j<column ; j++){
				*(m1 + i*column + j) = *(matrix + i*column + j);
			}
		}
		
		for(i = 0; i<row ; i++){
			*(m1 + i*column + k) = *(vector + i);
		}
		
		
		*(res + k) = m_det(row, column , m1) / Det;
	}
	
	for(k=0;k<column;k++){
		
		printf("\nX%d is : %.3lf",k,*(res + k));
		
	}
	
	
}


*/

