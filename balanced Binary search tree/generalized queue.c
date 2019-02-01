/*Generalized queue. 
  Design a generalized queue data type that supports all of the following operations in logarithmic time 
  (or better) in the worst case.

  
   1. Create an empty data structure.
   2. Append an item to the end of the queue.
   3. Remove an item from the front of the queue.
   4. Return the ith item in the queue.
   5. Remove the ith item from the queue.
   
   Hint:create a red–black BST where the keys are integers and the values are the items such that the ith
        largest integer key in the red–black BST corresponds to the ith
        item in the queue.

   @author mgroovyank(MAYANK CHHIPA)
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  int value;//position in queue
  int color;//0=black, 1=red
  struct node *left;
  struct node *right;
};
struct node *head=NULL;
struct node* put(struct node *root,int key,int value);
int isRed(struct node*);
struct node* rotateLeft(struct node*);
struct node* rotateRight(struct node*);
void flipColors(struct node*);
void inorder(struct node *root);
struct node* deleteMin(struct node *root);//dequeue
int get(int value);//return the ith item in the queue
struct node* min(struct node *root);
struct node* del(struct node *root,int value);//delete - hibbard deletion

int main()
{
  head=put(head,1,1);inorder(head);printf("\n");
  head=put(head,4,2);inorder(head);printf("\n");
  head=put(head,2,3);inorder(head);printf("\n");
  head=put(head,9,4);inorder(head);printf("\n");
  head=put(head,5,5);inorder(head);printf("\n");
  head=put(head,6,6);inorder(head);printf("\n");
  head=put(head,0,7);inorder(head);printf("\n");
  deleteMin(head);inorder(head);printf("\n");
  int temp=get(3);
  printf("%d",temp);
  del(head,5);
  inorder(head);printf("\n");
}

struct node* put(struct node *root,int key,int value){
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

  if(root->value>value){
    root->left=put(root->left,key,value);
  }else if(root->value<value){
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
  printf("%d",root->key);
  inorder(root->right);
}

struct node* deleteMin(struct node *root){
  if(root->left==NULL){
    struct node *temp=root->right;
    free(root);
    return temp;
  }
  root->left=deleteMin(root->left);
  return root;
}

int get(int value){
  struct node *temp=head;
  while(temp!=NULL){
    if(temp->value==value){
      return temp->key;
    }else if(temp->value>value){
      temp=temp->left;
    }else{
      temp=temp->right;
    }
  }
}

struct node* del(struct node *root,int value){
  if(root==NULL){
    return NULL;
  }
  if(root->value>value){
    root->left=del(root->left,value);
  }else if(root->value<value){
    root->right=del(root->right,value);
  }else{
    if(root->left==NULL){
      return root->right;
    }
    if(root->right==NULL){
      return root->left;
    }
    struct node *temp=root;
    root=min(temp->right);
    root->right=deleteMin(temp->right);
    root->left=temp->left;
    free(temp);
  }
  return root;
}


struct node* min(struct node *root){
  while(root->left!=NULL){
    root=root->left;
  }
  return root;
}
