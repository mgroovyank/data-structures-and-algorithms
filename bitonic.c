/**
 * Coursera - Algorithms Part I
 * Week 1 - Interview Questions - Union Find
 *
 * Question 2: Search in a bitonic array
 * An array is bitonic if it is comprised of an increasing sequence of integers
 * followed immediately by a decreasing sequence of integers. Write a program
 * that, given a bitonic array of N distinct integer values, determines whether
 * a given integer is in the array.
 *
 * Standard version: Use ~3lgN compares in the worst case.
 * Signing bonus: Use ~2lgN compares in the worst case (and prove that no
 * algorithm can guarantee to perform fewer than ~2lgN compares in the worst case).
 **/


#include<stdio.h>
int max_binary_search(int a[],int lo,int hi);
int binary_search1(int num,int a[],int lo,int hi);
int binary_search2(int num,int a[],int lo,int hi);
int main(){
  int a[]={0,5,7,9,6,4,3};
  int max=max_binary_search(a,0,7);
  printf("The maximum value in array is %d\n",a[max]);

  int length_a,result,num;
  length_a=sizeof(a)/sizeof(a[0]);
  num=6;
  result=binary_search1(num,a,0,max);
  if(result==0){
    result=binary_search2(num,a,max+1,length_a-1);
  }
  if(result==0){
    printf("Number does not exist in array");
  }else{
    printf("Number was found in array");
  }
}

int max_binary_search(int a[],int lo,int hi){
  int mid=lo+(hi-lo)/2;
  if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
    return mid;
  }else if(a[mid]<a[mid+1] && a[mid]>a[mid-1]){
    return max_binary_search(a,lo=mid,hi);
  }else if(a[mid]<a[mid-1] && a[mid]>a[mid+1]){
    return max_binary_search(a,lo,hi=mid);
  }
}

int binary_search1(int num,int a[],int lo,int hi){
  int mid=lo+(hi-lo)/2;
  if(num<a[lo] || num>a[hi]){
    return 0;
  }
  if(a[mid]==num){
    return 1;
  }else if(a[mid]>num){
    hi=mid-1;
    return binary_search1(num,a,lo,hi);
  }else if(a[mid]<num){
    lo=mid+1;
    return binary_search1(num,a,lo,hi);
  }
}

//for array elements arranged in descending order
int binary_search2(int num,int a[],int lo,int hi){
  int mid=lo+(hi-lo)/2;
  if(num>a[lo] || num<a[hi]){
    return 0;
  }
  if(a[mid]==num){
    return 1;
  }else if(a[mid]>num){
    lo=mid+1;
    return binary_search2(num,a,lo,hi);
  }else if(a[mid]<num){
    hi=mid-1;
    return binary_search2(num,a,lo,hi);
  }
}
