#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
  int data;
  struct node *next;
};
struct node *first=NULL;
struct node *last=NULL;
void enqueue(int data);//addLast()
void removeFirst();
void removeLast();
void dequeue();
int length=0;
int main()
{
  enqueue(4);
  enqueue(5);
  enqueue(6);
  int k;
  for(k=0;k<2;k++){//assuming k=2
    dequeue();
  }
}

void enqueue(int data){
  struct node *newLast=NULL;
  newLast=(struct node*)malloc(sizeof(struct node));
  newLast->data=data;
  newLast->next=NULL;
  if(first==NULL){
    last=newLast;
    first=last;
  }else{
    last->next=newLast;
    last=newLast;
  }
  length++;
}

void removeFirst(){
  if(first->next==NULL){
    printf("\ndequeue:decque is empty\n");
  }else{
    struct node *temp=first;
    first=first->next;
    printf("\nkth value:%d\n",temp->data);
    temp->next=NULL;
    free(temp);
  }
}

void removeLast(){
  if(first==NULL && last==NULL){
    printf("\nremoveLast:The decque is empty\n");
  }else if(first->next==NULL){
    free(first);
  }else{
    struct node *current=NULL;
    struct node *lastPrev=NULL;
    current=first;
    while(current->next!=NULL){
    if(current->next==last){
      lastPrev=current;
    }
    current=current->next;
    }
    printf("\nkth value:%d\n",current->data);
    last=lastPrev;
    last->next=NULL;
    free(current);
  }
}

void dequeue(){
   if(first==NULL){
    printf("\nThe randomized queue is empty.\n");
  }else{
    srand(time(0));
    int randInt=(rand()%(length))+1;
    if(randInt==1){
      removeFirst();
    }else if(randInt==length){
      printf("abcd");
      removeLast();
    }else{
      int i=1;
      struct node *current=NULL;
      struct node *prev=NULL;
      current=first;
      while(i<randInt){
      if(i=randInt-1){
      prev=current;
      }
      current=current->next;
      i++;
    }
    printf("\nkth value:%d\n",current->data);
    prev->next=current->next;
    current->next=NULL;
    free(current);
    }
    length--;
  }
}
