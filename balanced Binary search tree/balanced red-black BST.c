//@author mgroovyank(MAYANK CHHIPA)
#include<stdio.h>
#include<stdlib.h>
struct node
{
  char key;
  int value;
  int color;//0=black, 1=red
  struct node *left;
  struct node *right;
};
struct node *head=NULL;
struct node* put(struct node *root,char key,int value);
int isRed(struct node*);
struct node* rotateLeft(struct node*);
struct node* rotateRight(struct node*);
void flipColors(struct node*);
void inorder(struct node *root);

int main()
{
  head=put(head,'S',1);inorder(head);printf("\n");
  head=put(head,'E',2);inorder(head);printf("\n");
  head=put(head,'X',3);inorder(head);printf("\n");
  head=put(head,'A',4);inorder(head);printf("\n");
  head=put(head,'R',5);inorder(head);printf("\n");
  head=put(head,'C',6);inorder(head);printf("\n");
  head=put(head,'H',7);inorder(head);printf("\n");
}

struct node* put(struct node *root,char key,int value){
  if(root==NULL){
    struct node *newNode=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->key=key;
    newNode->value=value;
    newNode->color=1;
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

  if(isRed(root->right) && !isRed(root->left)){
    root=rotateLeft(root);
  }
  if(isRed(root->left) && isRed(root->left->left)){
    root=rotateRight(root);
  }
  if(isRed(root->left) && isRed(root->right)){
    flipColors(root);
  }

  return root;
}

int isRed(struct node *root){
  if(root==NULL){
    return 0;
  }
  if(root->color==0){
    return 0;
  }else if(root->color==1){
    return 1;
  }
}

struct node* rotateLeft(struct node *root){
  struct node *temp=root->right;
  root->right=temp->left;
  temp->left=root;
  temp->color=root->color;
  root->color=1;
  return temp;
}

struct node* rotateRight(struct node *root){
  struct node *temp=root->left;
  root->left=temp->right;
  temp->right=root;
  temp->color=root->color;
  root->color=1;
  return temp;
}

void flipColors(struct node *root){
  root->color=1;
  root->left->color=0;
  root->right->color=0;
}

void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  printf("%c",root->key);
  inorder(root->right);
}
