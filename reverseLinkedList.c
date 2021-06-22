#include<stdio.h>
#include<stdlib.h>

struct node
{

  int data;
  struct node *next;


};
struct node *head;
struct node *temp;


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

void reverse(){
    struct node *prevnode,*currentnode,*nextnode;
    prevnode=NULL;
    currentnode=nextnode=head;
    
    while(nextnode!=NULL){
        
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    
        
    }
    head=prevnode;
    
    
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


int main(){
    
    
    add(1);
    add(2);
    add(3);
    printdata();
    printf ("\n***********************************\n");
    reverse();
    printdata();
    printf ("\n***********************************\n");
    reverse();
    printdata();
    printf ("\n***********************************\n");
    
    
    
    
    
    
    
    return 0;
}


