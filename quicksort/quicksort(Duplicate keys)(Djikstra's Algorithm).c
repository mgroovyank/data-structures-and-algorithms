#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int arr[],int lo,int hi);
void quicksort(int arr[],int lo,int hi);
int main(){
  srand(time(0));
  int arr[]={1,-1,0,1,-1,0,0};
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

void quicksort(int arr[],int lo,int hi){
  int lt=lo;
  int gt=hi;
  int mid=lo+1;
  int temp;
  if(lo<hi){
    while(mid<=gt){
      if(arr[mid]==arr[lt]){
        mid++;
      }else if(arr[mid]<arr[lt]){
        temp=arr[mid];
        arr[mid]=arr[lt];
        arr[lt]=temp;
        lt++;
        mid++;//in this case mid needs to shift because lo++ is being done
      }else if(arr[mid]>arr[lt]){
        temp=arr[mid];
        arr[mid]=arr[gt];
        arr[gt]=temp;
        gt--;//take care not to do mid++ in this case as mid need not shift in this case.
      }
    }
    quicksort(arr,lo,lt-1);
    quicksort(arr,gt+1,hi);
  }else{
    return;
  }
}
