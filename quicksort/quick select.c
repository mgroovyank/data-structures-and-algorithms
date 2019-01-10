#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int arr[],int lo,int hi);
int partition(int arr[],int lo,int hi);
void quickSelect(int arr[],int lo,int hi,int k);
int main(){
  srand(time(0));
  int arr[]={9,8,3,6,5,4,7};
  shuffle(arr,0,6);
  int i;
  for(i=0;i<7;i++){
    printf(" %d ",arr[i]);
  }
  printf("\n");
  quickSelect(arr,0,6,0);
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

void quickSelect(int arr[],int lo,int hi,int k){
  int p;
  while(lo<=hi){
    p=partition(arr,lo,hi);
    if(p<k){
      lo=p+1;
    }else if(k<p){
      hi=p-1;
    }else{
      printf("The Kth largest is %d",arr[p]);
      return;
    }
  }
}
