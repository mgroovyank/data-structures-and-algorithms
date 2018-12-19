/*
Dequeue. A double-ended queue or deque (pronounced “deck”) is a generalization of a stack and a queue that supports adding and removing items from either the front or the back of the data structure. Create a generic data type Deque that implements the following API:

public class Deque<Item> implements Iterable<Item> {
   public Deque()                           // construct an empty deque
   public boolean isEmpty()                 // is the deque empty?
   public int size()                        // return the number of items on the deque
   public void addFirst(Item item)          // add the item to the front
   public void addLast(Item item)           // add the item to the end
   public Item removeFirst()                // remove and return the item from the front
   public Item removeLast()                 // remove and return the item from the end
   public Iterator<Item> iterator()         // return an iterator over items in order from front to end
   public static void main(String[] args)   // unit testing (optional)
}
Corner cases.  Throw the specified exception for the following corner cases:

Throw a java.lang.IllegalArgumentException if the client calls either addFirst() or addLast() with a null argument.
Throw a java.util.NoSuchElementException if the client calls either removeFirst() or removeLast when the deque is empty.
Throw a java.util.NoSuchElementException if the client calls the next() method in the iterator when there are no more items to return.
Throw a java.lang.UnsupportedOperationException if the client calls the remove() method in the iterator.
Performance requirements.  Your deque implementation must support each deque operation (including construction) in constant worst-case time. A deque containing n items must use at most 48n + 192 bytes of memory and use space proportional to the number of items currently in the deque. Additionally, your iterator implementation must support each operation (including construction) in constant worst-case time.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  int type;//type=0 for int and 1 for double
};
struct node *first=NULL;
struct node *last=NULL;
void enqueue(int data);//addLast()
void dequeue();//removeFirst()
void addFirst(int data);
void removeLast();
void printList(struct node *n);
int main()
{
  addFirst(9);
  removeLast();
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
    printf("\ndequeue:decque is empty\n");
  }else{
    struct node *temp=first;
    first=first->next;
    temp->next=NULL;
    free(temp);
  }
}

void addFirst(int data){
  if(first==NULL && last==NULL){
    first=(struct node*)malloc(sizeof(struct node));
    first->data=data;
    first->next=NULL;
    last=first;
  }else{
    struct node *newFirst=NULL;
    newFirst=(struct node*)malloc(sizeof(struct node));
    newFirst->data=data;
    newFirst->next=first;
    first=newFirst;
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
    while(current!=NULL){
    if(current->next==last){
      lastPrev=current;
    }
    current=current->next;
    }
    last=lastPrev;
    last->next=NULL;
    free(current);
  }
}

void printList(struct node *n){
  while (n != NULL)
  {
     printf("%d", n->data);
     n=n->next;
  }
}
