// @author mgroovyank(MAYANK CHHIPA)
#include<stdio.h>
#include<stdlib.h>
struct node
{
  char key;
  int value;
  int count;
  struct node *left;
  struct node *right;
};
struct node *head=NULL;
struct node* put(struct node *root,char key,int value);
int get(char key);
struct node* flr(struct node *root,char key);
struct node* ceiling(struct node *root,char key);
int size(struct node *root);
int rank(struct node *root,char key);
void inorder(struct node *root);
struct node* deleteMin(struct node *root);

int main()
{
  head=put(head,'S',1);
  printf("%d",head->value);
  put(head,'E',2);
  put(head,'X',3);
  put(head,'A',4);
  put(head,'R',5);
  put(head,'C',6);
  put(head,'H',7);
  int temp=get('R');
  printf("\n%d",temp);
  struct node *f=flr(head,'G');
  printf("\n%c",f->key);
  f=ceiling(head,'B');
  printf("\n%c",f->key);
  int t=rank(head,'X');
  printf("\n%d\n",t);
  inorder(head);
  deleteMin(head);
  printf("\n");
  inorder(head);
}

int size(struct node *root){
  if(root==NULL){
    return 0;
  }
  return root->count;
}

struct node* put(struct node *root,char key,int value){
  if(root==NULL){
    struct node *newNode=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->key=key;
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->count=1;
    return newNode;
  }
  if(root->key>key){
    root->left=put(root->left,key,value);
  }else if(root->key<key){
    root->right=put(root->right,key,value);
  }else{
    root->value=value;
  }
  root->count=1+size(root->left)+size(root->right);
  return root;
}

int get(char key){
  struct node *temp=head;
  while(temp!=NULL){
    if(temp->key==key){
      return temp->value;
    }else if(temp->key>key){
      temp=temp->left;
    }else{
      temp=temp->right;
    }
  }
}

struct node* flr(struct node *root,char key){
  if(root==NULL){
    return NULL;
  }
  if(root->key==key){
    return root;
  }else if(root->key>key){
    return flr(root->left,key);
  }
  struct node *temp=flr(root->right,key);
  if(temp!=NULL){
    return temp;
  }else{
    return root;
  }
}

struct node* ceiling(struct node *root,char key){
  if(root==NULL){
    return NULL;
  }
  if(root->key==key){
    return root;
  }else if(root->key<key){
    return ceiling(root->right,key);
  }
  struct node *temp=ceiling(root->left,key);
  if(temp!=NULL){
    return temp;
  }else{
    return root;
  }
}

int rank(struct node *root,char key){
  if(root==NULL){
    return 0;
  }
  if(root->key>key){
    return rank(root->left,key);
  }else if(root->key<key){
    return 1+size(root->left)+rank(root->right,key);
  }else if(root->key==key){
    return size(root->left);
  }
}

void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  printf("%c",root->key);
  inorder(root->right);
}

struct node* deleteMin(struct node *root){
  if(root->left==NULL){
    struct node *temp=root->right;
    free(root);
    return temp;
  }
  root->left=deleteMin(root->left);
  root->count=1+size(root->left)+size(root->right);
  return root;
}
