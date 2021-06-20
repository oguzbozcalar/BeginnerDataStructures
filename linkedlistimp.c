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
  count = 0;
  temp = head;

  while (temp != NULL)
    {
      printf ("%d ", temp->data);
      temp = temp->next;
      count++;
    }


}

void insertAtSpesificPos (int x, int pos)
{
  if (pos == count + 1)
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



int main ()
{


  add (5);
  add (6);
  add (7);
  printdata ();
  printf ("\n***********************************\n");
  insertAtBeginning (4);
  printdata ();
  printf ("\n***********************************\n");
  insertAtBeginning (3);
  printdata ();
  printf ("\n***********************************\n");
  insertAtEnd (8);
  printdata ();
  printf ("\n***********************************\n");
  add (9);
  printdata ();
  printf ("\n***********************************\n");
  insertAtSpesificPos (1, 3);
  printdata ();
  printf ("\n***********************************\n");
  insertAtSpesificPos (4, 7);
  printdata ();
  printf ("Legth:%d", count);
  printf ("\n***********************************\n");
  insertAtSpesificPos (10, 10);
  printdata ();
  printf ("\n***********************************\n");
  insertAtSpesificPos (11, 1);
  printdata ();




  return 0;
}
