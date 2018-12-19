#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head=NULL;
void push(int data);
void pop();
void printList(struct node *n);
int main()
{

  struct node *second=NULL;
  struct node *third=NULL;

  head=(struct node*)malloc(sizeof(struct node));
  second=(struct node*)malloc(sizeof(struct node));
  third=(struct node*)malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  push(4);
  push(5);
  push(6);
  printList(head);
  printf("\n");

  pop();
  pop();
  printList(head);
}

void push(int data){
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->data=data;
  newHead->next=head;
  head=newHead;
}

void pop(){
  struct node *temp=head;
  head=head->next;
  temp->next=NULL;
  free(temp);
}


void printList(struct node *n){
  while (n != NULL)
  {
     printf("%d", n->data);
     n=n->next;
  }
}
