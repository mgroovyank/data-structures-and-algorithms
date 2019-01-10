
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int arr[],int lo,int hi);
int partition(int arr[],int lo,int hi);
void quicksort(int arr[],int lo,int hi);

int main(){
  srand(time(0));
  int arr[]={9,8,2,6,5,4,3};
  shuffle(arr,0,6);
  int i;
  for(i=0;i<7;i++){
    printf(" %d ",arr[i]);
  }
  printf("\n");
  quicksort(arr,0,6);
  for(i=0;i<7;i++){
    printf(" %d ",arr[i]);
  }
}

void shuffle(int arr[],int lo,int hi){//Knuth shuffle
  int i,t,rand_int;
  for(i=lo+1;i<=hi;i++){
    rand_int=(rand()%i);
    t=arr[rand_int];
    arr[rand_int]=arr[i];
    arr[i]=t;
  }
}

int partition(int arr[],int lo,int hi){
  int i,t;
  i=lo+1;
  while(hi>=i){
    while(arr[i]<arr[lo]){
      i++;
      if(hi<i){
      t=arr[lo];
      arr[lo]=arr[hi];
      arr[hi]=t;
      return hi;
      }
    }
    while(arr[lo]<arr[hi]){
      hi--;
      if(hi<i){
      t=arr[lo];
      arr[lo]=arr[hi];
      arr[hi]=t;
      return hi;
      }
    }
    if(hi<i){
      t=arr[lo];
      arr[lo]=arr[hi];
      arr[hi]=t;
      return hi;
    }else{
      t=arr[i];
      arr[i]=arr[hi];
      arr[hi]=t;
    }
  }
}

void quicksort(int arr[],int lo,int hi){
  if(lo<hi){
    int p=partition(arr,lo,hi);
    quicksort(arr,lo,p);
    quicksort(arr,p+1,hi);
  }else{
    return;
  }
}
