/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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

void delete_beg()
{
    if(head==NULL)
    {
        printf("No element to delete:----");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        return;
    }
    struct node* temp=head;
    head=temp->next;
    free(temp);
    
}
void delete_end()
{
    if(head==NULL)
    {
        printf("No element to delete:----");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        return;
    }
    struct node* temp=head;
    struct node* ptr=head;
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
    
}

void delete_pos(int pos)
{   
    struct node* temp=head;
    struct node* ptr=head;
   
    if(pos==0)    
    {
        delete_beg();
    }
    else if(pos==count())
    {
        delete_end();
    }
    else{
        for(int i=0;i<pos;i++)
        {   ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        free(temp);
        
       
    }
}

void display()
{
    struct node* temp=head;
    
    while(temp->next!=NULL)
    {   printf("%d->",temp->data);
         temp=temp->next;
    }
    printf("%d",temp->data);
}

int main()
{
    int x,ch,pos;
     
    while(1)
    {   printf("\nEnter::\n1.insert_pos\n2.insert_beg\n3.insert_end\n4.delete_end\n5.delete_end\n6.delete_pos\n7.display\n8.exit the program\n");
        printf("\nEnter your choice:");
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
                delete_beg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("Enter pos to delete the item:");
                scanf("%d",&pos);
                delete_pos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
                break;
        }
    }
    return 0;
}
