/*
Stack with max. Create a data structure that efficiently supports the stack operations (push and pop) and also a return-the-maximum operation. Assume the elements are real numbers so that you can compare them
Hint -Use two stacks, one to store all of the items and a second stack to store the maximums.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head=NULL;
struct node *max=NULL;
void push(int data);
void push_max(int data);
void pop();
void pop_max();
void printList(struct node *n);
int main()
{
  push(4);
  printf("The maximum value is %d\n",max->data);
  push(5);
  printf("The maximum value is %d\n",max->data);
  push(6);
  printf("The maximum value is %d\n",max->data);
  printList(head);
  printf("\n");

  pop();
  printf("The maximum value is %d\n",max->data);
  pop();
  printf("The maximum value is %d\n",max->data);
  printList(head);
}

void push(int data){
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->data=data;
  newHead->next=head;
  if(head==NULL && max==NULL){
    struct node *newMax=NULL;
    newMax=(struct node*)malloc(sizeof(struct node));
    max=newMax;
    max->data=newHead->data;
  }
  head=newHead;
  if(head->data>max->data){
    int max=head->data;
    push_max(max);
  }
}

void push_max(int data){
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->data=data;
  newHead->next=max;
  max=newHead;
}

void pop(){
  struct node *temp=head;
  head=head->next;
  if(temp->data==max->data){
    pop_max();
  }
  temp->next=NULL;
  free(temp);
}
void pop_max(){
  struct node *temp=max;
  max=max->next;
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
