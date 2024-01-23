/*Author :- Aditya Yadav */
#include<stdio.h>
#include<stdlib.h> //Program to Implement a Basic Tree Non-Linear Data Structure
struct node{
    int data;
    struct node *left,*right;
};
typedef struct node Node;
Node* createNode(int val)
{
    Node* newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void preOrder(Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void postOrder(Node *root)
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
    int n;
    printf("Enter the Value of Root :- ");
    scanf("%d",&n);
    Node* root=createNode(n);
    Node* n1=createNode(4);
    Node* n2=createNode(10);
    Node* n3=createNode(2);
    Node* n4=createNode(3);
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n3->right=n4;
    printf("The Preorder Traversal is :- ");
    preOrder(root);
    printf("\n");
    printf("The Inorder Traversal is :- ");
    inOrder(root);
    printf("\n");
    printf("The Postorder Traversal is :- ");
    postOrder(root);
}