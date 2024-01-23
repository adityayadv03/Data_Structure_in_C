/*Author :- Aditya Yadav */
#include<stdio.h>
#include<stdlib.h> //Program to Implement a Basic Tree Non-Linear Data Structure
struct node //Creating a basic node used in a tree
{
    int data; //To Store the integer data of node
    struct node *left,*right; //To store the child Node
};
typedef struct node Node; //Create a shortcut of struct node as Node
Node* createNode(int val) //A function to create a node with a given integer value
{
    Node* newnode; //created a new node
    newnode=(Node*)malloc(sizeof(Node)); //allocating the size using malloc
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode; //returning the created Node
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
    Node* root=createNode(5); //Creating the root node with value 5
    Node* n1=createNode(4); //Creating a node with value 4
    Node* n2=createNode(10); //Creating a node with value 10
    Node* n3=createNode(2); //Creating a node with value 2
    Node* n4=createNode(3); //Creating a node with value 3
    root->left=n1; //Connecting Node
    root->right=n2; //Connecting Node
    n1->left=n3; //Connecting Node
    n3->right=n4; //Connecting Node
    printf("The Preorder Traversal is :- "); //Printing the Preorder Traversal
    preOrder(root);
    printf("\n");
    printf("The Inorder Traversal is :- "); //Printing the Inorder Traversal
    inOrder(root);
    printf("\n");
    printf("The Postorder Traversal is :- "); //Printing the Postorder Traversal
    postOrder(root);
}