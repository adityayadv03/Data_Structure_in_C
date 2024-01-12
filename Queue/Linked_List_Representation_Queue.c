/*Author :- Aditya Yadav */
#include<stdio.h> //Queue is Represented by Linked list in the following Program
#include<stdlib.h>
struct node //Basic Node To represent One Element Of Queue
{
	int data;
	struct node *next;
};
typedef struct node Node; //Define a shortname to struct node as Node
Node *front=NULL;
Node *rear;
void ins(int val)
{
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
int del()
{
	int val;
	if(front==NULL)
	{
		printf("\nUnderflow . \n");
		printf("\n");
		val=-1;
	}
	else
	{
		val=front->data;
		front=front->next;
	}
	return val;
}
void peek()
{
	if(front==NULL)
	{
		printf("\nQueue is Empty . ");
		printf("\n");
	}
	else
	{
		printf("\nThe first Element is :- %d . \n",front->data);
	}
	printf("\n");
}
void display()
{
	if(front==NULL)
	{
		printf("\nQueue is Empty . ");
	}
	else
	{
		rear=front;
		printf("\nElement of Queue :- ");
		while(rear!=NULL)
		{
			printf("%d ",rear->data);
			rear=rear->next;
		}
	}
	printf("\n\n");
}
int main()
{
	int ch,value;
	do
	{
		printf("Welcome To Queue . \n");
		printf("1.Insertion . \n");
		printf("2.Deletion . \n");
		printf("3.Peek . \n");
		printf("4.Display . \n");
		printf("5.Exit . \n");
		printf("Enter Your Choice :- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Value To Insert :- ");
				scanf("%d",&value);
				ins(value);
				break;
			case 2:
				value=del();
				if(value!=-1)
				{
					printf("\nElement Deleted :- %d . \n",value);
					printf("\n");
				}
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Thank You . \n");
				break;
			default:
				printf("Wrong Choice . \n");
				break;
		}
	}while(ch!=5);
}
