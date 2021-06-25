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


int getLengthOfCLL(){
    
    int count=0;
    struct node *temp;
    temp=tail->next;
    
    while(temp->next!=tail->next){
       count++;
        temp=temp->next;
    }
    count++;
    
    return count;
    
}


void insertAtBeg(int x){
    
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    
    else{
        
        
        newnode->next=tail->next;
        tail->next=newnode;
        
    }
    
}


void insertFromEnd(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    
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


void insertAtPos(int pos,int x){
    
    int i=1;
    struct node *temp;
    temp=tail->next;
    
    if(pos==1)
        insertAtBeg(x);
   
    else if(pos==getLengthOfCLL())
        insertFromEnd(x);
   
    else{
        
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    
    while(i<pos-1){
        
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
        
        
    }
    
    
    
}



void delFromBeg(){
    
    
    
    struct node *temp;
    temp=tail->next;
    
    if(temp->next==temp){
        tail=NULL;
        free(temp);
    }
    else{
        tail->next=temp->next;
        free(temp);
        
    }
}

void delFromEnd(){
    
    struct node *temp,*temp2;
    
    temp=tail->next;
    if(temp->next==temp){
        tail=NULL;
        free(temp);
    }
    
    else{
    
    while(temp->next!=tail){
        temp=temp->next;
    }
    
    temp2=temp->next;
    temp->next=tail->next;
    tail=temp;
    free(temp2);
        
    }
}


void delFromGivenPos(int pos){
    
    struct node *temp,*temp2;
    int i=1;
    
    
    if(pos==1)
        delFromBeg();
    
    else if(pos==getLengthOfCLL()){
        delFromEnd();
    }
    
    else{
        
        temp=tail->next;
        
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    
    temp2=temp->next;
    
    temp->next=temp2->next;
    
    free(temp2);
    
    }
}




int main(){
    
    
    createCLL(1);
    createCLL(2);
    createCLL(3);
    displayCLL();
    printf ("\n***********************************\n");
    
    insertAtBeg(0);
    displayCLL();
    printf ("\n***********************************\n");
    
    insertFromEnd(4);
    displayCLL();
    printf ("\n***********************************\n");
    
    insertAtPos(3,1);
    displayCLL();
    printf ("\n***********************************\n");
    
    delFromBeg();
    displayCLL();
    printf ("\n***********************************\n");
    
    delFromEnd();
    displayCLL();
    printf ("\n***********************************\n");
    
    delFromGivenPos(2);
    displayCLL();
    printf ("\n***********************************\n");
    
    
    
    
    
    
    return 0;
}

