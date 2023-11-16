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
Node *deleteafterno(Node *ins,int afno) //Function To Delete a node After any Number
{
    if(ins==NULL) //Checking if The Linked List Exist or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item . ");
    }
    else //If The List Exist Deleting the Specified Node
    {
        int check=0;
        Node *prev=ins; //Creating two pointer to traverse and insert the two node
        temp=ins->next;
        while(prev->next!=NULL) //Traversing till the we reach the last node
        {
            if(prev->data==afno) //Checking for the Number after which we have to delete
            {
                prev->next=temp->next;
                check=1;
                break; //Breaking after Delete so the number of iteration can be reduce
            }
            prev=temp;
            temp=temp->next;
        }
        if(prev==NULL && check==0) //For the Condition if the number is not present in list
        {
            printf("The Number Enter is Not Present in The List . \n");
        }
    }
    return ins;
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
    int afterno;
    printf("Enter Number After which You Want To Delete :- ");
    scanf("%d",&afterno);
    head=deleteafterno(head,afterno);
    display(head);
}
