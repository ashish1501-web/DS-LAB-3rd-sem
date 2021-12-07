#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    
}

struct node* head;
head=NULL;

struct node* newNode;
void insertAThead(int x)
{   newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=head;
    head=newNode;
}

void insertATrear(int x)
{   newNode=(struct node*) malloc(sizeof(struct node));
    struct node* temp=head;
    newNode->data=x;
    newNode->next=NULL;
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

void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    
    
}
int main()
{
    insertATrear(1);
    insertATrear(2);
    insertATrear(3);
    insertAThead(4);
    insertAThead(5);
    insertAThead(6);
    return 0;
}
