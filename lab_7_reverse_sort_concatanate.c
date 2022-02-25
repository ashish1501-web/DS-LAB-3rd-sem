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
//struct node* head=NULL;
struct node* newNode;
void insert(struct node* *head,int val)
{   newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->data=val;
    newNode->next=NULL;
    
    if((*head)==NULL)
    {
        (*head)=newNode;
        return;
    }
    struct node* temp=(*head);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    
    
}

struct node* reverse(struct node* head)
{
    struct node* curr=head,*prev=NULL,*next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

struct node*concatanation(struct node* h1,struct node* h2)
{
    struct node*temp=(h1);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=h2;
    return h1;
}

struct node* sort(struct node* head)
{
    struct node* temp1=(head),*temp2=(head);
    while(temp1!=NULL)
    {   temp2=head;
        while(temp2!=NULL)
        {   if(temp1->data<temp2->data)
            {
            int a=temp2->data;
            temp2->data=temp1->data;
            temp1->data=a;
            }
        temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return head;
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {   printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}

int main()
 {   struct node* head1=NULL;
     struct node* head2=NULL;
//     insert(&head1,10);
//     insert(&head1,30);
//     insert(&head1,20);
//     insert(&head2,40);
//     insert(&head2,50);
//     insert(&head2,60);
//     display(head1);
//     display(head2);
//     //head1=reverse(head1);
//     head1=sort(head1);
//     display(head1);
    
    // head1=concatanation(head1,head2);
    // display(head1);
    // head2=reverse(head2);
    
    // display(head2);
    int val,ch,x;
    printf("Enter.\n1.insert into linked list\n2.reverse the linked list\n3.concatanationof two linked lists\n4.sort the linked list\n5.display\n6.Exit");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter 1.Insert in first linked list\n2.Insert in second linked list\n");
                scanf("%d",&x);
                printf("Enter the element:");
                scanf("%d",&val);
                if(x==1)
                {
                    insert(&head1,val);
                }
                else if(x==2)
                {
                    insert(&head2,val);
                    
                }
                break;
                
            case 2:
                printf("Enter 1.reverse the first linked list\n2.reverse the second linked list\n");
                scanf("%d",&x);
                if(x==1)
                {
                    head1=reverse(head1);
                }
                else if(x==2)
                {
                    head2=reverse(head2);
                    
                }
                break;
            case 3:
                printf("Two lists are concatanated:");
                head1=concatanation(head1,head2);
                display(head1);
                break;
            case 4:
                 printf("Enter 1.sort the first linked list\n2.sort the second linked list\n");
                scanf("%d",&x);
                if(x==1)
                {
                    head1=sort(head1);
                }
                else if(x==2)
                {
                    head2=sort(head2);
                    
                }
                break;
            case 5:
                 printf("Enter 1.display the first linked list\n2.display the second linked list\n");
                scanf("%d",&x);
                if(x==1)
                {display(head1);
                }
                else if(x==2)
                {
                    display(head2);
                    
                }
                break;
            case 6:
                exit(0);
                break;
                
        }
    }

    return 0;
}


