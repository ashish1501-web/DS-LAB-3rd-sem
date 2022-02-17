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
    struct node* left;
    struct node* right;
};

struct node* root=NULL;
void insert(int val)
{   struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    
    if(root==NULL)
    {
        root=newNode;
        root->left=NULL;
        root->right=NULL;
        
        return;
    }
    else
    {struct node* child=root;
    struct node* parent=NULL;
    
    while(child!=NULL)
    {   parent=child;
        if(val<child->data)
        {
            
            child=child->left;
        }
        
        else
        {
            child=child->right;
        }
        
    }
    
    if(val<parent->data)
    {
        parent->left=newNode;
        
    }
    else{
        parent->right=newNode;
    }}
}

void inorder(struct node* temp)
{
    if(temp==NULL)
    {  
        return;
    }
    inorder(temp->left);
    printf("%d\t",temp->data);
    inorder(temp->right);
}
void postorder(struct node* temp)
{
    if(temp==NULL)
    {   
        return;
    }
    postorder(temp->left);
   
    postorder(temp->right);
     printf("%d\t",temp->data);
}
void preorder(struct node* temp)
{
    if(temp==NULL)
    {   
        return;
    }
    printf("%d\t",temp->data);
    preorder(temp->left);
    
    preorder(temp->right);
}

int main()
{   
    int choice,val;
    while(1)
    {
        printf("\nEnter\n1.Insert element into BST\n2.Inorder Display\n3.Preorder Display\n4.Postorder Display\n5.exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {   
            case 1:
                printf("\nEnter the value:");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                 postorder(root);
                 break;
            case 5:
                exit(0);
        }
        
    } 
    
    
   

    return 0;
}

