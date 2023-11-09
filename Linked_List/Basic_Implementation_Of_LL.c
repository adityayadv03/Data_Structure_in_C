#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *head;
Node *temp;
Node *insert(Node *ins,int val)
{
    Node *new;
    new=(Node*)malloc(sizeof(Node));
    new->data=val;
    new->next=NULL;
    if(ins==NULL)
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
void display(Node *dis)
{
    if(dis==NULL)
    {
        printf("List is Empty . \n");
        printf("First Insert Item .");
    }
    else
    {
        printf("List Element are :- ");
        while(dis!=NULL)
        {
            printf("%d ",dis->data);
            dis=dis->next;
        }
    }
    printf("\n");
}
int main()
{
    int n,value;
    printf("Enter the Number Of Nodes :- ");
    scanf("%d",&n);
    while(n-->0)
    {
        printf("Enter The Element :- ");
        scanf("%d",&value);
        head=insert(head,value);
    }
    display(head);
}
