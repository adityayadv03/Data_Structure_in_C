#include<stdio.h>
void display(int ar[],int n)
{
    printf("Element Are :- ");
    for(int i=0 ; i<n ; i++)
    {
        printf("%d ",ar[i]);
    }
}
int main()
{
    int n;
    printf("Enter The Number of Element :- ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements :- ");
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    display(arr,n);
}