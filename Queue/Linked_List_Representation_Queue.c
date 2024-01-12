/*Author :- Aditya Yadav */
#include<stdio.h> //Queue is Represented by Linked list in the following Program
#include<stdlib.h>
struct node //Basic Node To represent One Element Of Queue
{
	int data;
	struct node *next;
};
typedef struct node Node; //Define a shortname to struct node as Node
Node *front=NULL; //Initially the front is NULL and Queue is Empty
Node *rear;
void ins(int val) //Function to Insert any Value in the Queue
{
	Node *newnode; //Creating a Newnode
	newnode=(Node *)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	if(front==NULL) //If the front is NULL then newnode is the first element and position is stored to front and rear
	{
		front=newnode;
		rear=newnode;
	}
	else //else newnode is added after rear
	{
		rear->next=newnode;
		rear=newnode;
	}
}
int del() //Function to delete any element From Queue
{
	int val;
	if(front==NULL) //Checking whether the queue is empty or not if the front is NULl then Queue is Empty
	{
		printf("\nUnderflow . \n");
		printf("\n");
		val=-1;
	}
	else //Otherwise Deleting the element from front
	{
		val=front->data;
		front=front->next;
	}
	return val;
}
void peek() //Function to check the first element of Queue
{
	if(front==NULL) //Checking whether the queue is empty or not if the front is NULl then Queue is Empty
	{
		printf("\nQueue is Empty . ");
		printf("\n");
	}
	else //otherwise printing the first element
	{
		printf("\nThe first Element is :- %d . \n",front->data);
	}
	printf("\n");
}
void display() //Function to display all the element of Queue
{
	if(front==NULL) //Checking whether the queue is empty or not if the front is NULl then Queue is Empty
	{
		printf("\nQueue is Empty . ");
	}
	else //otherwise printing all the elements
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
int main() //Main Function to Make a Menu Driven Program and calling the above functions Correctly
{
	int ch,value;
	do //Using Do while Loop
	{
		printf("Welcome To Queue . \n");
		printf("1.Insertion . \n");
		printf("2.Deletion . \n");
		printf("3.Peek . \n");
		printf("4.Display . \n");
		printf("5.Exit . \n");
		printf("Enter Your Choice :- "); //Taking User Choice For the above menu
		scanf("%d",&ch);
		switch(ch) //Using Switch Case to Call the Right Function
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
