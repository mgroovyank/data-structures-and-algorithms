/*
  Taxicab numbers. A taxicab number is an integer that can be expressed as the
  sum of two cubes of positive integers in two different ways:
  a^3 + b^3 = c^3 + d^3a.

  Design an algorithm to find all taxicab numbers with a, b,c, and  d
   less than n.

   *Version 1: Use time proportional to n^2 log n and space proportional to n^2n
   *Version 2:Use time proportional to n^2 log n and space proportional to n

   **Only version 2 is implemented here

   Hint - Use a min-oriented priority queue with n items

   @author mgroovyank(MAYANK CHHIPA)

*/
#include<stdio.h>
void Minswim(int arr[],int k);
void MinIns(int arr[],int val,int end);
int delMin(int arr[],int end);
int exch(int arr[],int p,int q);
void Minsink(int arr[],int k,int end);
void printArray(int arr[],int end);
int main(){
  int n=1729;
  int arr[15];
  int k=1,sum;
  int i,j,min1;
  for(i=1;i<13;i++){
    for(j=i+1;j<13;j++){
        sum=i*i*i+j*j*j;
        MinIns(arr,sum,k++);
          if(k>=15){
              min1=delMin(arr,k--);
              if(min1==arr[1]){
                  printf("\n %d \n",min1);
              }
          }
    }
  }
}

void Minswim(int arr[],int k){
  while(k>1 && arr[k]<arr[k/2]){
    exch(arr,k/2,k);
    k=k/2;
  }
}


void MinIns(int arr[],int val,int end){
  arr[end]=val;
  Minswim(arr,end);
}

int delMin(int arr[],int end){
  exch(arr,1,end-1);
  Minsink(arr,1,end-1);
  return arr[end-1];
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

void printArray(int arr[],int end){
  int i;
  for(i=1;i<end;i++){
    printf(" %d ",arr[i]);
  }
  printf("\n");
}

int exch(int arr[],int p,int q){
  int temp;
  temp=arr[q];
  arr[q]=arr[p];
  arr[p]=temp;
}
