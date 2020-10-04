#include <stdio.h>
#include <stdlib.h>

void show_matrix(double *matrix,int row, int column );

void m_add(int , int , double* , double* , double* );
void m_mult(int , int , int , double* , double* , double*);
void m_trans(int , int , double* , double* );
	
#define m1(i,j) (*(m1 + i*c1 + j))
#define m2(i,j) (*(m2 + i*c2 + j))


int main(){
	
	double *m1, *m2, *out;
	int r1 ,c1 ,r2 ,c2 ;
	int i,j;
	
	int choice;
	
	while(1){
		printf("Which operation do you want?\n1::Addition\n2::Muliplication\n3::Transpoze\n");
		scanf("%d",&choice);
		if (choice != 1 && choice != 2 &&
		 choice != 3){
			printf("There is no operation on %d. Please enter a valid number.\n",choice);
		}else {
			break;
		}
	}
	
	
	switch(choice){
		case 1:
			printf("How many rows for matrix 1\n");
			scanf("%d",&r1);
			printf("How many colums for matrix 1\n");
			scanf("%d",&c1);
			
			printf("How many rows for matrix 2\n");
			scanf("%d",&r2);
			printf("How many colums for matrix 2\n");
			scanf("%d",&c2);
			
			if (r1 != r2 || c1 != c2){
				printf("Your matrix values are invalid!\n\n");
			}else{
				
				m1 = (double *)malloc(r1*c1*sizeof(double));
	
				printf("Enter the matrix 1 numbers:\n");
				for (i = 0 ; i<r1 ; i++){
					for (j = 0 ; j<c1 ; j++){
						scanf("%lf",&m1(i,j));
					}
				}
				
				show_matrix(&m1[0] ,r1 ,c1 );	
				
				m2 = (double *)malloc(r2*c2*sizeof(double));
				
				printf("Enter the matrix 2 numbers:\n");
	
				for (i = 0 ; i<r2 ; i++){
					for (j = 0 ; j<c2 ; j++){
						scanf("%lf",&m2(i,j));
					}
				}
				
				show_matrix(&m2[0] ,r2 ,c2 );	
				
				printf("\n\n\n");
				
				out = (double*)malloc(r1*c1*sizeof(double));
				m_add(r1,c1,m1,m2,out);
				show_matrix(out ,r1 ,c1 );
				
				
				free(m1);
				free(m2);
				free(out);
			}
			
			
			break;
		case 2:
			
			printf("How many rows for matrix 1\n");
			scanf("%d",&r1);
			printf("How many colums for matrix 1\n");
			scanf("%d",&c1);
			
			printf("How many rows for matrix 2\n");
			scanf("%d",&r2);
			printf("How many colums for matrix 2\n");
			scanf("%d",&c2);
			
			
			if(c1 != r2){
				printf("Your matrix values are invalid!\n\n");
				
			}else{
				
				m1 = (double *)malloc(r1*c1*sizeof(double));
	
				printf("Enter the matrix 1 numbers:\n");
				for (i = 0 ; i<r1 ; i++){
					for (j = 0 ; j<c1 ; j++){
						scanf("%lf",&m1(i,j));
					}
				}
				
				show_matrix(&m1[0] ,r1 ,c1 );	
				
				m2 = (double *)malloc(r2*c2*sizeof(double));
				
				printf("Enter the matrix 2 numbers:\n");
	
				for (i = 0 ; i<r2 ; i++){
					for (j = 0 ; j<c2 ; j++){
						scanf("%lf",&m2(i,j));
					}
				}
				
				show_matrix(&m2[0] ,r2 ,c2 );
				
				printf("\n\n\n");
				
				out = (double*)malloc(r1*c2*sizeof(double));
				m_mult(r1, c1, c2, m1, m2, out);
				show_matrix(out ,r1 ,c2 );
				
				
				free(m1);
				free(m2);
				free(out);
			}
			
			
			
			
			break;
		case 3:
			
			printf("How many rows for matrix \n");
			scanf("%d",&r1);
			printf("How many colums for matrix \n");
			scanf("%d",&c1);
			
			m1 = (double *)malloc(r1*c1*sizeof(double));
	
			printf("Enter the matrix numbers:\n");
			for (i = 0 ; i<r1 ; i++){
				for (j = 0 ; j<c1 ; j++){
					scanf("%lf",&m1(i,j));
				}
			}
				
			show_matrix(&m1[0] ,r1 ,c1 );	
			
			printf("\n\n\n");
			
			out = (double*)malloc(c1*r1*sizeof(double));
			m_trans(r1, c1, m1, out);
			show_matrix(out ,c1 ,r1 );

			free(m1);
			free(out);

			break;
		default :
			
			break;
	
	}
	
	
	#undef m1
	#undef m2
	system("pause");
	return 1;
}

void show_matrix(double *matrix,int row, int column ){
	int i, j;
	for (i=0;i<row;i++){
		for (j = 0;j<column;j++){
			printf("%-+10.2lf",*(matrix + i*column + j));
		}
		puts("");
	}
}


void m_add(int row, int column, double *m1, double *m2, double *output){
	int i, j;
	for (i=0;i<row;i++){
		for (j = 0;j<column;j++){
			*(output + i*column + j) = *(m1 + i*column + j) + *(m2 + i*column + j);
		}
	}
	
}

void m_mult(int row1, int column1, int column2, double *m1, double *m2, double *output){
	int i, j, k;
	for (i=0;i<row1;i++){
		for (j = 0;j<column2;j++){
			for (k = 0;k < column1;k++){
				*(output + i*column2 + j) += *(m1 + i*column1 + k) * *(m2 + k*column2 + j);
			}
		}
	}
	
}


void m_trans(int row, int column, double *matrix, double *output){
	int i, j;
	for (i=0;i<row;i++){
		for (j = 0;j<column;j++){
			*(output + j*row + i) = *(matrix + i*column + j);
		}
	}

	
}
