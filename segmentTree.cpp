#include <iostream>
#include <cmath>
using namespace std;
int createST_util(int arr[],int l,int r,int *st,int cn){
  if(l==r){
    st[cn]=arr[l];
    return st[cn];
  }
  int mid=l+(r-l)/2;
  st[cn]=createST_util(arr,l,mid,st,2*cn+1)+createST_util(arr,mid+1,r,st,2*cn+1+1);
  return st[cn];
}
int* createST(int arr[],int n){
  int h=(int)ceil(log2(n));
  int nodes=2*(int)pow(2,h)-1;
  int *st=new int[nodes];
  createST_util(arr,0,n-1,st,0);
  return st;
}
int getSum(int *st,int cn,int l,int r,int x,int y){
  if(l>=x && r<=y){
    return st[cn];
  }
  if(r<x || l>y){
    return 0;
  }
  int mid=l+(r-l)/2;
  return getSum(st,2*cn+1,l,mid,x,y)+getSum(st,2*cn+2,mid+1,r,x,y);
}
void updateVal_util(int *st,int l,int r,int u,int diff,int cn){
  if(u<l || u>r){
    return;
  }
  st[cn]=st[cn]+diff;
  if(l!=r){
    int mid=l+(r-l)/2;
    updateVal_util(st,l,mid,u,diff,2*cn+1);
    updateVal_util(st,mid+1,r,u,diff,2*cn+2);
  }
}
void updateVal(int arr[],int n,int u,int v,int *st){
  int diff=v-arr[u];
  arr[u]=v;
  updateVal_util(st,0,n-1,u,diff,0);
}
int main(){
  int n;
  cin>>n;
  int i,arr[n];
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  int *st=createST(arr,n);
  int m,x,y;
  cin>>m;
  while(m--){
    cin>>x>>y;
  }
  int sum=getSum(st,0,0,n-1,x,y);
  int u,v;
  cin>>u>>v;
  updateVal(arr,n,u,v,st);
  return 0;
}
