/*Author :- Aditya Yadav */
#include<stdio.h> //Stack is Represented by Array in the Following Program
#define max 10
int que[max],front=-1,rear=-1;
void ins(int val)
{
	if(rear==max-1)
	{
		printf("\nOverflow . \n");
		printf("\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		que[rear]=val;
		printf("\nElement Inserted . \n");
		printf("\n");
	}
	else
	{
		rear=rear+1;
		que[rear]=val;
		printf("\nElement Inserted . \n");
		printf("\n");
	}
}
int del()
{
	int val;
	if(front==-1 || front>rear)
	{
		printf("\nUnderflow . \n");
		printf("\n");
		val=-1;
	}
	else
	{
		val=que[front];
		front=front+1;
	}
	return val;
}
void peek()
{
	if(front==-1 || front>rear)
	{
		printf("\nQueue is Empty . ");
		printf("\n");
	}
	else
	{
		printf("\nThe first Element is :- %d . \n",que[front]);
	}
	printf("\n");
}
void display()
{
	if(front==-1 || front>rear)
	{
		printf("\nQueue is Empty . ");
		printf("\n");
	}
	else
	{
		printf("\nQueue Element :- ");
		for(int i=front ; i<=rear ; i++)
		{
			printf("%d ",que[i]);
		}
		printf("\n");
	}
	printf("\n");
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
