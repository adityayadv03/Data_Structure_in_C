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
void insert(int ar[] , int n)
{
    int el,po;
    int check=1;
    printf("Enter the Element To Insert :- ");
    scanf("%d",&el);
    printf("Enter The Index To Insert :- ");
    scanf("%d",&po);
    if(po<0 || po>=n)
    {
        printf("Wrong Position .");
        check=0;
    }
    else
    {
        for(int i=n-1 ; i>po ; i--)
        {
            ar[i]=ar[i-1];
        }
        ar[po]=el;
    }
    if(check==1)
    {
        display(ar,n);
    }
    else
    {
        display(ar,n-1);
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
