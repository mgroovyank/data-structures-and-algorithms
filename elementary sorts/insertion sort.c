#include<stdio.h>
int main(){
  float a[]={10,7,5,3,8,4,2,9,6},t;
  int i,j;
  int length_a=sizeof(a)/sizeof(a[0]);
  for(i=0;i<length_a;i++){
    for(j=i;j>0;j--){
      if(a[j-1]>=a[j]){
        t=a[j];
        a[j]=a[j-1];
        a[j-1]=t;
        continue;
      }
      break;
    }
  }
  for(i=0;i<length_a;i++){
    printf(" %f ",a[i]);
  }
  for(i=0;i<length_a-1;i++){
    if(a[i]<=a[i+1]){
      continue;
    }else{
      printf("Insertion sort didn't work!!");
      break;
    }
  }
}
