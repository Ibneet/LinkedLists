#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

//*********************************************************************

node * createNewNode(int);
node* insertNewNode(node*);
void deleteNode(node*);
void display(node*);

//*********************************************************************

int main()
{
    int n = 0;
    node * linkedList = NULL;
    node * updatedLinkedList = NULL;
    printf("How many node do you want to insert: ");
    scanf("%d" ,&n);
    linkedList = createNewNode(n);
    display(linkedList);
    updatedLinkedList = insertNewNode(linkedList);
    deleteNode(updatedLinkedList);
    return 0;
}

//*********************************************************************

node * createNewNode(int n)
{
    node * head = NULL;
    node * temp = NULL;
    node * temp1 = NULL;
    int j = 0;
    for(int i = 0 ; i < n ; i++)
    {
        temp = (node*)malloc(sizeof(node));
        printf("Enter the data to the node %d: ",++j);
        scanf("%d" ,&(temp->data));
        temp->next = NULL;
        
        if(head == NULL)
            head = temp;
        else
        {
            temp1=head;
            while(temp1->next != NULL)
                temp1 = temp1->next;
            temp1->next = temp;
        }
    }
    return head;
}

//*********************************************************************

void display(node*linkedList)
{
    while (linkedList != NULL)
    {
        printf("%d \n",linkedList->data);
        linkedList = linkedList->next;
    }
}

//*********************************************************************

node* insertNewNode(node*linkedList)
{
    int a,b,j;
    node*head = NULL;
    node*temp = NULL;
    node*temp1 = NULL;
    printf("Do you want to insert any new node,\nIf yes press 1 \nIf no press any key ");
    scanf("%d",&b);
    if(b==1)
    {
        temp = (node*)malloc(sizeof(node));
        printf("Enter value to new node: ");
        scanf("%d",&temp->data);
        printf("Where do you want to insert the new node:\n 1. Beginning\n 2. Inbetween\n 3. Ending \n");
        scanf("%d",&a);
        switch (a) {
            case 1:
                temp->next = linkedList;
                head = temp;
                display(head);
                break;
            case 2:
                printf("After which node do you want to insert: ");
                scanf("%d",&j);
                node*temp1=linkedList;
                while(linkedList->data != j)
                    linkedList = linkedList->next;
                temp->next=linkedList->next;
                linkedList->next = temp;
                head=temp1;
                display(head);
                break;
            case 3:
                temp1=linkedList;
                while(linkedList->next != NULL)
                    linkedList = linkedList->next;
                linkedList->next = temp;
                head=temp1;
                display(head);
                break;
                
            default:
                break;
    }
    }
    else
        exit(0);
    return head;
}

//*********************************************************************

void deleteNode(node* linkedList)
{
    int a,b,j;
    node*head = NULL;
    node*temp = NULL;
    node*temp1 = NULL;
    printf("Do you want to delete any new node,\nIf yes press 1 \nIf no press any key");
    scanf("%d",&b);
    if(b==1)
    {
        printf("From where do you want to delete the node:\n 1. Beginning\n 2. Inbetween\n 3. Ending \n");
        scanf("%d",&a);
        switch (a) {
            case 1:
                head = linkedList->next;
                linkedList->next = NULL;
                free(linkedList);
                display(head);
                break;
            case 2:
                printf("After which node do you want to delete: ");
                scanf("%d",&j);
                temp1=linkedList;
                while(linkedList->data != j)
                    linkedList = linkedList->next;
                linkedList->next = linkedList->next->next;
                temp = linkedList->next;
                free(temp);
                head=temp1;
                display(head);
                break;
            case 3:
                temp1=linkedList;
                while(linkedList->next->next != NULL)
                    linkedList = linkedList->next;
                free(linkedList->next->next);
                linkedList->next = NULL;
                head=temp1;
                display(head);
                break;
                
            default:
                break;
        }
    }
    else
        exit(0);
}




























