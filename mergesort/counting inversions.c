/*
   *Problem - Counting inversions.

   *An inversion in an array a[\,]a[] is a pair of entries a[i]a[i] and a[j]a[j] such that i < ji<j but a[i] > a[j]a[i]>a[j]. Given an array, design a linearithmic algorithm to count the number of inversions.

*/
#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int m,int r);
void mergesort(int arr[],int l,int r);
void printArray(int arr[],int arr_size);
int inv=0;
int main(){
  int arr[]={12,11,13,5,6,7};
  int arr_size=sizeof(arr)/sizeof(arr[0]);
  printArray(arr,arr_size);
  mergesort(arr,0,arr_size-1);
  printArray(arr,arr_size);
  printf("Number of incersion pairs %d",inv);
}

void merge(int arr[],int l,int m,int r){
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;

  int L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=arr[l+i];
  }
  for(j=0;j<n2;j++){
    R[j]=arr[m+1+j];
  }

  i=0;
  j=0;
  k=l;
  while(i<n1 && j<n2){
    if(L[i]>R[j]){
      arr[k]=R[j];
      j++;
      k++;
      inv+=(m-i+1);
    }else if(L[i]<R[j]){
      arr[k]=L[i];
      i++;
      k++;
    }else{
      arr[k]=L[i];
      i++;
      k++;
    }
  }
  while(i<n1){
    arr[k]=L[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k]=R[j];
    j++;
    k++;
  }
}

void mergesort(int arr[],int l,int r){
  if(l<r){
    int m=l+(r-l)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}
void printArray(int arr[],int arr_size){
  int i;
  printf("\n");
  for(i=0;i<arr_size;i++){
    printf(" %d ",arr[i]);
  }
  printf("\n");
}
