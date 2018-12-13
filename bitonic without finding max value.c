#include<stdio.h>
int binary_search1(int num,int a[],int lo,int hi);
int binary_search2(int num,int a[],int lo,int hi);
int bitonic_search(int num,int a[],int lo,int hi);
int main(){
  int a[]={0,5,7,9,6,4};
  int num=5,result,length_a;
  length_a=sizeof(a)/sizeof(a[0]);
  result=bitonic_search(num,a,0,length_a-1);
  if(result==0){
    printf("Number does not exist in array");
  }
  if(result==1){
    printf("Number was found in array done");
  }
}

int binary_search1(int num,int a[],int lo,int hi){
  printf("biary search");
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
    printf("binary search");
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

int bitonic_search(int num,int a[],int lo,int hi){
  int length_a,result,mid;
  length_a=hi-lo+1;
  mid=lo+(hi-lo)/2;
  if(a[mid]==num){
    return 1;
  }
  if(a[mid]<a[mid-1] && a[mid]>a[mid+1]){
    if(num<a[mid]){
      result=binary_search2(num,a,mid+1,length_a-1);
      if(result==0){
        result=binary_search1(num,a,0,mid-1);
      }
      if(result==0){
        return 0;
      }
      if(result==1){
        return 1;
      }
    }
    if(num>a[mid]){
      hi=mid-1;
      result=bitonic_search(num,a,lo,hi);
      if(result==0){
        return 0;
      }
      if(result==1){
        return 1;
      }
    }
  }

  if(a[mid]>a[mid-1] && a[mid]<a[mid+1]){
    if(num<a[mid]){
      result=binary_search2(num,a,mid+1,length_a-1);
      if(result==0){
        result=binary_search1(num,a,0,mid-1);
      }
      if(result==0){
        return 0;
      }
      if(result==1){
        return 1;
      }
    }
    if(num>a[mid]){
      lo=mid+1;
      result=bitonic_search(num,a,lo,hi);
      if(result==0){
        return 0;
      }
      if(result==1){
        return 1;
      }
    }
  }
  if(a[mid]>a[mid-1] && a[mid]>a[mid-1]){
    result=binary_search2(num,a,mid+1,length_a-1);
    if(result==0){
      result=binary_search1(num,a,0,mid-1);
    }
    if(result==0){
        return 0;
      }
    if(result==1){
      return 1;
    }
  }

}
