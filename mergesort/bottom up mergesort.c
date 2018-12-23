#include <stdio.h>
void merge(int arr[],int l,int m,int r);
void printArray(int arr[],int arr_size);
int main() {
  int arr[]={4,9,2,7,5,3,0};
  printArray(arr,7);
  int sz,lo;
  for(sz=1;sz<7;sz=2*sz){
    for(lo=0;lo<7-sz;lo+=2*sz){
      if(lo+2*sz-1<6){
        merge(arr,lo,lo+sz-1,lo+2*sz-1);
      }else{
        merge(arr,lo,lo+sz-1,6);
      }
    }
  }
  printArray(arr,7);
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

void printArray(int arr[],int arr_size){
  int i;
  printf("\n");
  for(i=0;i<arr_size;i++){
    printf(" %d ",arr[i]);
  }
  printf("\n");
}
