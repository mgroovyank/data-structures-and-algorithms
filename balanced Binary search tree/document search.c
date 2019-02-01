/*
    Document search. 
    
    Design an algorithm that takes a sequence of nn document words and a sequence of mm query words 
	and find the shortest interval in which the mm query words appear in the document in the order given.
	The length of an interval is the number of words in that interval.
	
	or 
	
	 How to find the minimum window that contains all the search keywords?
	
	Hint: for each word, maintain a sorted list of the indices in the document in which that word appears. 
	Scan through the sorted lists of the query words in a judicious manner.
	
	@author mgroovyank(MAYANK CHHIPA)
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  char data;
  struct node *next;
};
struct node *first=NULL;
struct node *last=NULL;
void enqueue(char data);
void dequeue();
void printList(struct node *n);
int main()
{
  char arr[]={'C','x','A','x','B','x','x','A','x','C','x','B','A','x','x','C'};
  int i,len=0;
  struct node *j;
  for(i=0;i<16;i++){
    if(arr[i]!='x'){
      enqueue(arr[i]);
      len++;
    }
    j=first->next;
    while(j!=NULL){
      if(j->data==first->data && i>1){
        dequeue();
        len--;
        break;
      }else{
        j=j->next;
      }
    }
  }
  printf("%d",len);
}

void enqueue(char data){
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
     printf("%c", n->data);
     n=n->next;
  }
}
