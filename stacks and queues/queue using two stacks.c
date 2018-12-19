/*
Queue with two stacks. Implement a queue with two stacks
so that each queue operations takes a constant
amortized number of stack operations.
Hint: If you push elements onto a stack and then pop them all, they
appear in reverse order. If you repeat this process, they're now back in order.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head=NULL;
struct node *rev=NULL;//rev is the head of another stack
void enqueue(int data);
void push_rev(int data);
void dequeue();
void pop_rev();
void printList(struct node *n);
int main()
{
  enqueue(4);
  enqueue(5);
  enqueue(6);
  printList(head);
  printf("\n");

  dequeue();
  dequeue();
  printList(head);
}

void enqueue(int data){
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->data=data;
  newHead->next=head;
  head=newHead;
}

void push_rev(int data){
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->data=data;
  newHead->next=rev;
  rev=newHead;
}

void dequeue(){
  while(head!=NULL){
    struct node *temp=head;
    head=head->next;
    push_rev(temp->data);
    temp->next=NULL;
    free(temp);
  }
  pop_rev();
}
void pop_rev(){
  struct node *temp=rev;
  rev=rev->next;
  temp->next=NULL;
  free(temp);
  while(rev!=NULL){
    enqueue(rev->data);
    rev=rev->next;
  }
}

void printList(struct node *n){
  while (n != NULL)
  {
     printf("%d", n->data);
     n=n->next;
  }
}
