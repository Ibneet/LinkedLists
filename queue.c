#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

void createQueues(int,int);
void display(node*);
void deleteNode(node*);

//*********************************************************************

int main()
{
    int q,n;
    node * head = NULL;
    printf("How many queues you want to make: ");
    scanf("%d",&q);
    printf("How many nodes you want to insert: ");
    scanf("%d",&n);
    createQueues(n,q);
    return 0;
}

//*********************************************************************

void createQueues(int n,int q)
{
    int x,b,c;
    node* index[q];
    node * temp = NULL;
    node * temp1 = NULL;
    node * rear = NULL;
    node * newNode = NULL;
    for(int j = 0 ; j < q ; j++)
    {
        node * head = NULL;
        printf("This is queue number %d \n",j+1);
        for(int i = 0 ; i < n ; i++)
        {
            temp = (node*)malloc(sizeof(node));
            printf("Enter the data to the node %d: ",i+1);
            scanf("%d" ,&(temp->data));
            temp->next = NULL;
            
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                temp1=head;
                while(temp1->next != NULL)
                    temp1 = temp1->next;
                temp1->next = temp;
            }
        }
        index[j] = head;
    }
    for( int i = 0 ; i < q ; i++ )
    {
        printf("This is queue %d\n",i+1);
        display(index[i]);
    }
    printf("Do you want to get into the queue:\nPress 1 if yes and press any other key if not.\n");
    scanf("%d",&b);
    
    if(b==1)
    {
        newNode = (node*)malloc(sizeof(node));
        printf("Enter the data to the new node: ");
        scanf("%d" ,&(newNode->data));
        newNode->next = NULL;
        printf("In which queue you want to go: ");
        scanf("%d",&x);
        temp1 = index[x-1];
    
        while( temp1->next != NULL)
        {
            temp1 = temp1->next;
            if( temp1->next == NULL)
                rear = temp1;
        }
        rear->next = newNode;
    
        printf("This is the updated queue\n");
        display(index[x-1]);
    }
    else
        printf("No new member is coming");
    printf("Do you want to take a number from the queue:\nPress 1 if yes and press any other number if not.\n");
    scanf("%d",&c);
    if(c==1)
    {
        printf("From which queue do you want to get the number: ");
        scanf("%d",&x);
        deleteNode(index[x-1]);
    }
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

void deleteNode(node* linkedList)
{
    node * head = NULL;
    
    head = linkedList->next;
    linkedList->next = NULL;
    free(linkedList);
    
    printf("This is the updated queue\n");
    display(head);
}


