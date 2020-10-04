#include <stdio.h>
#include <stdlib.h> 

#define MAX 100

struct Stack{
	char entry[50];
	int count;
};

void init(struct Stack *s);

void push(struct Stack *s,char c);

char pop(struct Stack *s);

int isPol(char *str);

int countPol(char *str,int *num);

void uptolow(char *str);




int main(){
	
	char word[20],str[MAX];
	scanf("%[^\n]",word);
	int polnum, num[20] = {0};
	int i;
	getchar();
	if(isPol(word)){
		printf("\nYes, it is a Ploiindrome.\n");
	}else
		printf("\nNo,it is not a Polindrome.\n");

	scanf("%[^\n]",str);
	uptolow(str);
	polnum = countPol(str,num);
	printf("Number of polindrome %d\n",polnum);	
	
	
	
	for(i = 0;num[i] != 0;i++){
		printf("Word %d is a polindrome\n",num[i]);
	}
	
	
	
	
	
	
	
	
	return 1;
}


void init(struct Stack *s){
	s->count = 0;
}

void push(struct Stack *s,char c){
	if (s->count > MAX){
		exit(0);
	}else{
		s->entry[s->count++] = c;
	}
}

char pop(struct Stack *s){
	if(s->count > 0){
		return(s->entry[--s->count]);
	}else
		exit(0);
	
}

int isPol(char *str){
	char flag = 1,*tem = str;
	struct Stack s;
	init(&s);
	
	for(;*tem != '\0';tem++)
		push(&s,*tem);
	
	
	for(tem = str;*tem != '\0';tem++)
		if(*tem != pop(&s))	flag = 0;
	
	return flag;
}

int countPol(char *str,int *num){
	int i,j = 0,count = 0,k = 0;
	char word[20];
	
	
	for(i = 0;*str != '\0';str++,i++){
		if(*str == ' '){
			j++;
			word[i] = '\0';
			i = -1; 
			if(isPol(word)){
				num[k] = j;
				k++;
				count++;
			}
		}else{
			word[i] = *str;
		}	
	}
	j++;
	word[i] = '\0';
	if(isPol(word)){
		num[k] = j;
		k++;
		count++;
		}

	return count;
}

void uptolow(char *str){
	for(;*str != '\0';str++){
		if(*str >= 'A' && *str <= 'Z'){
			*str = *str + 'a' - 'A';
		}
	}
}






















