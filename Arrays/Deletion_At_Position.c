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
void delete(int ar[],int n)//Function To delete a Element 
{
    int po;
    printf("Enter The Position To Delete :- "); //Taking The Position to Delete
    scanf("%d",&po);
    po=po-1; //Coverting position to index
    if(po<0 && po>=n) //Checking for Wrong Index/Position
    {
        printf("Wrong Position .\n");
    }
    else
    {
        for(int i=po ; i<n-1 ; i++)//Shifting Element Towards right
        {
            ar[i]=ar[i+1];
        }
        n=n-1; //Decrementing The Size of Array By 1
        display(ar,n); //Printing The Updated Array
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
