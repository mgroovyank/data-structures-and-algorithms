#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
  srand(time(0));
  int a[]={4,7,3,8,9,5,2,1};
  int i,length_a,t,rand_int;
  length_a=sizeof(a)/sizeof(a[0]);
  for(i=1;i<length_a;i++){
    rand_int=(rand()%i);
    t=a[rand_int];
    a[rand_int]=a[i];
    a[i]=t;
  }
  for(i=0;i<length_a;i++){
    printf("%d",a[i]);
  }
}
