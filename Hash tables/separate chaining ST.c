#include<stdio.h>
#include<stdlib.h>
struct node
{
  char key;
  int val;
  struct node *next;
};
struct node *st[5];
void put(char key,int val,int hash);
int get(char key,int hash);
int main()
{
  char keys[]="SEARCHEXAMPLE";
  int hash[]={2,0,0,4,4,4,0,2,0,4,3,3,0};
  int values[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
  int i,v;
  for(i=0;i<13;i++){
    put(keys[i],values[i],hash[i]);
  }

  for(i=0;i<13;i++){
    v=get(keys[i],hash[i]);
    printf("\n%d\n",v);
  }
}

void put(char key,int val,int hash){
  struct node *x;
  x=st[hash];
  while(x!=NULL){
    if(x->key==key){
      x->val=val;
      return;
    }
    x=x->next;
  }
  struct node *newHead=NULL;
  newHead=(struct node*)malloc(sizeof(struct node));
  newHead->key=key;
  newHead->val=val;
  newHead->next=st[hash];
  st[hash]=newHead;
  return;
}

int get(char key,int hash){
  struct node *x;
  x=st[hash];
  while(x!=NULL){
    if(x->key==key){
      return x->val;
    }
    x=x->next;
  }
  printf("No such key found");
  return 0;
}
