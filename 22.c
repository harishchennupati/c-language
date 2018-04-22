
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct node
{
    char data;
    struct node* next;
};
bool isPalindromeUtil(struct node **left, struct  node *right)
{
   if (right == NULL)
      return true;
   bool isp = isPalindromeUtil(left, right->next);
   if (isp == false)
      return false;
   bool isp1 = (right->data == (*left)->data);
   *left = (*left)->next;
 
   return isp1;
}
bool isPalindrome(struct node *head)
{
   isPalindromeUtil(&head, head);
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    
    struct node* head = NULL;
    int i;
    int n;
    int m;
    printf("enter n\n");
    scanf("%d",&n);
    for (i = 0;i<n; i++)
    { scanf("%d",&m);
       push(&head,m);
    }
if(isPalindromeUtil(&head,head))
printf("1\n");
else
printf("0");

    return 0;
}
