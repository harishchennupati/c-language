
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void print(struct Node* root)
{
    while(root!=NULL)
    {
        printf("%d ",root->data);
        root=root->next;
    }
}
int frequency = 0;
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int count(struct Node* head, int key)
{
    if (head == NULL)
        return frequency;
    if (head->data == key)
        frequency++;
    count(head->next, key);
}
int main()
{  int n;
printf("enter the size of the list\n");
scanf("%d",&n);
    struct Node* head = NULL;
    int k,key;
    for(int i=1;i<=n;++i){
        scanf("%d",&k);
    push(&head,k);
    }
    printf("printing the list:\n");
    print(head);
    printf("enter the key to find its occurence\n");
    scanf("%d",&key);
    count(head,key);
    printf("%d occured %d times",key,frequency);
    return 0;
}
