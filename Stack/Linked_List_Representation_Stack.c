/*Author :- Aditya Yadav */
#include<stdio.h> //Stack is Represented by Linked list in the following Program
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *top=NULL;
void push(int val)
{
	struct node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->data=val;
	if(top==NULL)
	{
		newnode->next=NULL;
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
	int data;
	if(top==NULL)
	{
		printf("\nUnderflow . \n");
	}
	else
	{
		data=top->data;
		printf("\nElement Deleted :- %d . \n",data);
		top=top->next;
	}
	printf("\n");
}
int peek()
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		return top->data;
	}
}
void display()
{
	Node *temp;
	temp=top;
	if(temp!=NULL)
	{
		printf("\nElement Of Stack :- ");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	else
	{
		printf("\nStack is Empty . \n");
	}
	printf("\n");
}
int main()
{
	int value,ch;
	do
	{
		printf("1.Push . \n");
		printf("2.Pop . \n");
		printf("3.Peek . \n");
		printf("4.Display . \n");
		printf("5.Exit .\n");
		printf("Enter the Choice :- ");
		scanf("%d",&ch);
		switch(ch)
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
