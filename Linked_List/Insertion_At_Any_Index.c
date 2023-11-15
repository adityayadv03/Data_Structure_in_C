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
int countnode(Node *cou) //Function To Count Number of Node
{
    int co=0;
    while(cou!=NULL) //Running Till Finding the Last Node
    {
        co=co+1;
        cou=cou->next;
    }
    return co;
}
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
Node *ins_ind(Node *ins) //Function to Insert Node at any Index
{
    if(ins==NULL) //Checking whether Linked List Exist Or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item . \n");
    }
    else
    {
        int in,val;
        printf("Enter the Postion To Insert :- "); //Taking Postion to Insert
        scanf("%d",&in);
        in=in-1; //Converting the position to index
        printf("Enter the Number To Insert :- "); //Taking value to insert
        scanf("%d",&val);
        int num=countnode(ins); //Finding the Number of Nodes
        if(in>=0 && in<=num)
        {
            Node *new;
            new=(Node*)malloc(sizeof(Node)); //Creating a Node
            new->data=val;
            new->next=NULL;
            Node *prev=ins;
            temp=ins;
            for(int i=0 ; i<=num ; i++) //Here we have use till smaller than equal to so that we can add node in last position
            {
                if(in==0) //Checking if we have to insert at the starting or not
                {
                    new->next=ins;
                    ins=new;
                    break;
                }
                else if(i==in) //For any Other Index
                {
                    new->next=temp;
                    prev->next=new;
                    break; //Breaking the condition to reduce iteration 
                }
                prev=temp;
                temp=temp->next;
            }
        }
        else
        {
            printf("Wrong Choice . \n"); //if User enter Wrong index Printing a Meaningful Message
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
    head=ins_ind(head);
    display(head);
}
