#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;
//*********************************************************************
void createNewNode(int n,node *);

int main()
{
    int n;
    printf("How many nodes you want to insert: ");
    scanf("%d",&n);
    node * head = NULL;
    node * temp = (node *) malloc (sizeof(node));
    temp->data = 2;
    temp->next = NULL;
    head = temp;
    createNewNode(n,temp);
    
    return 0;
}
//**********************************************************************
void createNewNode(int n,node * temp)
{
    node * temp2 = (node *) malloc (sizeof(node));
    temp2=temp;
    int j=1;
    for(int i=0 ; i<n ; i++)
    {
        node * temp1 = (node *) malloc (sizeof(node));
        j++;
        printf("enter value of %d node: ",j);
        scanf("%d",&temp1->data);
        temp->next=temp1;
        temp1->next=NULL;
        temp=temp->next;
    }
    temp=temp2;
    while (temp!=NULL) {
        printf("%d \n",temp->data);
    
        temp=temp->next;
    }
   
}
