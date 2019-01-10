#include<stdio.h>
int binary_search(char key,char keys[],int lo,int hi);
int get(char keys[],char key);
int rank(char keys[],char key);//number of keys < key
int main(){
  //parallel keys and values in two arrays
  char keys[10]={'B','C','E','H','L','M','P','R','S','X'};
  int vals[10]={0,1,2,3,4,5,6,7,8,9};

  int valIndex=get(keys,'P');
  printf("\nThe value of index P is %d\n",vals[valIndex]);

  int rnk=rank(keys,'Q');
  printf("\nThe rank of this key is %d\n",rnk);
}

int binary_search(char key,char keys[],int lo,int hi){
  int mid=lo+(hi-lo)/2;
  if(hi<lo){
    printf("The key doesn't exist in keys");
    return lo;
  }
  if(keys[mid]==key){
    return mid;
  }else if(keys[mid]>key){
    hi=mid-1;
    return binary_search(key,keys,lo,hi);
  }else if(keys[mid]<key){
    lo=mid+1;
    return binary_search(key,keys,lo,hi);
  }
}

int get(char keys[],char key){
  int valIndex=binary_search(key,keys,0,9);
  return valIndex;
}

int rank(char keys[],char key){
  int lo=binary_search(key,keys,0,9);
  return lo;
}
