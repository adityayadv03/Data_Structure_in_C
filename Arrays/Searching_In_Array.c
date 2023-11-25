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
void search(int ar[],int n) //Function to Search in Array
{
    int ele,po=-1;
    printf("Enter The Element To Search :- "); //Taking Input Of Element To Search
    scanf("%d",&ele);
    for(int i=0 ; i<n ; i++) //Running The Loop To Check Every Element
    {
        if(ele==ar[i]) //Checking With Every Element 
        {
            po=i; //If the Element id Found Storing its Location
            break;
        }
    }
    if(po!=-1) //If The Position is other than -1 Than Element Found 
    {
        po=po+1;
        printf("Element Found :- %d .",po);
    }
    else //If The Position is -1 Then Element Not Found
    {
        printf("Element Not Found . ");
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
    search(arr,n);
}
