/*Author :- Aditya Yadav */
#include<stdio.h> //Queue is Represented by Array in the Following Program
#define max 10 //the Size of max to 10
int que[max],front=-1,rear=-1; //Declaring the Queue as Array of Size max and the front and rear variable to -1
void ins(int val) //Function to insert any value in the Queue
{
	if(rear==max-1) //Checking if the Queue is Full or Not If the Condition is True then Displaying the message Overflow
	{
		printf("\nOverflow . \n");
		printf("\n");
	}
	else if(front==-1 && rear==-1) //If the Queue is Empty then Setting the value of front and rear to 0
	{
		front=0;
		rear=0;
		que[rear]=val; //Inserting Value
		printf("\nElement Inserted . \n");
		printf("\n");
	}
	else //If the Above two Condition False then just inserting value by increasing rear by 1
	{
		rear=rear+1;
		que[rear]=val; //Inserting Value
		printf("\nElement Inserted . \n");
		printf("\n");
	}
}
int del() //Function to Delete or pop any Value From Queue
{
	int val;
	if(front==-1 || front>rear) //If the Queue is Empty then Printing the message Underflow
	{
		printf("\nUnderflow . \n");
		printf("\n");
		val=-1;
	}
	else //Else Removing a Value and Increasing the value of Front by 1
	{
		val=que[front];
		front=front+1;
	}
	return val;
}
void peek() //Fucntion to Display the Element Present in Queue
{
	if(front==-1 || front>rear) //Checking Whether the Queue is Empty or Not if the condition is true then the Queue is Empty
	{
		printf("\nQueue is Empty . ");
		printf("\n");
	}
	else //Else printing the first element
	{
		printf("\nThe first Element is :- %d . \n",que[front]);
	}
	printf("\n");
}
void display() //Fucntion to Display All the Element Present in Queue
{
	if(front==-1 || front>rear) //Checking Whether the Queue is Empty or Not if the condition is true then the Queue is Empty
	{
		printf("\nQueue is Empty . ");
		printf("\n");
	}
	else //Else printing all the element present in the queue
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
	do //Creating a Menu Driven Program to Successively perform insert and delete operation
	{
		printf("Welcome To Queue . \n");
		printf("1.Insertion . \n");
		printf("2.Deletion . \n");
		printf("3.Peek . \n");
		printf("4.Display . \n");
		printf("5.Exit . \n");
		printf("Enter Your Choice :- "); //Taking Choice of User
		scanf("%d",&ch);
		switch(ch) //Checking the Choice with help or Switch Case
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
