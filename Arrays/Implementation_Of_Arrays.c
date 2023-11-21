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
}
