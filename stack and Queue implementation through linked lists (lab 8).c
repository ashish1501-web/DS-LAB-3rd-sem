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

void insertAThead(int x)
{   newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=head;
    head=newNode;
}


void deleteATend()
{
    struct node* temp=head,*prev=head;
    if(head==NULL)
    {
        printf("No element is present to delete");
        return;
    }
    else if(head->next==NULL)
    {   head=NULL;
        free(temp);
    }
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;

}

void deleteAThead()
{   struct node* temp=head;
    if(head==NULL)
    {
        printf("No element is present to delete");
        return;
    }
    head=head->next;
    free(temp);
}
void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
    
}

int main()
{   int val,ch;
    
    while(1)
    {  printf("Enter\n 1.push into stack\n 2.pop from stack\n 3.display\n 4.enqueue\n 5.dequeue\n 6.display queue elements \n 7.exit");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
    {   case 1:
         {   printf("enter the value:");
            scanf("%d",&val);
            insertAThead(val);
            break;}
          case 2:
            
            
           deleteAThead();
            break;
        case 3:
            display();
            break;
        case 4:
         {   printf("enter the value:");
            scanf("%d",&val);
            insertAThead(val);
            break;}
          case 5:
            
            
           deleteATend();
            break;
        case 6:
            display();
            break;
        case 7:
           exit(0);
        
    }
    }
    
}

