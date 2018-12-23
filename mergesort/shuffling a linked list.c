/*
Problem - Shuffling a linked list.
* Given a singly-linked list containing nn items, rearrange the items uniformly at random. Your algorithm should consume a logarithmic (or constant) amount of extra memory and run in time proportional to n \log nnlogn in the worst case.

Solution -
Prerequisite - mergesort a linked list
*associate a random number with each node
*sort the linked list according to these random values
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
  int data;
  int rand;//rand represents random data associated with each node
  struct node *next;
};
void push(struct node **head,int data);
void printList(struct node *n);
void split(struct node *source,struct node **f,struct node **b);
struct node* merge(struct node *f,struct node *b);
void mergesort(struct node **head);
int main(){
  srand(time(0));
  struct node *head=NULL;
  push(&head,1);
  push(&head,4);
  push(&head,9);
  push(&head,7);
  push(&head,0);
  printList(head);
  mergesort(&head);
  printf("\nshuffled linked list is:\n");
  printList(head);
}
void push(struct node **headRef,int data){
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->data=data;
  newHead->next=*headRef;
  newHead->rand=rand();
  *headRef=newHead;
}
void printList(struct node *n){
  while(n!=NULL){
    printf(" %d ",n->data);
    n=n->next;
  }
}

void mergesort(struct node **head){
  struct node *f;
  struct node *b;
  struct node* headRef = *head;
  if((headRef == NULL) || (headRef->next == NULL)){
    return;
    }
  split(headRef,&f,&b);
  mergesort(&f);
  mergesort(&b);
  *head=merge(f,b);
}
struct node* merge(struct node *f,struct node *b){
  struct node *result=NULL;
  if(f==NULL){
    return(b);
  }else if(b==NULL){
    return(f);
  }
  if(f->rand>=b->rand){//sort according to random values and not data
    result=b;
    result->next=merge(f,b->next);
  }else{
    result=f;
    result->next=merge(f->next,b);
  }
  return result;
}


void split(struct node *source,struct node **f,struct node **b){
  struct node *slow;
  struct node *fast;
  slow=source;
  fast=source->next;
  while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
      slow=slow->next;
      fast=fast->next;
    }
  }
  *f=source;
  *b=slow->next;
  slow->next=NULL;
}



