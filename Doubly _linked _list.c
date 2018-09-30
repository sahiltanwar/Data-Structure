#include<stdio.h>
#include<stdlib.h>

void insertAtBegin();
void insertAtEnd();
void insertSpecific(int);
void deleteAtBegin();
void deleteAtEnd();
void deleteSpecific(int);
void display();

struct dll
{
	struct dll* prev;
	int data;
	struct dll* next;
}*s;

void create()
{
	int n, data, i;
	struct dll *Node, *p;

	printf("Enter size of linked-list : ");
	scanf("%d",&n);

	s = (struct dll*)malloc(sizeof(struct dll));

	if(s == NULL)
	{
		printf("Memory could not be located for the linked list!!!");
	}
	else
	{
		printf("\tData at node 1 : ");
		scanf("%d",&(s->data));
		s->prev = NULL;
		s->next = NULL;

		p = s;

		i=2;
		while(i<=n)
		{
			Node = (struct dll*)malloc(sizeof(struct dll));
			if(Node == NULL)
			{
				printf("Memory could not be located to this node!!!!");
				break;
			}
			else
			{
				printf("\tData at Node %d : ",i);
				scanf("%d",&(Node->data));
				Node->next = NULL;
				Node->prev = p;
				p->next = Node;
				p = p->next;
			}
			i++;
		}

		printf("Doubly Linked List Created!!!\n\n");
	}
}
int main()
{
   	int choice, location;
   	create();
   	while(1)
   	{
    	printf("\n*********** MENU *************\n");
      	printf("1. Insert at begin \n");
	  	printf("2. insert at end \n");
	  	printf("3. insert after Specific node \n");
	  	printf("4. Delete at begin\n");
	  	printf("5. Delete at end \n");
	  	printf("6. Delete Specific node \n");
	  	printf("7. Display \n");
		  printf("8. Exit \n");
		printf("\n\nEnter your choice: ");
      	scanf("%d",&choice);
      	
		switch(choice)
      	{
        	case 1: 	
		   			insertAtBegin();
               		break;
            case 2: 	
					insertAtEnd();
                    break;
      	    case 3: 	
					printf("Enter the node after which you want to insert: ");
                    scanf("%d",&location);
                    insertSpecific(location);
                    break;
            
            case 4:
                    deleteAtBegin();
                    break;
			case 5:
					deleteAtEnd();
					break;
			case 6:
					printf("Enter the node that you want to delete : ");
                    scanf("%d",&location);
					deleteSpecific(location);
					break;
			case 7:
                    display();
                    break;
			case 8:
                    return 0;
			default: 
					printf("\nPlease select correct option!!!");
      	}
	}
}
void insertAtBegin()
{
	struct dll  *newNode;
	int value;
	newNode = (struct dll *)malloc(sizeof(struct dll));
	
	printf("Enter the data : ");
	scanf("%d",&value);
	newNode->data=value;
	newNode->next=NULL;
	
	if(s==NULL)
	{
		newNode->next=NULL;
		s=newNode;
	}
	else
	{
		newNode->next=s;
		s=newNode;
	}
	printf("\nInsertion success!!!\n");
}
void insertAtEnd()
{
	struct dll  *newNode;
	int value;
	newNode = (struct dll *)malloc(sizeof(struct dll));
	printf("\nEnter the data : ");
	scanf("%d",&value);
	newNode->data=value;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(s==NULL)
	{
		newNode->prev=NULL;
		s=newNode;
	}
	else
	{
		struct dll *temp;
		temp=s;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
			temp->next=newNode;
			newNode->prev=temp;
		printf("\nInsertion success!!!\n");
	}
}
void insertSpecific(int x)
{
	struct dll  *newNode, *temp;
	int value;
	newNode = (struct dll *)malloc(sizeof(struct dll));
	printf("\nEnter the data : ");
	scanf("%d",&value);
	newNode->data=value;
	if(s==NULL)
	{
		newNode->prev=NULL;
		newNode->next=NULL;
		s=newNode;
	}
	else
	{
		struct dll *temp1, *temp2;
		temp1=s;
		while(temp1->data!=x)
		{
			if(temp1->next==NULL)
			{
				printf("\nGiven node not found\n");
			}
			else
			{
				temp1=temp1->next;
			}
		}
		temp2=temp1->next;
		temp1->next=newNode;
		newNode->prev=temp1;
		newNode->next=temp2;
		temp2->prev=newNode;
		printf("\nInsertion success\n");
	}
}
void deleteAtBegin()
{
	if(s==NULL)
	{
		printf("\nList is empty!!! Deletion is not possible\n");
		return;
	}
	else
	{
		struct dll *temp;
		temp=s;
		if(temp->prev==temp->next)
		{
			s=NULL;
			free(temp);
		}
		else
		{
			s=temp->next;
			s->prev=NULL;
			free(temp);
		}
		printf("\nDeletion success!!!\n");
	}
}
void deleteAtEnd()
{
	if(s==NULL)
	{
		printf("\nList is Empty!!! Deletion is not possible\n");
		return;
	}
	else
	{
		struct dll *temp;
		temp=s;
		if(temp->prev==temp->next)
		{
			s=NULL;
			free(temp);
			
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
				temp->prev->next=NULL;
				
				free(temp);
			printf("\nDeletion success!!!\n");
		}
	}
}
void deleteSpecific(int x)
{
	if(s==NULL)
	{
		printf("\nList is Empty!!! Deletion is not possible\n");
		return;
	}
	else
	{
		struct dll *temp;
		temp=s;
		while(temp->data!=x)
		{
			if(temp->next==NULL)
			{
				printf("\nGiven node is not found\n");
				return;
			}
			else
			{
				temp=temp->next;
			}
		}
		if(temp==s)
		{
			s=s->next;
			s->prev=NULL;
			free(temp);
		}
		else if(temp->next==NULL)
		{
			temp->prev->next=NULL;
			free(temp);
		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
		printf("\nDeletion success!!!\n");
	}
}

void display()
{
	struct dll *p;
	printf("\nDoubly Linked List :\n");
	if(s==NULL)
	{
		printf("\nEmpty Doubly Linked List!!!\n");
	}
	else
	{
		p = s;
		int i=1;
		while(p!=NULL)
		{
			printf("\t%2d. %2d\n",i,p->data);
			p = p->next;
			i++;
		}
	}

}


