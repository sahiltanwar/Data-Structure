#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void EnQueue()
{
	struct node *n1;
	int value;
	n1 = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the elements in queue : ");
	scanf("%d", &value);
	
	n1->data = value;
	n1->next =NULL;
	if(front==NULL)
	{
		front = rear = n1;
	}
	else
	{
		rear->next=n1;
		rear = n1;
	}
	printf("\nInsertion success !!\n");
}
void DeQueue()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("\nQueue is Empty !!\n");
	}
	else
	{
		temp=front;
		printf("\n%d  is deleted \n",temp->data);
		front=front->next;
		
		free(temp);
	}
}
void Display()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(front==NULL)
	{
		printf("\nQueue is Empty !!\n");
	}
	else
	{
		printf("\nYour Queue is : \n");
		temp=front;
		while(temp->next!=NULL)
		{
			printf("%d --> ", temp->data);
			temp=temp->next;
		}
		printf("%d --> NULL", temp->data);
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n\n\t------------------------------\n");
		printf("\t\t   MENU\n");
		printf("\n\t\t1) EnQueue\n");
		printf("\t\t2) DnQueue\n");
		printf("\t\t3) Display\n");
		printf("\t\t4) Exit\n");
		printf("\n\n\t------------------------------\n");
		printf("\n\nEnter ur choice : ");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:	
					EnQueue();
					break;
			case 2:	
					DeQueue();
					break;
			case 3:	
					Display();
					break;
			case 4:
					return 0;
			default : 
					printf("Wrong choice ");
					break;
		}
	}
}
