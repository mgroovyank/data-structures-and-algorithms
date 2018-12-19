/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
Permutation. Given two integer arrays of size nn, design a subquadratic algorithm to determine whether one is a permutation of the other. That is, do they contain exactly the same entries but, possibly, in a different order.
*/
#include<stdio.h>
void shellsort(int arr[]);
int main(){
  int a[]={1,3,8,5,7,2,9};
  int b[]={3,2,5,9,1,8,7};
  shellsort(a);
  printf("\n");
  shellsort(b);
  printf("\n");
  int i;
   for(i=0;i<7;i++){
    if(a[i]==b[i]){
        if(i==6){
            printf("The arrays are a pemutation of each other");
        }
      continue;
    }else{
      printf("The arrays are not a pemutation of each other");
      break;
    }
  }
}
void shellsort(int arr[]){
  int t;
  int i,j;
  int length_arr=7;
  int h=1;
  while(h<length_arr/3){
    h=3*h+1;
  }
  while(h>0){
    for(i=h;i<length_arr;i++){
    for(j=i;j>0;j=j-h){
      if(arr[j-h]>=arr[j]){
        t=arr[j];
        arr[j]=arr[j-h];
        arr[j-h]=t;
        continue;
      }
      break;
    }

  }
  h=h/3;
  }
  for(i=0;i<length_arr;i++){
    printf(" %d ",arr[i]);
  }
}
