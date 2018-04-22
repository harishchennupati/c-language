
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
} 
struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
    return node;
}
bool search(struct node *root,int key)
{
    if(root==NULL)
    return false;
    if(root->key==key)
    return true;
    if(key>root->key)
    return search(root->right,key);
    else
    return search(root->left,key);
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
  printf("enter the key to be searched\n");
  int key;
  scanf("%d",&key);
  if(search(root,key))
  printf("found\n");
  else
  printf("not found");
    return 0;
}
