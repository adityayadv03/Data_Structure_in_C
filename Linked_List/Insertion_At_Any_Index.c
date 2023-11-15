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
int countnode(Node *cou)
{
    int co=0;
    while(cou!=NULL)
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
Node *ins_ind(Node *ins)
{
    if(ins==NULL)
    {
        printf("List is Empty . \n");
        printf("First Insert Item . \n");
    }
    else
    {
        int in,val;
        printf("Enter the Postion To Insert :- ");
        scanf("%d",&in);
        in=in-1;
        printf("Enter the Number To Insert :- ");
        scanf("%d",&val);
        int num=countnode(ins);
        if(in>=0 && in<=num)
        {
            Node *new;
            new=(Node*)malloc(sizeof(Node));
            new->data=val;
            new->next=NULL;
            Node *prev=ins;
            temp=ins;
            for(int i=0 ; i<=num ; i++)
            {
                if(in==0)
                {
                    new->next=ins;
                    ins=new;
                    break;
                }
                else if(i==in)
                {
                    new->next=temp;
                    prev->next=new;
                    break;
                }
                prev=temp;
                temp=temp->next;
            }
        }
        else
        {
            printf("Wrong Choice . \n");
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
