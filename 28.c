
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
} 
struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);   
    return node;
}
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;

     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data);
}
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);  
     printInorder(node->right);
}

void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     printf("%d ", node->data);  

     printPreorder(node->left);  
 
     printPreorder(node->right);
}    
int main()
{
     struct node *root = NULL;
    char s[5];
    int n;
    printf("enter the key number\n");
    scanf("%d",&n);
    root=insert(root,n);
    do{
    printf("do you want to create another junction\n");
    scanf("%s",s);
    if(strcmp(s,"yes")==0){
    printf("enter the key number\n");
    scanf("%d",&n);
    root=insert(root,n);}
  }while(strcmp(s,"yes")==0);

     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
 
     getchar();
     return 0;
}
