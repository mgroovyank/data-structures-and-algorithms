/*
  Problem - Merging with smaller auxiliary array.
  * Suppose that the subarray \mathtt{a[0]}a[0] to \mathtt{a[n-1]}a[n−1] is sorted and the subarray \mathtt{a[n]}a[n] to \mathtt{a[2*n-1]}a[2∗n−1] is sorted. How can you merge the two subarrays so that \mathtt{a[0]}a[0] to \mathtt{a[2*n-1]}a[2∗n−1] is sorted using an auxiliary array of length nn (instead of 2n2n)?

  Solution:
  *copy only the left half into the auxiliary array.
*/
#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int m,int r);
void mergesort(int arr[],int l,int r);
void printArray(int arr[],int arr_size);
int main(){
  int arr[]={12,11,13,5,6,7};
  int arr_size=sizeof(arr)/sizeof(arr[0]);
  printArray(arr,arr_size);
  mergesort(arr,0,arr_size-1);
  printArray(arr,arr_size);
}

void merge(int arr[],int l,int m,int r){
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;

  int L[n1];
  for(i=0;i<n1;i++){
    L[i]=arr[l+i];
  }

  i=0;
  j=m+1;
  k=l;
  while(i<n1 && j<=r){
    if(L[i]>arr[j]){
      arr[k]=arr[j];
      j++;
      k++;
    }else if(L[i]<arr[j]){
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
  while(j<=r){
    arr[k]=arr[j];
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
