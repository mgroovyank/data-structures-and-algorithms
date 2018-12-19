/*
Randomized queue. A randomized queue is similar to a stack or queue, except that the item removed is chosen uniformly at random from items in the data structure. Create a generic data type RandomizedQueue that implements the following API:

public class RandomizedQueue<Item> implements Iterable<Item> {
   public RandomizedQueue()                 // construct an empty randomized queue
   public boolean isEmpty()                 // is the randomized queue empty?
   public int size()                        // return the number of items on the randomized queue
   public void enqueue(Item item)           // add the item
   public Item dequeue()                    // remove and return a random item
   public Item sample()                     // return a random item (but do not remove it)
   public Iterator<Item> iterator()         // return an independent iterator over items in random order
   public static void main(String[] args)   // unit testing (optional)
}
Iterator.  Each iterator must return the items in uniformly random order. The order of two or more iterators to the same randomized queue must be mutually independent; each iterator must maintain its own random order.

Corner cases.  Throw the specified exception for the following corner cases:

Throw a java.lang.IllegalArgumentException if the client calls enqueue() with a null argument.
Throw a java.util.NoSuchElementException if the client calls either sample() or dequeue() when the randomized queue is empty.
Throw a java.util.NoSuchElementException if the client calls the next() method in the iterator when there are no more items to return.
Throw a java.lang.UnsupportedOperationException if the client calls the remove() method in the iterator.
*/
/*
  (removeFirst)first->[][][][][][][][]<-last(enqueue here)(removeLast)
                             |
                             dequeue from here
You can have a loot at my decque implementation before moving on.
*/
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
void printList(struct node *n);
int length=0;
int main()
{
  dequeue();
  enqueue(4);
  enqueue(5);
  enqueue(6);
  printList(first);
  printf("\n");
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
  length++;
}

void removeFirst(){
  if(first->next==NULL){
    printf("\ndequeue:decque is empty\n");
  }else{
    struct node *temp=first;
    first=first->next;
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

void dequeue(){
   if(first==NULL){
    printf("\nThe randomized queue is empty.\n");
  }else{
    srand(time(0));
    int randInt=(rand()%(length))+1;
    if(randInt==1){
      removeFirst();
    }else if(randInt==length){
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
    prev->next=current->next;
    current->next=NULL;
    free(current);
    }
    length--;
  }
}

void printList(struct node *n){
  while (n != NULL)
  {
     printf("%d", n->data);
     n=n->next;
  }
}
