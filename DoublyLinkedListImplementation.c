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


void insertAtBeg(int x){
    
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    
    
}


void insertAtEnd(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    
    newnode->prev=tail;
  
    tail->next=newnode;
    tail=newnode;
    
    
}

void insertAtPos(int pos,int x){
    
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    temp=head;
    int i=1;
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(pos==1)
       insertAtBeg(x);
       
    else{
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    
    }
    
}


void display(){
    struct node *temp;
    temp=head;
    
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    
}

int lengthOfDLL(){
    struct node *temp;
    temp=head;
    int count=0;
    
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    
    return count;
}

void delAtBeg(){
    struct node *temp;
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    
}

void delFromEnd(){
    
    struct node *temp;
    temp=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(temp);
    
}

void delFromPos(int pos){
    
    int i=1;
    struct node *temp;
    temp=head;
    
    if(pos==1)
        delAtBeg();
    else if(pos==lengthOfDLL())
        delFromEnd();
    
    else{
    
    while(i<pos){
        temp=temp->next;
        i++;
    }
    
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    }
}


int main(){
    
    createDLL(1);
    createDLL(2);
    createDLL(3);
    
    display();
    printf ("\n***********************************\n");
    insertAtBeg(0);
    display();
    printf ("\n***********************************\n");
    
    insertAtEnd(4);
    display();
    printf ("\n***********************************\n");
    
    insertAtPos(3,1);
    display();
    printf ("\n***********************************\n");
    
    delAtBeg();
    display();
    printf ("\n***********************************\n");
    
    delFromEnd();
    display();
    printf ("\n***********************************\n");
    
    delFromPos(3);
    display();
    printf ("\n***********************************\n");
    
    delFromPos(1);
    display();
    printf ("\n***********************************\n");
    
    delFromPos(2);
    display();
    printf ("\n***********************************\n");
    
    
    
    
    return 0;
}

