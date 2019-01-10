#include<stdio.h>
void insert(int arr[],int val,int key);
int delMax(int arr[],int len);
int main(){
  int arr[6];
  int key=0,max;
  insert(arr,3,key++);
  insert(arr,1,key++);
  insert(arr,2,key++);
  max=delMax(arr,key--);
  printf(" %d ",max);
}
void insert(int arr[],int val,int key){
  arr[key]=val;
}
int delMax(int arr[],int len){
  int i,max=0;
  for(i=0;i<len;i++){
    if(arr[i]>=arr[max]){
      max=i;
    }
  }
  int temp=arr[len-1];
  arr[len-1]=arr[max];
  arr[max]=temp;
  return arr[len-1];
}
