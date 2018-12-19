/*
@author mgroovyank(MAYANK CHHIPA)
*/
#include<stdio.h>
int main(){
  float a[]={10,7,5,3,8,4,2,9,6,23},t;
  int i,j;
  int length_a=sizeof(a)/sizeof(a[0]);
  int h=1;
  while(h<length_a/3){
    h=3*h+1;
  }
  while(h>0){
    for(i=h;i<length_a;i++){
    for(j=i;j>0;j=j-h){
      if(a[j-h]>=a[j]){
        t=a[j];
        a[j]=a[j-h];
        a[j-h]=t;
        continue;
      }
      break;
    }

  }
  h=h/3;
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
