#include<stdio.h>
void sink(int arr[],int k,int end);
int exch(int arr[],int p,int q);
void printArray(int arr[],int end);
int main(){
  int arr[15]={-1,34,30,29,27,25,17,16,19,27,24};
  int end=11;
  printArray(arr,end);
  int k;
  for(k=(end-1)/2;k>=1;k--){
    sink(arr,k,end);
  }
  while(end>1){
    exch(arr,1,end-1);
    end--;
    sink(arr,1,end);
  }
  printArray(arr,11);
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
