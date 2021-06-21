#include<stdio.h>
#include<stdlib.h>

struct node
{

  int data;
  struct node *next;


};

int count;
struct node *temp;
struct node *head = NULL;

void add (int x)
{

  struct node *newnode;
  newnode = (struct node *) malloc (sizeof (struct node));
  newnode->next = NULL;
  newnode->data = x;
  if (head == NULL)
    {
      head = temp = newnode;
    }
  else
    {
      temp = head;
      while (temp->next != NULL)
    {
      temp = temp->next;

    }
      temp->next = newnode;
      newnode->next = NULL;
    }
}

void insertAtBeginning (int x)
{
  struct node *newnode;
  newnode = (struct node *) malloc (sizeof (struct node));
  newnode->data = x;
  newnode->next = head;
  head = newnode;


}

void insertAtEnd (int x)
{

  temp = head;
  struct node *newnode;
  newnode = (struct node *) malloc (sizeof (struct node));
  newnode->data = x;

  while (temp->next != NULL)
    {
      temp = temp->next;

    }
  temp->next = newnode;
  newnode->next = NULL;
}

void printdata ()
{
  
  temp = head;

  while (temp != NULL)
    {
      printf ("%d ", temp->data);
      temp = temp->next;
     
    }

}

int lengthOfLinkedList(){
    
    count = 0;
    temp = head;

  while (temp != NULL)
    {
      temp = temp->next;
      count++;
    }
    
    return count;
}

void insertAtSpesificPos (int x, int pos)
{
    int c=lengthOfLinkedList();
  if (pos == c + 1)
    insertAtEnd (x);
  else if (pos == 1)
    insertAtBeginning (x);
  else
    {
      temp = head;
      struct node *newnode;
      newnode = (struct node *) malloc (sizeof (struct node));
      newnode->data = x;
      pos -= 2;
      while (pos--)
    {
      temp = temp->next;
    }
      newnode->next = temp->next;
      temp->next = newnode;
    }

}

void delAtBegin(){
    
    temp=head;
    head=head->next;
    free(temp);
    
}


void delAtEnd(){
   
    int c=lengthOfLinkedList();
    if(c==1)
    {
        temp=head;
        free(temp);
        head=NULL;
    }
    else{
        
    temp=head;
    struct node *temp2;
    temp2=head;
    
    while(temp2->next->next!=NULL)
        temp2=temp2->next;
    
    while(temp->next!=NULL)
        temp=temp->next;
    
    
    temp2->next=NULL;
    free(temp);
    }
    
}

void delAtSpecPos(int pos){
    
    temp=head;
    int c=lengthOfLinkedList();
    
    if(c==pos){
        delAtEnd();
        
    }
    else if(pos==1){
        delAtBegin();
    }
    
    else
    {
        
    int i=1;
    struct node *nextnode;
    temp=head;
    
    
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    
    nextnode=temp->next;
   
    
    temp->next=nextnode->next;
    free(nextnode);
    
    }
    
}



int main ()
{


  add (1);
  add (2);
  add (3);
  printdata ();
  printf ("\n***********************************\n");
  insertAtBeginning (0);
  printdata ();
  printf ("\n***********************************\n");
  insertAtBeginning (-1);
  printdata ();
  printf ("\n***********************************\n");
  insertAtEnd (4);
  printdata ();
  printf ("\n***********************************\n");
  add (5);
  printdata ();
  printf ("\n***********************************\n");
  insertAtSpesificPos(9,2);
  printdata();
  printf ("\n***********************************\n");
  insertAtSpesificPos(6,6);
  printdata();
  printf ("\n***********************************\n");
  insertAtSpesificPos(9,9);
  printdata();
  printf ("\n***********************************\n");
  insertAtSpesificPos(-2,1);
  printdata();
  printf ("\n***********************************\n");
  delAtEnd();
  printdata();
  printf ("\n***********************************\n");
  delAtBegin();
  printdata();
  printf ("\n***********************************\n");
  delAtSpecPos(1);
  printdata();
  printf ("\n***********************************\n");
  delAtSpecPos(8);
  printdata();
  printf ("\n***********************************\n");
  delAtSpecPos(4);
  printdata();
  printf ("\n***********************************\n");
  delAtSpecPos(5);
  printdata();
  printf ("\n***********************************\n");




  return 0;
}

