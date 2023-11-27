/*Author :- Aditya Yadav */
#include<stdio.h> //A Menu Driven Program to Do All The Mention Task in Linked List Folder
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
Node *create(Node *crt)
{
    int n,value;
    printf("Enter the Number Of Nodes :- "); //Taking The Number of Nodes From user
    scanf("%d",&n);
    while(n-->0)
    {
        printf("Enter The Element :- ");
        scanf("%d",&value);
        crt=insert(crt,value); //Adding the Value By Insert Function Declare Above
    }
    return crt;
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
Node *insertbeg(Node *ins,int val) //Function To Add a node in Begining
{
    if(ins==NULL) //Checking if The Linked List Exist or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item . ");
    }
    else //If The List Exist Creating a new node and inserting it
    {
        Node *new;
        new=(Node*)malloc(sizeof(Node));
        new->data=val;
        new->next=ins;
        ins=new;
    }
    return ins;
}
Node *insertend(Node *ins,int val) //Function To Add a node in Begining
{
    if(ins==NULL) //Checking if The Linked List Exist or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item . ");
    }
    else //If The List Exist Creating a new node and inserting it
    {
        temp=ins; //Using a Temp pointer of structure type to find last Node
        Node *new;
        new=(Node*)malloc(sizeof(Node)); //Creating a new node 
        new->data=val;
        new->next=NULL;
        while(temp->next!=NULL) //finding the last Node as last node have NULL in the next pointer
        {
            temp=temp->next;
        }
        temp->next=new; //adding the new node to the last
    }
    return ins;
}
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
Node *deletebeg(Node *ins) //Function To Delete a node in Begining
{
    if(ins==NULL) //Checking if The Linked List Exist or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item . ");
    }
    else //If The List Exist Deleting the First Node
    {
        temp=ins; //Storing the Completing Linked List
        ins=ins->next; //Moving the Pointer to the next
        free(temp); //Removing the Allocated first node from the memory
    }
    return ins;
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
Node *del_ind(Node *ins) //Function to Delete Node at any Index
{
    if(ins==NULL) //Checking whether Linked List Exist Or Not
    {
        printf("List is Empty . \n");
        printf("First Insert Item . \n");
    }
    else
    {
        int in;
        Node *rem; //Pointer to Remove the allocated Node memory
        printf("Enter the Postion To Delete :- "); //Taking Postion to Delete
        scanf("%d",&in);
        int num=countnode(ins); //Finding the Number of Nodes
        if(in>=1 && in<=num) //Checking Whether the User Enter a Valid Position or Not
        {
            Node *prev=ins; //Pointer to Traverse Through the Linked list
            temp=ins;
            for(int i=1 ; i<=num ; i++)
            {
                if(in==1) //Shifting The Pointer for the First Position
                {
                    rem=ins; //Pointing the Node To Remove From Memory
                    ins=ins->next;
                    free(rem); //Deallocating Using Free
                    break;
                }
                else if(i==in) //For Other Position
                {
                    rem=temp; //Pointing the Node To Remove From Memory
                    prev->next=temp->next;
                    free(rem); //Deallocating Using Free
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
Node *reverse(Node *rev) //Function to Reverse The List
{
    Node *prev=NULL; //Two Pointer to Connect List in Reverse Order
    Node *next=NULL;
    while(rev!=NULL) //Running the Loop To Cover the Complete List
    {
        next=rev->next;
        rev->next=prev;
        prev=rev;
        rev=next;
    }
    rev=prev;
    return rev;
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
            printf("Element Found At %d . \n",count); //if Element Found Printing its Position
            check=1;
            break;
        }
        srh=srh->next;
    }
    if(srh==NULL && check==0) //If the Element is Not Found then Printing a Meaningful Message
    {
        printf("Element Not Found . \n");
    }
}
Node *sort(Node *srt) //Function to Sort Linked List
{
    int temp; //Variable to Swap
    Node *ptr1=srt; //Pointer To Perform Sorting
    Node *ptr2;
    while(ptr1!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data>ptr2->data) //Comparing the First Node data is Greater or Not
            {
                temp=ptr1->data; //Swapping if the Position is Wrong
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return srt;
}
int main()
{
    int ch,newvalue;
    do
    { //Mention All Function Except Deletion and Insertion After Any Number as it is Not That Efficent
        printf("0.Exit . \n"); //Insertion Can Be Done At First Position and First Element Cont be Deleted By these Function
        printf("1.Create A Linked List . \n");
        printf("2.Display Linked List . \n");
        printf("3.Insertion At Begining . \n");
        printf("4.Insertion At End . \n");
        printf("5.Insertion At Any Index . \n");
        printf("6.Deletion At Begining . \n");
        printf("7.Deletion At End . \n");
        printf("8.Deletion At Any Index . \n");
        printf("9.Reversing Linked List . \n");
        printf("10.Searching in Linked List . \n");
        printf("11.Sorting Linked List . \n");
        printf("Enter Your Choice :- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                printf("Thank You . \n");
            break;
            case 1:
                head=create(head);
            break;
            case 2:
                display(head);
            break;
            case 3:
                printf("Enter The Value To Insert :- "); //Taking the Value To Add in List
                scanf("%d",&newvalue);
                head=insertbeg(head,newvalue); //Inserting it To List By The Mention Function
                display(head);
            break;
            case 4:
                printf("Enter The Value To Insert :- "); //Taking the Value To Add in List
                scanf("%d",&newvalue);
                head=insertend(head,newvalue); //Inserting it To List By The Mention Function
                display(head);
            break;
            case 5:
                head=ins_ind(head);
                display(head);
            break;
            case 6:
                head=deletebeg(head); //Deletion at Begining By The Mention Function
                display(head);
            break;
            case 7:
                head=deleteend(head); //Deletion at End By The Mention Function
                display(head);
            break;
            case 8:
                head=del_ind(head);
                display(head);
            break;
            case 9:
                head=reverse(head);
                printf("After Reversing : \n");
                display(head);
            break;
            case 10:
                search(head);
            break;
            case 11:
                head=sort(head); //Calling the Function to Perform Sorting
                display(head);
            break;
            default:
                printf("Wrong Choice . \n");
            break;
        }
    }while(ch!=0);
}
