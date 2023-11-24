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
void sort(int ar[] , int n) //Function to Sort Array
{
    int temp; //Variable to Swap
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-1 ; j++)
        {
            if(ar[j]>ar[j+1]) //checking whether the position is right or not and if it is wrong swapping it
            {
                temp=ar[j]; //Swapping
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    display(ar,n); //Display The Sorted Array
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
    sort(arr,n);
}
