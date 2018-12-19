#include<stdio.h>
#include<stdlib.h>
struct node
{
  void *data;
  struct node *next;
  int type;
};
struct node *head=NULL;
void push(void *data,int data_size,int type);
void pop();
void printList(struct node *n);
int main()
{
  int arr[]={1,2,3,4},i,type;
  for(i=3;i>=0;i--){
    push(&arr[i],sizeof(int),0);
  }
  float arr1[]={1.2,2.3,3.7};
  for(i=2;i>=0;i--){
    push(&arr1[i],sizeof(float),1);
  }
  printList(head);
  printf("\n");
  pop();
  printList(head);
}

void push(void *data,int data_size,int type){
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->data=malloc(data_size);
  newHead->type=type;
  int i;
  for(i=0;i<data_size;i++){
    *(char *)(newHead->data+i)=*(char *)(data+i);
  }
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
     if(n->type==0){
       printf(" %d ",*(int *)(n->data));
     }
     if(n->type==1){
       printf(" %f ",*(float *)(n->data));
     }
     n=n->next;
  }
}
