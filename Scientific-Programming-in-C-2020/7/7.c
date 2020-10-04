#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32

struct node {
	int id;
	char name[N];
	struct node *next;
};

struct node *head = NULL;

void insert(int id, char *name);

void show_list(void);

void remove_list(int id);

void search(int id);

void clearscreen(void);

void wait(void);

int main(){
	int choice,id;
	char name[32];
	while(1){
		printf("********************************\n");
		printf("1::Insert\n2::Display the list\n3::Search\n4::Remove\n5::Exit\n********************************\n");
		printf("Choose an option-->");
		scanf("%d",&choice);
		clearscreen();
		if(choice == 1){
			printf("Student number:");
			scanf("%d",&id);
			printf("Student name:");
			scanf("%s",name);
			printf("\nStudent %s and number %d added to list\n",name,id);
			insert(id,name);
			wait();
		}else if(choice == 2){
			show_list();
			wait();
		}else if(choice == 3){
			printf("Student number:");
			scanf("%d",&id);
			search(id);
			wait();
		}else if(choice == 4){
			printf("Student number:");
			scanf("%d",&id);
			remove_list(id);
			wait();
		}else if(choice == 5){
			printf("FINISH PROGRAMMING!!!\n");
			break;
		}else{
			printf("FALSE CHOOSE!!!\n");
			wait();
		}
	}
	
	
	
	
	
	
	
	
	return 1;
}



void insert(int id, char *name){
	struct node * temp = NULL;
	temp = malloc(sizeof(struct node));
	
	temp->id = id;
	strcpy(temp->name,name);
	
	temp->next = head;
	head = temp;
}

void show_list(void){
	struct node *temp;
	if(head == NULL){
		printf("\nThe list is empty!!!\n");
	}
	for(temp = head;temp != NULL;temp = temp->next){
		printf("Name %-10s -- id %-5d\n",temp->name,temp->id);
	}
}

void remove_list(int id){
	struct node *temp;
	struct node *prev;
	int flag = 0;
	
	if(head == NULL){
		printf("\nThe list is empty!!!\n");
	}else{
		for(temp = head;temp != NULL;temp = temp->next){
			if(temp->id==id){
				flag = 1;
				break;
			}
			prev = temp;	
		}
		if(flag){
			printf("Student %s and id number of %d has been deleted from the list\n",temp->name,temp->id);
			if(temp == head){
				head = temp->next;
			}else {
				prev->next = temp->next;
			}
			free(temp);
		}else{
			printf("There is no student with this id\n");
		}
	}
	
	
}

void search(int id){
	struct node *temp;
	int flag = 0;
	for(temp = head;temp != NULL;temp = temp->next){
		if(temp->id==id){
			flag = 1;
			break;
		}	
	}
	if(flag){
		printf("Student %s and id %d \n",temp->name,temp->id);
	}else{
		printf("There is no student with this id\n");
	}
}

void clearscreen(void){
	system("cls");
}

void wait(void){
	char temp;
	printf("\nPress Enter to continue!!!\n");
	temp = getchar();
	temp = getchar();
	clearscreen();
}







