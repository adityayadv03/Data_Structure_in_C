/*Author :- Aditya Yadav */
#include<stdio.h>
#include<stdlib.h> //Program to Implement the Binary Search Tree
struct node //Creating a basic node used in a tree
{
    int data; //To Store the integer data of node
    struct node *left,*right; //To store the child Node
};
typedef struct node Node; //Create a shortcut of struct node as Node
void createBST(Node* root,int val) //Function to insert a Newnode in the Binary Search Tree 
{
    Node* prev=NULL;
    while(root!=NULL) //Traversing till we find the last Null Node
    {
        prev=root; //Storing the previous node address
        if(root->data==val) //Checking if the Value we want to insert is already present we will not insert it
        {
            return;
        }
        else if(val<root->data) //If the Value we want to insert in smaller than the current node value we will go to left subtree
        {
            root=root->left;
        }
        else //If the Value we want to insert in greater than the current node value we will go to Right subtree
        {
            root=root->right;
        }
    } //After finding the right place to insert the node
    Node* newnode;
    newnode=(Node*)malloc(sizeof(Node)); //Creating the Newnode and allocating the memory
    newnode->data=val; //Inserting the data to the Newnode
    newnode->left=NULL;
    newnode->right=NULL;
    if(val<prev->data) //If the val is less than the prev node data then inserting the newnode in the left
    {
        prev->left=newnode;
    }
    else //Otherwise inserting the value in the right
    {
        prev->right=newnode;
    }
}
int search(Node *root,int val) //Creating the Function to Check whether the Number Occur in the Binary Search Tree or Not
{ //The Function will return 1 if the element is present and 0 if it is not
    while(root!=NULL) //Traversing the whole tree till we find its end
    {
        if(val==root->data) //Checking whether the root has the data we are finding for or not
        {
            return 1; //If the Element is Found
        }
        else if(val<root->data) //If Element is not found in the root node Changing the Root Node Accordingly 
        {
            root=root->left; //if the Number is Smaller than root value then checking the left sub tree
        }
        else
        {
            root=root->right; //if the Number is Greater than root value then checking the Right sub tree
        }
    }
    return 0; //If the whole tree is traverse and the element is not present then returning 0
}
int main()
{
    Node* root; //Declaring the root Node
    root=(Node*)malloc(sizeof(Node)); //Allocating the Memory to root
    root->left=NULL;
    root->right=NULL;
    int n,ele,find;
    printf("Enter The Number of Vertices :- "); //Taking the Number of Vertices in tree
    scanf("%d",&n);
    printf("Enter the Value of Root Node :- "); //Taking the Value of root Node
    scanf("%d",&root->data);
    for(int i=1 ; i<n ; i++)
    {
        printf("Enter the Value of Vertices :- "); //Taking the Rest of Remaining Root
        scanf("%d",&ele);
        createBST(root,ele);
    }
    printf("Enter The Number to Search :- "); //Taking the Number to find in the tree
    scanf("%d",&find);
    if(search(root,find)==1) //Passing in the function
    {
        printf("Number Found . "); //if the function return 1 then printing the message that Number is Present
    }
    else
    {
        printf("Number Not Found ."); //If the Function return 0 then printing that Number is Not Present
    }
}
