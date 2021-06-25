#include<stdio.h>
#include<stdlib.h>

struct node{
    
    int data;
    struct node* next;
    
};
struct node *tail=NULL;


void createCLL(int x){

struct node *newnode;


newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=NULL;

if(tail==NULL){
    tail=newnode;
    tail->next=newnode;
}
    
else{
    
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
    
}
    
}


void displayCLL(){
    
    struct node *temp;
    temp=tail->next;
    
    while(temp->next!=tail->next){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    
}



void reverseOfCLL(){
    
    struct node *prev,*current,*nextnode;
    
    current=tail->next;
    nextnode=current->next;
    
    while(current!=tail){
        
        prev=current;
        current=nextnode;
        nextnode=current->next;
        current->next=prev;
        
    }
    
    nextnode->next=tail;
    tail=nextnode;
    
    
}


int main(){
    
    createCLL(1);
    createCLL(2);
    createCLL(3);
    displayCLL();
    printf ("\n***********************************\n");
    reverseOfCLL();
    displayCLL();
    printf ("\n***********************************\n");
    
    
    
    
    
    
    
    
    
    
    return 0;
}