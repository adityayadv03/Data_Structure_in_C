/*Author :- Aditya Yadav */
#include<stdio.h> //Stack is Represented by Array in the Following Program
#define max 7 //the Size of max to 7
int st[max],top=NULL; //Declaring the Stack as Array of Size max and the top variable to NULL
void push(int value) //Function to insert or push any value in the Stack
{
	if(top==max-1) //Checking if the Stack is Full or Not If the Condition is True then Displaying the message Overflow
	{
		printf("\nOverflow . \n");
		printf("\n");
	}
	else //If the Condition is False then inserting the Value
	{
		top++;
		st[top]=value;
	}
}
void pop() //Function to Delete or pop any Value From Stack
{
	int val; //Variable to Store the deleted Value
	if(top==NULL) //Checking Whether the Stack is Empty or Not if the condition is true then the Stack is Empty
	{
		printf("\nUnderflow . \n");
		printf("\n");
	}
	else // If Condition is False then Poping the Variable
	{
		val=st[top];
		top--;
		printf("Element Deleted is %d . ",val);
		printf("\n");
	}
}
void display() //Fucntion to Display All the Element Present in Stack
{
	if(top==NULL) //Checking Whether the Stack is Empty or Not if the condition is true then the Stack is Empty
	{
		printf("Stack is Empty . ");
	}
	else //If Condition is False Then Displaying the Present Element
	{
		printf("Stack Elements Are :- ");
		for(int i=top ; i>0 ; i--)
		{
			printf("%d ",st[i]);
		}
	}
	printf("\n");
}
int main()
{
	int value,ch;
	do //Creating a Menu Driven Program to Successively perform push or pop operation
	{
		printf("1.Push . \n");
		printf("2.Pop . \n");
		printf("3.Display . \n");
		printf("4.Exit .\n");
		printf("Enter the Choice :- "); //Taking Choice of User
		scanf("%d",&ch);
		switch(ch) //Checking the Choice with help or Switch Case
		{
			case 1:
				printf("Enter the Value To Insert :- ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Thank You . \n");
				break;
			default :
				printf("Wrong Choice . \n");
				break;
		}
	}while(ch!=4);
}
