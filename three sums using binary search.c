#include<stdio.h>
int binary_search(int num,int a[],int lo,int hi);
int main(){
  int a[]={-40,-20,-10,0,5,10,30,40};
  int length_a=sizeof(a)/sizeof(a[0]);
  int lo=0;
  int hi=length_a-1;
  int i,j,num,ths=0;
  for(i=0;i<length_a-1;i++){
    for(j=i+1;j<length_a-1;j++){
      num=-(a[i]+a[j]);
      int result=binary_search(num,a,lo,hi);
      if(result!=0){
        ths++;
        }
    }
  }
  printf("The number of three sums in array is %d",ths);
}
int binary_search(int num,int a[],int lo,int hi){
  int mid=lo+(hi-lo)/2;
  if(num<a[lo] || num>a[hi]){
    return 0;
  }
  if(a[mid]==num){
    return num;
  }else if(a[mid]>num){
    hi=mid-1;
    return binary_search(num,a,lo,hi);
  }else if(a[mid]<num){
    lo=mid+1;
    return binary_search(num,a,lo,hi);
  }
}
