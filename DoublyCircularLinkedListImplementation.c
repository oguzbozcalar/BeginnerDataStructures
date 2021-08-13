#include<stdio.h>
#include<stdlib.h>

struct node{
    
    int data;
    struct node *next;
    struct node *prev;
    
};

struct node *head=NULL;
struct node *tail;

void createDCLL (int x){
    struct node *newnode;
    
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    
    if(head==NULL)
    {
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    
    else{
        
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
        
    }
    
}


void display(){
    struct node *temp;
    temp=head;
    
    while(temp!=tail){
        printf("%d ",temp->data);
        temp=temp->next;
        
    }
   printf("%d",temp->data);
    
    
}



void insertAtBeg(int x){
    
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    
    if(head==NULL)
    {
    head=tail=newnode;
    newnode->prev=tail;
    newnode->next=head;
    }
    else
    {
   
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=tail;
    tail->next=newnode;
    head=newnode;
        
    }
    
    
}


void insertFromEnd(int x){
    
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    
       
    if(head==NULL)
    {
    head=tail=newnode;
    newnode->prev=tail;
    newnode->next=head;
    }
    
    else{
    
    newnode->prev=tail;
    tail->next=newnode;
    newnode->next=head;
    head->prev=newnode;
    tail=newnode;
    }
}

int getLength(){
    
    struct node *temp;
    temp=head;
    int count=0;
    while(temp->next!=head){
        count++;
        temp=temp->next;
        
    }
    count++;

return count;

}


void insertAtPos(int pos,int x){
    
    struct node *newnode,*temp,*temp2;
    temp=head;
    int i=1;
    
    if(pos==1)
        insertAtBeg(x);
    
    else if(pos==getLength())
        insertFromEnd(x);
        
        
    else
    {
    
    newnode=(struct node *)malloc(sizeof(struct node));
    
    newnode->data=x;
    
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    
  
    
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    
    }

}


void delFromBeg(){

    struct node *temp;
    temp=head;
    if(head->next==head){
        head=tail=NULL;
        free(temp);
    }
    
    else{
        
    head=head->next;
    head->prev=tail;
    tail->next=head;
    free(temp);
    
    }
}


void delFromEnd(){
    
    struct node *temp; 
    
    if(getLength()==1){
        delFromBeg();
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
        
        
    }
    
}


void delFromPos(int pos){
    
    struct node *temp;
    int i=1,l;
    temp=head;
    if(pos==1){
        delFromBeg();
    }
    
    else if(pos==getLength()){
        delFromEnd();
    }
    
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
    
    
    createDCLL(1);
    createDCLL(3);
    createDCLL(-1);
    display();
    printf ("\n***********************************\n");
    
    insertAtBeg(5);
    display();
    printf ("\n***********************************\n");
    
    insertFromEnd(12);
    display();
    printf ("\n***********************************\n");
    
    insertAtPos(3,-2);
    display();
    printf ("\n***********************************\n");
   
   delFromBeg();
    display();
    printf ("\n***********************************\n");
    
    delFromEnd();
    display();
    printf ("\n***********************************\n");
   
   delFromPos(1);
   display();
   printf ("\n***********************************\n");
   
  // delFromPos(2);
  // display();
  // printf ("\n***********************************\n");


   delFromPos(3);
   display();
   printf ("\n***********************************\n");
    
    
    
    
    return 0;
}
