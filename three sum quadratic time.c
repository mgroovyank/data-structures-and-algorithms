//3-SUM in quadratic time. Design an algorithm for the 3-SUM problem that takes time proportional to n^2n in the worst case. You may assume that you can sort the nn integers in time proportional to n^2n or better.

#include <stdio.h>
int main() {
  int a[]={-40,-20,-10,0,5,10,30,40};
  int length_a=sizeof(a)/sizeof(a[0]);
  int i,j,k,sum,count=0;
  for(i=0;i<length_a-2;i++){
    j=i+1;
    k=length_a-1;
    while(j<k){
      sum=a[i]+a[j]+a[k];
      if(sum==0){
        count++;
      }
      if(sum>=0){
        k--;
      }else{
        j++;
      }
    }
  }
  printf("The number of three sums is %d ",count);
}
