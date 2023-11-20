/*Author :- Aditya Yadav */
#include<stdio.h>
#include<stdlib.h> //Library To Use Malloc Function Its a Standard Library
struct node //Basic Structure of Each Node
{
    int data;
    struct node *next; //A Pointer Element To Store The Location of Structure like its own
};
typedef struct node Node; //To use a Short Form
Node *head; //Head Node
Node *temp; //Temporary Node
Node *insert(Node *ins,int val) //Inserting New Node Or To Create a fresh Linked List
{
    Node *new;
    new=(Node*)malloc(sizeof(Node)); //Allocating the Size
    new->data=val;
    new->next=NULL;
    if(ins==NULL) //Checking whether Linked List Exist Or Not
    {
        ins=new;
        temp=new;
    }
    else
    {
        temp->next=new;
        temp=new;
    }
    return ins;
}
void display(Node *dis) //Printing the Complete Linked List
{
    if(dis==NULL) //Checking whether Linked List Exist Or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item .");
    }
    else
    {
        printf("List Element are :- "); //If List Exist Then Printing It
        while(dis!=NULL)
        {
            printf("%d ",dis->data);
            dis=dis->next;
        }
    }
    printf("\n");
}
void search(Node *srh) //Function To Search a Element In A Linked List
{
    int n,check=0,count=0;
    printf("Enter The Number To Search :- "); //Taking The Number From User
    scanf("%d",&n);
    while(srh!=NULL) //Running the Loop Till To Traverse the Whole List
    {
        count++; //Counting the Position of Traverse Node
        if(srh->data==n) //Checking with each Element 
        {
            printf("Element Found At %d . ",count); //if Element Found Printing its Position
            check=1;
            break;
        }
        srh=srh->next;
    }
    if(srh==NULL && check==0) //If the Element is Not Found then Printing a Meaningful Message
    {
        printf("Element Not Found . ");
    }
}
int main()
{
    int n,value;
    printf("Enter the Number Of Nodes :- "); //Taking The Number of Nodes From user
    scanf("%d",&n);
    while(n-->0)
    {
        printf("Enter The Element :- ");
        scanf("%d",&value);
        head=insert(head,value); //Adding the Value By Insert Function Declare Above
    }
    display(head);
    search(head);
}
