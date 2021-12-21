#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insertAThead(int x)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
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
void insertATend(int x)
{struct node* newNode=(struct node* ) malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    struct node* temp=head;
    if(head==NULL)
    {
        head=newNode;
    }
    else{
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}


}


int len()
{
    int l=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

void insertATpos(int x,int pos)
{   struct node* temp=head;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    int l=len();
    if(pos==1)
    {
        insertAThead(x);
        return;
    }
    if(pos==l)
    {
        insertATend(x);
        return;
    }


    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteATend()
{
    struct node* temp=head,*pre=head;
    if(head==NULL)
    {
        printf("NO ELE:");
        return;
    }
    while(temp->next!=NULL)
    {   pre=temp;
        temp=temp->next;
    }
    pre->next=NULL;
    free(temp);
}

void deleteATbeg()
{
     struct node* temp=head,*pre=head;
    if(head==NULL)
    {
        printf("NO ELE:");
        return;
    }
    head=head->next;
    free(temp);
}

void deleteATpos(int pos)
{   struct node* ptr1=head,*ptr=head;
    if(pos==1)
    {
        deleteATbeg();
    }
    else if(pos==len())
    {
        deleteATend();
    }
    else{
        for(int i=1;i<pos;i++)
        {
            ptr1=ptr;
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("cant delete out of bounds:::::");
                return;
            }
            
        }
        ptr1->next=ptr->next;
        free(ptr);
        
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
}
int main()
{   int c,ch,x;
    printf("Enter\n 1.insert at pos \n 2>delete at pos:\n3.display\n4.exit");
    while(1)
    {
        printf("Enter ur choice:");
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
