#include<stdio.h>
#include<stdlib.h>

struct node{
    
  int data;
  struct node *next;
  struct node *prev;
    
};

struct node *head=NULL;
struct node *tail=NULL;

void createDLL(int x){
    
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    if(head==NULL){
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        
        
    }
    
    
}

void reverseDLL(){
    
    struct node *currentnode,*nextnode;
    currentnode=head;
    
    while(currentnode!=NULL){
        
        nextnode=currentnode->next;
        currentnode->next=currentnode->prev;
        currentnode->prev=nextnode;
        currentnode=nextnode;
        
    }
    
    currentnode=head;
    head=tail;
    tail=currentnode;
    
    
}

void display(){
    struct node *temp;
    temp=head;
    
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    
}



int main(){
    
    createDLL(3);
    createDLL(5);
    createDLL(7);
    
    display();
    printf ("\n***********************************\n");
    
    reverseDLL();
    display();
    printf ("\n***********************************\n");
    
    reverseDLL();
    display();
    printf ("\n***********************************\n");
    
    
    return 0;
}
