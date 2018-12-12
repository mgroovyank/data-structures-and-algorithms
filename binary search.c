#include<stdio.h>
int binary_search(int num,int a[],int lo,int hi);
int main(){
  int a[]={1,2,3,4,5,6};
  int length_a=sizeof(a)/sizeof(a[0]);
  int lo=0;
  int hi=length_a-1;
  int num;
  printf("Enter the number to find:");
  num=2;
  int result=binary_search(num,a,lo,hi);
  if(result!=0){
    printf("number was found in the array");
  }else{
    printf("number doesn't exist in array");
  }
}
int binary_search(int num,int a[],int lo,int hi){
  printf("the num is%d\n",num);
  int mid=lo+(hi-lo)/2;
  printf("mid is%d",mid);
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
