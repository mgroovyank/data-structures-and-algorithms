/*

Write a data type to represent a set of points in the unit square (all points have 
x- and y-coordinates between 0 and 1) using a
2d-tree to support efficient range search (find all of the points contained in a query rectangle)
and nearest-neighbor search (find a closest point to a query point).
2d-trees have numerous applications, ranging from classifying astronomical objects
to computer animation to speeding up neural networks to mining data to image retrieval.

*/
//@author mgroovyank
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
  double x;
  double y;
  struct node *left;
  struct node *right;
};
struct node *head=NULL;
struct node* insert(struct node *root,double x,double y,int l);
int ptInRect(double a,double b,double c,double d,double x,double y);
void rangeSearch(struct node *root,double a,double b,double c,double d,int l);
//a=min-x b=min-y c=max-x d=max-y
double dist(double a,double b,double x,double y);
struct node* near(struct node *root,double x,double y,int l,int d);
int main()
{
  head=insert(head,0.7,0.2,0);
  head=insert(head,0.5,0.4,0);
  head=insert(head,0.2,0.3,0);//0.1,0.2,0.3,0.4
  head=insert(head,0.4,0.7,0);
  head=insert(head,0.9,0.6,0);
  rangeSearch(head,0.1,0.2,0.3,0.35,0);
  
}

struct node* insert(struct node *root,double x,double y,int l){
  if(root==NULL){
    struct node *newNode=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->x=x;
    newNode->y=y;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
  }
  if(l==0){
    if(root->x>x){
      root->left=insert(root->left,x,y,1);
    }else if(root->x<x){
      root->right=insert(root->right,x,y,1);
    }
  }else if(l==1){
    if(root->y>y){
      root->left=insert(root->left,x,y,0);
    }else if(root->y<y){
      root->right=insert(root->right,x,y,0);
    }
  }
  return root;
}

int ptInRect(double a,double b,double c,double d,double x,double y){
  
  if(x<c && x>a && y>b && y<d){
    printf("\nPoint is in the rectangle\n");
    return 1;
  }
  return 0;
}

void rangeSearch(struct node *root,double a,double b,double c,double d,int l){
  int i=ptInRect(a,b,c,d,root->x,root->y);
  if(i==1){
    printf("\nThe rectangle contains one point\n");
    return;
  }
  if(l==0){
    if(c<root->x){
      rangeSearch(root->left,a,b,c,d,1);
    }else{
      rangeSearch(root->right,a,b,c,d,1);
    }
  }else{
    if(d<root->y){
      rangeSearch(root->left,a,b,c,d,0);
    }else{
      rangeSearch(root->right,a,b,c,d,0);
    }
  }
}

double dist(double a,double b,double x,double y){
  double t=(x-a)*(x-a)+(y-b)*(y-b);
  double result=pow(t,0.5);
  return result;
}

struct node* near(struct node *root,double x,double y,int l,int d){
  int t;
  t=dist(x,y,root->x,root->y);
  if(t==0){
    return;
  }
  if(d==-1){
    d=dist(x,y,root->x,root->y);
    if(x<root->x){
      near(root->left,x,y,1,d);
    }else{
      near(root->right,x,y,1,d);
    }
  }
  if(l==0){
    if(t<d){
      d=t;
    }
  }else if(l==1){
    if(t<d){
      d=t;
    }
    if(y<root->y){
      near(root->left,x,y,0,d)
    }else{
      near(root->right,x,y,0,d);
    }
  }
}
