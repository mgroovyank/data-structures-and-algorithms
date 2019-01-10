/*
   Randomized priority queue.

   Describe how to add the methods \mathtt{sample()}sample() and \mathtt{delRandom()}
   delRandom() to our binary heap implementation. The two methods return a
   key that is chosen uniformly at random among the remaining keys, with
   the latter method also removing that key. The \mathtt{sample()}sample() method
   should take constant time; the \mathtt{delRandom()}delRandom() method should
    take logarithmic time. Do not worry about resizing the underlying array.

    Hint - use sink() and swim().
          *get a random number form 1 - N, and get the element of that index in the array as the sample() result. for DelRandom(), swap that element with the last element,
           and sink and swim in that index.

   @author mgroovyank(MAYANK CHHIPA)

*/
#include<stdio.h>
void swim(int arr[],int k);
void insert(int arr[],int val,int end);
void sink(int arr[],int k,int end);
int delRandom(int arr[],int rand,int end);
int exch(int arr[],int p,int q);
void printArray(int arr[],int end);
int main(){
  int arr[15]={-1,34,30,29,27,25,17,16,19,22,24};
  int end=11;
  int rand;
  insert(arr,32,end++);
  printArray(arr,end);
  rand=delRandom(arr,10,end--);
  printArray(arr,end);
  printf("\n-----------\n");
  printf("the deleted element is %d",rand);
  printf("\n-----------\n");
}

void swim(int arr[],int k){
  while(k>1 && arr[k]>arr[k/2]){
    exch(arr,k/2,k);
    k=k/2;
  }
}

void insert(int arr[],int val,int end){
  arr[end]=val;
  swim(arr,end);
}

void sink(int arr[],int k,int end){
  while(2*k<=end-1){
    if(2*k+1>end-1){
      if(arr[2*k]>arr[k]){
        exch(arr,k,2*k);
        k=2*k;
        continue;
      }else{
        break;
      }
    }
    if(arr[k]<arr[2*k] && arr[k]<arr[2*k+1]){
      if(arr[2*k]>arr[2*k+1]){
        exch(arr,k,2*k);
        k=2*k;
      }else{
        exch(arr,k,2*k+1);
        k=2*k+1;
      }
    }else if(arr[k]<arr[2*k]){
      exch(arr,k,2*k);
      k=2*k;
    }else if(arr[k]<arr[2*k+1]){
      exch(arr,k,2*k+1);
      k=2*k+1;
    }else{
      break;
    }
  }
}

int delRandom(int arr[],int rand,int end){
  exch(arr,rand,end-1);
  sink(arr,rand,end-1);
  return arr[end-1];
}

int exch(int arr[],int p,int q){
  int temp;
  temp=arr[q];
  arr[q]=arr[p];
  arr[p]=temp;
}

void printArray(int arr[],int end){
  int i;
  for(i=1;i<end;i++){
    printf(" %d ",arr[i]);
  }
  printf("\n");
}
