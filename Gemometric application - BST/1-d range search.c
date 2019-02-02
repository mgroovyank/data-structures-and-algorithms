//@author mgroovyank(MAYANK CHHIPA)
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
int size(struct node *root);
int rank(struct node *root,char key);
void inorder(struct node *root);
int rangeCount(struct node*,char lo,char hi);//number of keys between lo and hi
struct node* rangeSearch(struct node*,char lo,char hi);//print all keys between lo and hi

int main()
{
  head=put(head,'S',1);
  head=put(head,'E',2);
  head=put(head,'X',3);
  head=put(head,'A',4);
  head=put(head,'R',5);
  head=put(head,'C',6);
  head=put(head,'H',7);
  inorder(head);
  int count=rangeCount(head,'A','X');
  printf("\n%d\n",count);
  rangeSearch(head,'A','X');

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

int rangeCount(struct node *root,char lo,char hi){
return rank(root,hi)-rank(root,lo)-1;
}

struct node* rangeSearch(struct node *root,char lo,char hi){
  if(root==NULL){
    return NULL;
  }
  if(root->key>lo && root->key<hi){
    printf("\n%c\n",root->key);
    rangeSearch(root->left,lo,hi);
    rangeSearch(root->right,lo,hi);
  }else if(root->key<=lo){
    rangeSearch(root->right,lo,hi);
  }else if(root->key>=hi){
    rangeSearch(root->left,lo,hi);
  }
}

