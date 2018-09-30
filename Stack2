#include<stdio.h>
#include<stdlib.h>
 
void push();
void pop();
void display();

struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;


int main()
{
	int choice, ch;
	while(1)
	{	
		printf("\n\n\t***********************************\n");
		printf("\t\tSelect an operation\n\n");
		printf("\t\t1) Push\n");
		printf("\t\t2) Pop\n");
		printf("\t\t3) Display\n");
		printf("\t\t4) Exit\n");
		printf("\t***********************************\n");
		
		printf("\nEnter ur choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
					push();
					break;
			case 2: 
					pop();
					break;
			case 3: 
					display();
					break;
			case 4: 
					return 0 ;
			default : 
					printf("Wrong choice");
					break;
		}
	}
	
}
void push()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	if(temp==NULL)
	{
		printf("Memory annot be allocated");
	}
	
	printf("Enter the item : ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	printf("%d is pushed", temp->data);
		if(start==NULL)
		{
			start=temp;
		}
	else
	{
		
		temp->next=start;
		start=temp;
	}
}
void pop()
{
	struct node *del;
	if(start==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		del = start;
		start = start->next;
		printf("%d is popped", del->data);
		free(del);
	}
}
void display()
{
	struct node *tmp;
	if(start==NULL)
	{
		printf("\nThere is no item in the stack\n Stack is empty");
	}
	else
	{
		printf("Your stack is :\n");
		tmp = start;
		while(tmp!=NULL)
		{
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
	}
}
