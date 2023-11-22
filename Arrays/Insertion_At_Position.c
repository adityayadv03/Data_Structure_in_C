/*Author :- Aditya Yadav */
#include<stdio.h>
void display(int ar[],int n) //Function To Display the Array
{
    printf("Element Are :- ");
    for(int i=0 ; i<n ; i++) //Running loop till array length 
    {
        printf("%d ",ar[i]);
    }
}
void insert(int ar[] , int n) //Function To Insert A Element
{
    int el,po; //Declaring Variable For Element and Position
    int check=1;
    printf("Enter the Element To Insert :- "); //Taking Input Element 
    scanf("%d",&el);
    printf("Enter The Index To Insert :- "); //Taking Input Position
    scanf("%d",&po);
    if(po<0 || po>=n)//Checking for Wrong Index
    {
        printf("Wrong Position .\n");
        check=0;
    }
    else
    {
        for(int i=n-1 ; i>po ; i--) // Shifting Element By One Position Backward
        {
            ar[i]=ar[i-1];
        }
        ar[po]=el; //Inserting Element to position
    }
    if(check==1)
    {
        display(ar,n); //Printing if Element is Inserted
    }
    else
    {
        display(ar,n-1); //Printing if Element is Not Inserted
    }
}
int main()
{
    int n;
    printf("Enter The Number of Element :- "); //Taking Size of Array From User
    scanf("%d",&n);
    int arr[n+1]; //Declaring the Array
    printf("Enter the Elements :- ");
    for(int i=0 ; i<n ; i++) //Taking Input
    {
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    printf("\n");
    insert(arr,n+1);
}
