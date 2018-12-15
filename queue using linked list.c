#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *first=NULL;
struct node *second=NULL;
struct node *last=NULL;
void enqueue(int data);
void dequeue();
void printList(struct node *n);
int main()
{
  first=(struct node*)malloc(sizeof(struct node));
  second=(struct node*)malloc(sizeof(struct node));
  last=(struct node*)malloc(sizeof(struct node));

  first->data = 1;
  first->next = second;

  second->data = 2;
  second->next = last;

  last->data = 3;
  last->next = NULL;

  enqueue(4);
  enqueue(5);
  enqueue(6);
  printList(first);
  printf("\n");

  dequeue();
  dequeue();
  printList(first);
}

void enqueue(int data){
  struct node *temp=last;
  struct node *newLast=NULL;
  newLast=(struct node*)malloc(sizeof(struct node));
  newLast->data=data;
  newLast->next=NULL;
  last=newLast;
  temp->next=last;
}

void dequeue(){
  if(first->next==NULL){
    printf("queue is empty");
  }else{
    struct node *temp=first;
    first=first->next;
    temp->next=NULL;
    free(temp);
  }
}


void printList(struct node *n){
  while (n != NULL)
  {
     printf("%d", n->data);
     n=n->next;
  }
}
