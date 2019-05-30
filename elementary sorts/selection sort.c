#include<stdio.h>
int main(){
  float a[]={1.0,5.0,7.0,4.12,2.34},t,min=a[0];
  int i,j;
  int length_a=sizeof(a)/sizeof(a[0]);
  
  // code that does sorting
  for(i=0;i<length_a;i++){
    for(j=i+1;j<length_a;j++){
      if(a[j]<=a[i]){
        t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
    }
  }
  for(i=0;i<length_a;i++){
    printf(" %f ",a[i]);
  }
  
  // code to check if selection sort worked or not
  for(i=0;i<length_a-1;i++){
    if(a[i]<=a[i+1]){
      continue;
    }else{
      printf("Selection sort didn't work!!");
      break;
    }
  }
}
