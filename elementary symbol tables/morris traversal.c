/*Inorder traversal with constant extra space.
Design an algorithm to perform an inorder traversal of a binary search tree using only a constant amount of extra space.
You need to traverse the binary tree in order without using a stack or recursion.

Solution - 

1. Initialize current as root 
2. While current is not NULL
   If current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) In current's left child's right subtree, search for rightmost node.This will be the predecessor to current.
      b) Go to this left child, i.e., current = current->left
      

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
void inorder(struct node *root);
void morrisTraversal(struct node*);

int main()
{
  head=put(head,'S',1);
  put(head,'E',2);
  put(head,'X',3);
  put(head,'A',4);
  put(head,'R',5);
  put(head,'C',6);
  put(head,'H',7);
  inorder(head);
  printf("\n");
  morrisTraversal(head);
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

void inorder(struct node *root){//IN ORDER TRAVERSAL USING RECURSION
  if(root==NULL){
    return;
  }
  inorder(root->left);
  printf("%c",root->key);
  inorder(root->right);
}

void morrisTraversal(struct node *root){//IN ORDER TRAVERSAL WITHOUT USING STACK OR RECURSION
  if(root==NULL){
    return;
  }
  struct node *pre,*current;//pre=predecessor
  current=root;
  while(current!=NULL){
    if(current->left==NULL){
      printf("%c",current->key);
      current=current->right;
    }else{
      pre=current->left;
      while(pre->right!=NULL && pre->right!=current){//SERACH FOR RIGHTMOST ELEMENT
        pre=pre->right;
      }
      if(pre->right==NULL){
        pre->right=current;
        current=current->left;
      }else{
        pre->right=NULL;
        printf("%c",current->key);
        current=current->right;
        }
    }
  }
}

