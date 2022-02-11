#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* newNode;

int count()
{   int len=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}

void insert_beg(int x)
{
    struct node* temp=head;
    newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->next=NULL;
    newNode->data=x;
    if(head==NULL)
    {
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}

void insert_end(int x)
{
    struct node* temp=head;
    newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->next=NULL;
    newNode->data=x;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void insert_pos(int pos,int x)
{   
    struct node* temp=head;
    newNode=(struct node*)malloc(sizeof(struct node*));
   
    newNode->data=x;
    if(pos==0)    
    {
        insert_beg(x);
    }
    else if(pos==count())
    {
        insert_end(x);
    }
    else{
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void display()
{
    struct node* temp=head;
    
    while(temp!=NULL)
    {   printf("%d->",temp->data);
         temp=temp->next;
    }
}

int main()
{
    int x,ch,pos;
     printf("\nEnter::\n1.insertATpos\n2.insert_beg\n3.insert_end\n4.display\n5.exit the program\n");
    while(1)
    {   printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element and position to insert in linked list:");
                scanf("%d %d",&x,&pos);
                insert_pos(pos,x);
                break;
            case 2:
                 printf("Enter element insert in linked list:");
                scanf("%d",&x);
                insert_beg(x);
                break;
            case 3:
                 printf("Enter element insert in linked list:");
                scanf("%d",&x);
                insert_end(x);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}
