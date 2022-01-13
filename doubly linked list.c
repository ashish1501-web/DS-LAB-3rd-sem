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

int length()
{
    int len=0;
    struct node* temp=head;
    while(temp!=NULL)
    {   len++;
        temp=temp->next;
    }
    return len;
}
void insertAThead(int x)
{   newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=head;
    newNode->prev=NULL;
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
void insertATpos(int x,int pos)
{   struct node* temp=head;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    int l=length();
    if(pos==1)
    {
        insertAThead(x);
        return;
    }
    if(pos==l+1)
    {
        insertATrear(x);
        return;
    }


    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next->prev=newNode;
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
}

void deleteAThead()
{   struct node* temp=head;
    if(head==NULL)
    {
        printf("No element is present to delete");
        return;
    }
    head->next->prev=NULL;
    head=head->next;
    free(temp);
}

void deleteATend()
{
    struct node* temp=head;
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
        
        temp=temp->next;
    }
    temp->prev->next=NULL;
    
    free(temp);
   

}

void deleteATpos(int pos)
{   struct node* ptr=head;
    int len=length();
    printf("\n%d\n",len);
    if(pos==1)
    {
        deleteAThead();
        return;
    }
    if(pos==len)
    {
        deleteATend();
        return;
    }
    for(int i=1;i<pos;i++)
    {  
        ptr=ptr->next;
        
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(ptr);
}

void display()
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        printf("%d<=>",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
    
    
}

int main()

{   int c,ch,x;
    printf("Enter\n 1.insert at pos \n 2.delete at pos:\n3.display\n4.exit");
    while(1)
    {
        printf("\nEnter ur choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter data and pos:");
                scanf("%d %d",&x,&c);
                
                insertATpos(x,c);
                break;
            case 2:
                printf("Enter pos:");
                scanf("%d",&c);
                
                deleteATpos(c);
                break;
                
                
            case 3:
                display();
                break;
            case 4:
                exit(0);
                
        }
    }


    return 0;
    
}

