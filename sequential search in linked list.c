#include<stdio.h>
#include<stdlib.h>
struct node
{
  char key;
  int value;
  struct node *next;
};
struct node *head=NULL;
void insert(char key);
void search(int value);
void printList(struct node *n);

int main()
{
  insert('S');
  insert('E');
  insert('A');
  insert('R');
  insert('C');
  insert('H');
  insert('E');
  search(2);
  printList(head);
}

void insert(char key){
  struct node *iterator=head;
  while(iterator!=NULL){
    if(iterator->key==key){
      iterator->value=iterator->value+1;
      return;
    }
    iterator=iterator->next;
  }
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->key=key;
  newHead->value=1;
  newHead->next=head;
  head=newHead;
}

void search(int value){
  struct node *iterator=head;
  while(iterator!=NULL){
    if(iterator->value==value){
      printf("\nthe found value %d has key %c\n",iterator->value,iterator->key);
      return;
    }
    iterator=iterator->next;
  }
  printf("\nThe value is not present\n");
}

void printList(struct node *n){
  while (n != NULL)
  {
     printf(" %c : %d ", n->key,n->value);
     n=n->next;
  }
}
