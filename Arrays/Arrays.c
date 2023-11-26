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
    int n,ch;
    printf("Enter The Number of Element :- "); //Taking Size of Array From User
    scanf("%d",&n);
    int arr[n]; //Declaring the Array
    printf("Enter the Elements :- ");
    for(int i=0 ; i<n ; i++) //Taking Input
    {
        scanf("%d",&arr[i]);
    }
    printf("1.Display . \n");
    printf("2.Insertion At Any Position . \n");
    printf("3.Deletion At Any Position . \n");
    printf("4.Sorting Array . \n");
    printf("5.Searching In Array . \n");
    printf("Enter Your Choice :- ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            display(arr,n);
        break;
        case 2:
            insert(arr,n+1);
        break;
        case 3:
            delete(arr,n);
        break;
        case 4:
            sort(arr,n);
        break;
        case 5:
            search(arr,n);
        break;
        default:
            printf("Wrong Choice . \n");
        break;
    }
}
