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
void preOrder(Node *root) //Recursive Function to print the preorder traversal
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root) //Recursive Function to print the Inorder traversal
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void postOrder(Node *root) //Recursive Function to print the postorder traversal
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    Node* root; //Declaring the root Node
    root=(Node*)malloc(sizeof(Node)); //Allocating the Memory to root
    root->left=NULL;
    root->right=NULL;
    int n,ele;
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
    printf("The Preorder Traversal :- "); //Printing the Preorder Traversal
    preOrder(root);
    printf("\n");
    printf("The Inorder Traversal :- "); //Printing the Inorder Traversal
    inOrder(root);
    printf("\n");
    printf("The Postorder Traversal :- "); //Printing the Postorder Traversal
    postOrder(root);
    printf("\n");
}
