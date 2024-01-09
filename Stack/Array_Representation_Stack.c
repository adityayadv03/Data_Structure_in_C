/*Author :- Aditya Yadav */
#include<stdio.h> //Stack is Represented by Array in the Following Program
#define max 7
int st[max],top=NULL;
void push(int value)
{
	if(top==max-1)
	{
		printf("\nOverflow . \n");
		printf("\n");
	}
	else
	{
		top++;
		st[top]=value;
	}
}
void pop()
{
	int val;
	if(top==NULL)
	{
		printf("\nUnderflow . \n");
		printf("\n");
	}
	else
	{
		val=st[top];
		top--;
		printf("Element Deleted is %d . ",val);
		printf("\n");
	}
}
void display()
{
	if(top==NULL)
	{
		printf("Stack is Empty . ");
	}
	else
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
	do
	{
		printf("1.Push . \n");
		printf("2.Pop . \n");
		printf("3.Display . \n");
		printf("4.Exit .\n");
		printf("Enter the Choice :- ");
		scanf("%d",&ch);
		switch(ch)
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
