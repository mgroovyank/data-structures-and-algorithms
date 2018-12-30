/*   Dynamic median.

  Design a data type that supports insert in logarithmic time, find-the-median
  in constant time, and remove-the-median in logarithmic time. If the
  number of keys in the data type is even, find/remove the lower median.

   Hint- maintain two binary heaps, one that is max-oriented and one that is
   min-oriented.

   @author mgroovyank(MAYANK CHHIPA)

 */
#include<stdio.h>
void Maxswim(int arr[],int k);
void MaxIns(int arr[],int val,int end);
void Minswim(int arr[],int k);
void MinIns(int arr[],int val,int end);
void Maxsink(int arr[],int k,int end);
int delMax(int arr[],int end);
void Minsink(int arr[],int k,int end);
int delMin(int arr[],int end);
int exch(int arr[],int p,int q);
void printArray(int arr[],int end);
int main(){
  int arr[15]={-1,34,16,30,17,37,19,32,24,25,29,27,10};
  int median;
  int minHeap[10],maxHeap[10];
  int minEnd=1,maxEnd=1;
  int i;
  for(i=1;i<13;i++){
    if(i==1){
      MaxIns(maxHeap,arr[i],maxEnd++);
      median=maxHeap[1];
      continue;
    }
    if(arr[i]<=median){
      if(maxEnd-minEnd==1){
        MinIns(minHeap,maxHeap[1],minEnd++);
        delMax(maxHeap,maxEnd--);
        MaxIns(maxHeap,arr[i],maxEnd++);
      }else{
        MaxIns(maxHeap,arr[i],maxEnd++);
      }
      median=maxHeap[1];
    }else{
      if(minEnd-maxEnd==1){
        MaxIns(maxHeap,minHeap[1],maxEnd++);
        delMin(minHeap,minEnd--);
        MinIns(minHeap,arr[i],minEnd++);
      }else{
        MinIns(minHeap,arr[i],minEnd++);
      }
      median=minHeap[1];
    }
  }
  printArray(maxHeap,maxEnd);
  printArray(minHeap,minEnd);
  printf("\n---------\n");
  printf("median = %d",median);
  printf("\n---------\n");
}

void Maxswim(int arr[],int k){
  while(k>1 && arr[k]>arr[k/2]){
    exch(arr,k/2,k);
    k=k/2;
  }
}

void MaxIns(int arr[],int val,int end){
  arr[end]=val;
  Maxswim(arr,end);
}

void MinIns(int arr[],int val,int end){
  arr[end]=val;
  Minswim(arr,end);
}

void Minswim(int arr[],int k){
  while(k>1 && arr[k]<arr[k/2]){
    exch(arr,k/2,k);
    k=k/2;
  }
}

int exch(int arr[],int p,int q){
  int temp;
  temp=arr[q];
  arr[q]=arr[p];
  arr[p]=temp;
}

void Maxsink(int arr[],int k,int end){
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

int delMax(int arr[],int end){
  exch(arr,1,end-1);
  Maxsink(arr,1,end-1);
  return arr[end];
}

void Minsink(int arr[],int k,int end){
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
    if(arr[k]>arr[2*k] && arr[k]>arr[2*k+1]){
      if(arr[2*k]<arr[2*k+1]){
        exch(arr,k,2*k);
        k=2*k;
      }else{
        exch(arr,k,2*k+1);
        k=2*k+1;
      }
    }else if(arr[k]>arr[2*k]){
      exch(arr,k,2*k);
      k=2*k;
    }else if(arr[k]>arr[2*k+1]){
      exch(arr,k,2*k+1);
      k=2*k+1;
    }else{
      break;
    }
  }
}

int delMin(int arr[],int end){
  exch(arr,1,end-1);
  Minsink(arr,1,end-1);
  return arr[end];
}

void printArray(int arr[],int end){
  int i;
  for(i=1;i<end;i++){
    printf(" %d ",arr[i]);
  }
  printf("\n");
}
