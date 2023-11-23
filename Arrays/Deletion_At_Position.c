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
void delete(int ar[],int n)
{
    int po;
    printf("Enter The Position To Delete :- ");
    scanf("%d",&po);
    po=po-1;
    if(po<0 && po>=n)
    {
        printf("Wrong Position .\n");
    }
    else
    {
        for(int i=po ; i<n-1 ; i++)
        {
            ar[i]=ar[i+1];
        }
        n=n-1;
        display(ar,n);
    }
}
int main()
{
    int n;
    printf("Enter The Number of Element :- "); //Taking Size of Array From User
    scanf("%d",&n);
    int arr[n]; //Declaring the Array
    printf("Enter the Elements :- ");
    for(int i=0 ; i<n ; i++) //Taking Input
    {
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    printf("\n");
    delete(arr,n);
}
