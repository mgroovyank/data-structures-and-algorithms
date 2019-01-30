/*
  Check if a binary tree is a BST. 
  Given a binary tree where each Node contains a key, determine whether it is a binary search tree. 
  Use extra space proportional to the height of the tree.
  
  Solution: Use inorder to print the values in binary tree and see if they are in ascending order.
            Maintain a prev variable to keep track of the largest node you have traversed till then.
            
    @author mgroovyank(MAYANK CHHIPA)
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  char key;
  int value;
  struct node *left;
  struct node *right;
};
struct node *head=NULL;
struct node* put(struct node *root,char key,int value);
void inorder(struct node *root,struct node *prev);

int main()
{
  head=put(head,'S',1);
  put(head,'E',2);
  put(head,'X',3);
  put(head,'A',4);
  put(head,'R',5);
  put(head,'C',6);
  put(head,'H',7);
  inorder(head,NULL);
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

void inorder(struct node *root,struct node *prev){
  if(root==NULL){
    return;
  }
  inorder(root->left,prev);
  printf("%c",root->key);
  prev=root;
  if(prev->key>root->key){
    printf("not binary search tree");
    return;
  }
  inorder(root->right,prev);
}

