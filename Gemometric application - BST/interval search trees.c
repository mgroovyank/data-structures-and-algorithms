//@author mgroovyank(MAYANK CHHIPA)
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x;
  int y;
  int rmax;
  struct node *left;
  struct node *right;
};
struct node *head=NULL;
struct node* insert(struct node *root,int x,int y);
struct node* search(struct node *root,int x,int y);
int intersects(int x,int y,int a,int b);//x and y are corresponding points and same for and b

int main()
{
  head=insert(head,17,19);
  head=insert(head,5,8);
  head=insert(head,21,24);
  head=insert(head,4,8);
  head=insert(head,15,18);
  head=insert(head,7,10);
  head=insert(head,16,22);
  struct node *temp=search(head,21,23);
  if(temp==NULL){
    printf("no intersecting interval found");
  }else{
    printf(" x= %d y= %d ",temp->x,temp->y);
  }
}

struct node* insert(struct node *root,int x,int y){
  if(root==NULL){
    struct node *newNode=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->x=x;
    newNode->y=y;
    newNode->rmax=y;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
  }
  if(root->x>x){
    root->left=insert(root->left,x,y);
    if(root->left->rmax>root->rmax){
      root->rmax=root->left->rmax;
    }
  }else if(root->x<x){
    root->right=insert(root->right,x,y);
    if(root->right->rmax>root->rmax){
      root->rmax=root->right->rmax;
    }
  }else{
    root->x=x;
    root->y=y;
  }
  return root;
}

struct node* search(struct node *root,int x,int y){
  while(root!=NULL){
    if(intersects(root->x,root->y,x,y)){
      return root;
    }else if(root->left==NULL){
      root=root->right;
    }else if(root->left->rmax<x){
      root=root->right;
    }else{
      root=root->left;
    }
  }
  return NULL;
}

int intersects(int x,int y,int a,int b){
  int i;
  for(i=a;i<=b;i++){
    if(i>=x && i<=y){
      return 1;
    }else{
      continue;
    }
  }
  return 0;
}

