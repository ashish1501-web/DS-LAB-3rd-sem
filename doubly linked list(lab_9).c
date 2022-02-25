#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node*prev;
};
struct node* head=NULL;


struct node* newNode;



void insertATrear(int x)
{   newNode=(struct node*) malloc(sizeof(struct node));
    struct node* temp=head;
    newNode->data=x;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        newNode->prev=NULL;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
    
}

void insertATleft_pos(int key,int val)
{   newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=val;
    struct node* temp=head,*ptr;
    while(temp!=NULL)
    {  
        if(temp->data==key)
        {
            break;
        }
         ptr=temp;
        temp=temp->next;
    }
    if(temp!=NULL)
    {   newNode->prev=ptr;
        newNode->next=temp;
        ptr->next=newNode;
        temp->prev=newNode;
    }
    else{
        printf("No key found");
    }
}

void delete_by_value(int key)
{
    struct node* temp=head,*ptr=head;
    if(head->data==key)
    {   head=head->next;
        free(temp);
        return;
    }
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            break;
        }
        ptr=temp;
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        ptr->next=NULL;
        free(temp);
        
    }
    else{
        ptr->next=temp->next;
        temp->next->prev=ptr;
        free(temp);
    }
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
{
    
    insertATrear(10);
    insertATrear(30);
    insertATrear(70);
    insertATrear(20);
    display();
    insertATleft_pos(30,99);
    display();
    delete_by_value(20);
    display();
//   int c,ch,x;
//     printf("Enter\n 1.insert at pos \n 2.delete at pos:\n3.display\n4.insert At left position of key.\n5.exit\n");
//     while(1)
//     {
//         printf("Enter ur choice:");
//         scanf("%d",&ch);
//         switch(ch)
//         {
//             case 1:
//                 printf("Enter data:");
//                 scanf("%d %d",&x);
//                 insertATrear(x);
//                 break;
                
//             case 2:
//                 printf("Enter pos:");
//                 scanf("%d",&c);
//                 deleteATpos(c);
//                 break;
//             case 3:
//                 display();
//                 break;
//             case 4:
//                 exit(0);
                
//         }
//     }

    return 0;
}


