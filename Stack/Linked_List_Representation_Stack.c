/*Author :- Aditya Yadav */
#include<stdio.h> //Stack is Represented by Linked list in the following Program
#include<stdlib.h>
struct node //Basic Node To represent One Element Of Stack
{
	int data;
	struct node *next;
};
typedef struct node Node; //Define a shortname to struct node as Node
Node *top=NULL; //Initially the top is NULL and Stack is Empty
void push(int val) //Function to Push any Value in the Stack
{
	struct node *newnode; //Creating a Newnode
	newnode=(Node *)malloc(sizeof(Node));
	newnode->data=val;
	if(top==NULL) //If the Top is NULL then newnode fill be the first element and top value is the value of Newnode
	{
		newnode->next=NULL;
		top=newnode;
	}
	else //Else we will add the newnode to the starting
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop() //Function to Pop a Value from the Linked List
{
	int data;
	if(top==NULL) //Checking Whether the top value is NULL or Not if it is NULL The pop function cant be perform
	{
		printf("\nUnderflow . \n");
	}
	else //Else Removing the first Element of Stack
	{
		data=top->data;
		printf("\nElement Deleted :- %d . \n",data);
		top=top->next;
	}
	printf("\n");
}
int peek() //Function to See the Value of the Top element in Stack
{
	if(top==NULL) //If the Stack is Already Empty then returning -1
	{
		return -1;
	}
	else //Else returning the top Value
	{
		return top->data;
	}
}
void display() //Function to Display all the element present in stack
{
	Node *temp;
	temp=top;
	if(temp!=NULL) //If Top is Not NULL then only the Value can be printed
	{
		printf("\nElement Of Stack :- ");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	else //if the top is Null then printing a appropriate message
	{
		printf("\nStack is Empty . \n");
	}
	printf("\n");
}
int main() //Main Function to Make a Menu Driven Program and calling the above functions Correctly
{
	int value,ch;
	do //Using Do while Loop
	{
		printf("1.Push . \n");
		printf("2.Pop . \n");
		printf("3.Peek . \n");
		printf("4.Display . \n");
		printf("5.Exit .\n");
		printf("Enter the Choice :- "); //Taking User Choice For the above menu
		scanf("%d",&ch);
		switch(ch) //Using Switch Case to Call the Right Function
		{
			case 1:
				printf("Enter the Value To Push :- ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				value=peek();
				if(value==-1)
				{
					printf("\n");
					printf("Stack is Empty . \n");
					printf("\n");
				}
				else
				{
					printf("\nValue At Top is %d . \n",value);
					printf("\n");
				}
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Thank You . \n");
				break;
			default :
				printf("Wrong Choice . \n");
				break;
		}
	}while(ch!=5);
}
