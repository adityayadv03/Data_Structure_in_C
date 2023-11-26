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
Node *deleteend(Node *ins) //Function To Delete a node in End
{
    if(ins==NULL) //Checking if The Linked List Exist or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item . ");
    }
    else //If The List Exist Deleting the Last Node
    {
        temp=ins;
        Node *prev;
        while(temp->next!=NULL) //Running the Loop Till the last Last Node
        {
            prev=temp; //Storing the Second last Node
            temp=temp->next; //Moving the Pointer to Next Address
        }
        prev->next=temp->next; //Storing the last node next address(NULL) to the Second Last Node
        free(temp); //Removing the Allocated Last node from the memory
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
    display(head);
    head=deleteend(head); //Deletion at End By The Mention Function
    display(head);
}
