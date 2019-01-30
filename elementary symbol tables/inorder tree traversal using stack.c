// @author mgroovyank(MAYANK CHHIPA)
#include<stdio.h>
#include<stdlib.h>
struct stack
{
  struct node *data;
  struct stack *next;
};
struct node
{
  char key;
  int value;
  int count;
  struct node *left;
  struct node *right;
};

struct stack *stackHead=NULL;
struct node *head=NULL;
struct node* put(struct node *root,char key,int value);
void inorder(struct node*);
void push(struct node*);
void pop();

int main()
{
  head=put(head,'S',1);
  put(head,'E',2);
  put(head,'X',3);
  put(head,'A',4);
  put(head,'R',5);
  put(head,'C',6);
  put(head,'H',7);
  printf("\n");
  inorder(head);
}

void push(struct node *data){
  struct stack *newHead=NULL;
  newHead=(struct stack*)malloc(sizeof(struct stack));
  newHead->data=data;
  newHead->next=stackHead;
  stackHead=newHead;
}

void pop(){
  struct stack *temp=stackHead;
  stackHead=stackHead->next;
  temp->next=NULL;
  free(temp);
}

struct node* put(struct node *root,char key,int value){
  if(root==NULL){
    struct node *newNode=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->key=key;
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
  }
  if(root->key>key){
    root->left=put(root->left,key,value);
  }else if(root->key<key){
    root->right=put(root->right,key,value);
  }else{
    root->value=value;
  }
  return root;
}

void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  struct node *current;
  current=root;
  while(current!=NULL || stackHead!=NULL){
    while(current!=NULL){
    push(current);
    current=current->left;
  }
  current=stackHead->data;
  printf("%c",stackHead->data->key);
  pop();
  current=current->right;
  }
}
