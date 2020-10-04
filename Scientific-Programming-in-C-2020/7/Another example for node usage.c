#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char code[10];
	char courses[50];
	struct node *next;
};

struct node *Node_head = NULL;

char *LCode[6] = {"EE311","EE411","EE425","EE443","EE455","EE461"};
char *LCourse[6] = {"Digital Electronics","Fundamentals of Photonics","Microwave Engineering","Embedded Systems","Mobile Communication","Nonlinear Control Systems"}; 

void add_front(int selection){
	struct node *node;
	node = malloc(sizeof(struct node));
	strcpy(node->code , LCode[selection]);
	strcpy(node->courses , LCourse[selection]);
	printf("%s",node->courses);
	node->next = Node_head;
	Node_head = node;
}


void add_end(int selection){
	struct node *node;
	struct node *temp = Node_head;
	node = (struct node*)malloc(sizeof(struct node));
	strcpy(node->code , LCode[selection]);
	strcpy(node->courses , LCourse[selection]);
	node->next = NULL;
	if(Node_head == NULL){
		Node_head = node;
	}
	else{
		for(;temp->next != NULL;temp = temp->next);
		temp->next = node;
	}
}

void show_items(void){
	struct node *temp = Node_head;
	for(;temp != NULL;temp = temp->next){
		printf("%s -- %s\n",temp->code,temp->courses);
	}
}

int check(int selection){
	struct node *temp = Node_head;
	for(;temp != NULL;temp = temp->next){
		if(!strcmp(temp->code,LCode[selection]))
			return 0;
	}
	return 1;
}

void ndelete(int selection){
	struct node *temp = Node_head;
	struct node *prev;
	for(;temp != NULL;temp = temp->next){
		if(!strcmp(temp->code,LCode[selection])){
			break;
		}
		prev = temp;	
	}
	if(temp == Node_head){
		Node_head = temp->next;
	}else {
		prev->next = temp->next;
	}
}



int main(){
	int choice,selection;
	int i;
	printf("**********LECTURE LIST*********\n");
	for(i=0;i<6;i++){
		printf("%d - %s -- %s\n",i,LCode[i],LCourse[i]);	
	}
	
	while(1){
		printf("Choose an option\n1::Add to front\n2::Add to end\n3::Print the items\n4::Delete\n0::Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter your selection\n");
				scanf("%d",&selection);
				if(check(selection)){
					add_front(selection);
				}else{
					printf("This course is already exist\n");
				}
				
				break;
			case 2:
				printf("Enter your selection\n");
				scanf("%d",&selection);
				if(check(selection)){
					add_end(selection);
				}else{
					printf("This course is already exist\n");
				}
				break;
			case 3:
				show_items();
				break;
			case 4:
				printf("Enter your selection\n");
				scanf("%d",&selection);
				ndelete(selection);
				break;
			case 0:
				exit(0);
			default:
				break;
		}
	}	
	
	
	
	
	
	
	
	
	
	
	
	
	return 1;
}
