#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node Node;
void createBST(Node* root,int val)
{
    Node* prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(root->data==val)
        {
            return;
        }
        else if(val<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    Node* newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if(val<prev->data)
    {
        prev->left=newnode;
    }
    else
    {
        prev->right=newnode;
    }
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
    Node* root;
    root=(Node*)malloc(sizeof(Node));
    root->left=NULL;
    root->right=NULL;
    int n,ele;
    printf("Enter The Number of Vertices :- ");
    scanf("%d",&n);
    printf("Enter the Value of Root Node :- ");
    scanf("%d",&root->data);
    for(int i=1 ; i<n ; i++)
    {
        printf("Enter the Value of Vertices :- ");
        scanf("%d",&ele);
        createBST(root,ele);
    }
    printf("The Preorder Traversal :- ");
    preOrder(root);
    printf("\n");
    printf("The Inorder Traversal :- ");
    inOrder(root);
    printf("\n");
    printf("The Postorder Traversal :- ");
    postOrder(root);
    printf("\n");
}