#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
}node;

node* createNewNode(int);
void display(node*);
node* insertNewNode(node*);
node* deleteNode(node*);

//*********************************************************************

int main()
{
    int n;
    node* linkedList = NULL;
    node* newLinkedList = NULL;
    node* updatedLinkedList = NULL;
    printf("How many nodes do you want to insert: ");
    scanf("%d",&n);
    linkedList = createNewNode(n);
    display(linkedList);
    printf("out of display");
    newLinkedList = insertNewNode(linkedList);
    printf("The new linked list is: \n");
    if(newLinkedList == NULL)
    {
        printf("Nothing is inserted\n");
        updatedLinkedList = deleteNode(linkedList);
    }
    else
    {
        display(newLinkedList);
        updatedLinkedList = deleteNode(newLinkedList);
    }
    printf("The updated linked list is: \n");
    display(updatedLinkedList);
    return 0;
}

//*********************************************************************

node* createNewNode(int n)
{
    int i;
    node*head = NULL;
    node*tail = NULL;
    node*temp = NULL;
    node*temp1 = NULL;
    for( i = 0 ; i < n ; i++ )
    {
        temp = (node*)malloc(sizeof(node));
        printf("Enter the data to the node %d: ",i+1);
        scanf("%d",&temp->data);
        temp->prev = NULL;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            temp1 = head;
            while( temp1->next != NULL)
            {
                temp1 = temp1->next;
                if( temp->next == NULL)
                    tail = temp;
            }
            temp->prev = temp1;
            temp1->next = temp;
        }
    }
    

    return head;
}

//*********************************************************************

void display(node*linkedList)
{
    while(linkedList != NULL)
    {
        printf("%d\n",linkedList->data);
        linkedList = linkedList->next;
    }
}

//*********************************************************************

node* insertNewNode(node* linkedList)
{
    int a,b,n,x=0,y=0;
    node* temp1 = NULL;
    node* temp = NULL;
    node* head = NULL;
    node* tail = NULL;
    temp1 = linkedList;
    
    while( temp1->next != NULL)
    {
        temp1 = temp1->next;
        if( temp1->next == NULL)
            tail = temp1;
    }
    
    printf("The last node is %d \n",tail->data);
    
    printf("Do you want to insert any new node, \n* If yes press 1 \n* If no press any key\n");
    scanf("%d",&a);
    
    if(a==1)
    {
        temp = (node*)malloc(sizeof(node));
        printf("Enter value to the new node: ");
        scanf("%d",&temp->data);
        printf("Where do you want to insert the new node:\n1. Beginning \n2. Inbetween \n3. Ending\n");
        scanf("%d",&b);
        switch (b) {
            case 1:
                head = linkedList;
                temp->next = linkedList;
                linkedList->prev = temp;
                temp->prev = NULL;
                head = temp;
                break;
            case 2:
                temp1=linkedList;
                printf("After which node do you want to insert the new node: ");
                scanf("%d",&n);
//                printf("Do you want to traverse from head or tail, \n* If head press 1 \n* If tail press 2\n");
//                scanf("%d",&x);
//                if( x==1 )
//                {
                    while (linkedList->data != n)
                    {
                        linkedList = linkedList->next;
                        x++;
                    }
//                    temp->next = linkedList->next;
//                    linkedList->next->prev = temp;
//                    temp->prev = linkedList;
//                    linkedList->next = temp;
//                    head = temp1;
//                }
                
//                if( x==2 )
//                {
                    while(tail->data != n)
                    {
                        tail = tail->prev;
                        y++;
                    }
//                    temp->next = tail->next;
//                    tail->next->prev = temp;
//                    temp->prev = tail;
//                    tail->next = temp;
//                    head = temp1;
//                }
                if(x<=y)
                {
                    printf("Traversing from beginning \n");
                    temp->next = linkedList->next;
                    linkedList->next->prev = temp;
                    temp->prev = linkedList;
                    linkedList->next = temp;
                    head = temp1;
                }
                else
                {
                    printf("Traversing from end \n");
                    temp->next = tail->next;
                    tail->next->prev = temp;
                    temp->prev = tail;
                    tail->next = temp;
                    head = temp1;
                }
           
                break;
            case 3:
                tail->next = temp;
                temp->prev = tail;
                head=linkedList;
                break;
            default:
                break;
        }
    }
    return head;
}

//*********************************************************************

node* deleteNode(node*newLinkedList)
{
    int a,b,n,x=0,y=0;
    node* temp1 = NULL;
    node* temp = NULL;
    node* head = NULL;
    node* tail = NULL;
    temp1 = newLinkedList;
    
    while( temp1->next != NULL)
    {
        temp1 = temp1->next;
        if( temp1->next == NULL)
            tail = temp1;
    }
    
    printf("The last node is %d \n",tail->data);
    
    printf("Do you want to delete any  node, \n* If yes press 1 \n* If no press any key\n");
    scanf("%d",&a);
    
    if(a==1)
    {
        printf("From where do you want to delete the node:\n1. Beginning \n2. Inbetween \n3. Ending\n");
        scanf("%d",&b);
        switch (b) {
            case 1:
                temp = newLinkedList;
                newLinkedList->next->prev = NULL;
                head = newLinkedList->next;
                newLinkedList->next = NULL;
                free(temp);
                break;
            case 2:
                temp1=newLinkedList;
                printf("Which node do you want to delete: ");
                scanf("%d",&n);
            
                while (newLinkedList->data != n)
                {
                    newLinkedList = newLinkedList->next;
                    x++;
                }
                
                while(tail->data != n)
                {
                    tail = tail->prev;
                    y++;
                }
                
                if(x<=y)
                {
                    printf("Traversing from beginning \n");
                    newLinkedList->prev->next = newLinkedList->next;
                    newLinkedList->next->prev = newLinkedList->prev;
                    newLinkedList->prev = NULL;
                    newLinkedList->next = NULL;
                    free(newLinkedList);
                    head = temp1;
                }
                else
                {
                    printf("Traversing from end \n");
                    tail->prev->next = tail->next;
                    tail->next->prev = tail->prev;
                    tail->prev = NULL;
                    tail->next = NULL;
                    free(tail);
                    head = temp1;
                }
                
                break;
            case 3:
                tail->prev->next = NULL;
                tail->prev = NULL;
                free(tail);
                head = newLinkedList;
                break;
            default:
                break;
        }
    }
    return head;
}













