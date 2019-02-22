 #include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node* createNewNode(int);
void display(node* , int);
node* insertNewNode(node*);
node* deleteNode(node*);


//*********************************************************************

int main()
{
    int a,n,b;
    node* linkedList = NULL;
    node* newLinkedList = NULL;
    node* updatedLinkedList = NULL;
    printf("How many nodes you want to insert: ");
    scanf("%d",&n);
    linkedList = createNewNode(n);
    display(linkedList , n);
    printf("Do you want to insert a new node:\n* If yes press 1\n* If no press any key\n");
    scanf("%d",&a);
    if( a==1 )
    {
        n = n+1;
        newLinkedList = insertNewNode(linkedList);
        printf("The new linked list is:\n");
        display(newLinkedList , n);
        printf("Do you want to delete a node:\n* If yes press 1\n* If no press any key\n");
        scanf("%d",&b);
        if( b==1 )
        {
            n = n-1;
            updatedLinkedList = deleteNode(newLinkedList);
            printf("The updated linked list is:\n");
            display(updatedLinkedList , n);
        }
    }
    else{
        printf("Do you want to delete a node:\n* If yes press 1\n* If no press any key\n");
        scanf("%d",&b);
        if( b==1 )
        {
            n = n-1;
            updatedLinkedList = deleteNode(linkedList);
            printf("The updated linked list is:\n");
            display(updatedLinkedList , n);
        }
    }
    return 0;
}

//*********************************************************************

node* createNewNode(int n)
{
    int i;
    node*temp = NULL;
    node*head = NULL;
    node*temp1 = NULL;
    for( i=0 ; i<n ; i++ )
    {
        temp = (node*)malloc(sizeof(node));
        printf("Enter data to the node %d: ",i+1);
        scanf("%d",&temp->data);
        temp->prev = NULL;
        temp->next = NULL;
        
        if( head == NULL )
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
        }
        
        else
        {
            temp1 = head;
            while( temp1->next != head )
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
            temp->prev = temp1;
            temp->next = head;
            head->prev = temp;
        }
    }
    return head;
}

//*********************************************************************

void display(node* linkedList , int n)
{
    int i=0;
    for( i=0 ; i<=n ; i++ )
    {
        printf("%d \n",linkedList->data );
        linkedList = linkedList->next;
    }
}

//*********************************************************************

node* insertNewNode(node* linkedList)
{
    int b,m;
    int i=0 , j=0;
    node* temp = NULL;
    node* head = NULL;
    node* temp1 = NULL;
    node* tail = NULL;
    temp1 = linkedList;
    tail = linkedList;

    temp = (node*)malloc(sizeof(node));
    printf("Enter value to the new node: ");
    scanf("%d",&temp->data);
       
    printf("Where do you want to insert the new node:\n1. Beginning\n2. Inbetween\n");
    scanf("%d",&b);
    switch (b) {
        case 1:
            temp->next = linkedList;
            temp->prev = linkedList->prev;
            linkedList->prev->next = temp;
            linkedList->prev = temp;
            temp1 = temp;
            head = temp1;
            break;
        case 2:
            printf("After which node you want to insert the new node: ");
            scanf("%d",&m);
            while( linkedList->data != m )
            {
                linkedList = linkedList->next;
                i++;
            }
            while( tail->data != m )
            {
                tail = tail->prev;
                j++;
            }
            if(i<=j)
            {
                printf("Traversing forward\n");
                temp->next = linkedList->next;
                temp->prev = linkedList;
                linkedList->next = temp;
                linkedList->next->prev = temp;
                head = temp1;
            }
            else
            {
                printf("Traversing backward\n");
                temp->next = tail->next;
                temp->prev = tail;
                tail->next = temp;
                tail->next->prev = temp;
                head = temp1;
            }
            break;
        default:
            break;
}
    return head;
}

//*********************************************************************

node* deleteNode(node* linkedList)
{
    int b,m;
    int i=0 , j=0;
    node* head = NULL;
    node* temp1 = NULL;
    node* tail = NULL;
    temp1 = linkedList;
    tail = linkedList;
    
    printf("Where do you want to delete the node:\n1. Beginning\n2. Inbetween\n");
    scanf("%d",&b);
    switch (b) {
        case 1:
            linkedList->prev->next = linkedList->next;
            linkedList->next->prev = linkedList->prev;
            head = linkedList->next;
            linkedList->next = NULL;
            linkedList->prev = NULL;
            free(linkedList);
            break;
        case 2:
            printf("Which node do you want to delete: ");
            scanf("%d",&m);
            while( linkedList->data != m )
            {
                linkedList = linkedList->next;
                i++;
            }
            while( tail->data != m )
            {
                tail = tail->prev;
                j++;
            }
            if(i<=j)
            {
                printf("Traversing forward\n");
                linkedList->prev->next = linkedList->next;
                linkedList->next->prev = linkedList->prev;
                linkedList->next = NULL;
                linkedList->prev = NULL;
                free(linkedList);
                head = temp1;
            }
            else
            {
                printf("Traversing backward\n");
                tail->prev->next = tail->next;
                tail->next->prev = tail->prev;
                tail->next = NULL;
                tail->prev = NULL;
                free(tail);
                head = temp1;
            }
            break;
        default:
            break;
    }
    return head;
}









