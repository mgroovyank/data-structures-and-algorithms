/*
* Dutch national flag. Given an array of nn buckets, each containing a red, white, or blue pebble, sort them by color. The allowed operations are:

* swap(i, j)swap(i,j): swap the pebble in bucket ii with the pebble in bucket jj.
* color(i)color(i): determine the color of the pebble in bucket ii.
* The performance requirements are as follows:

* At most nn calls to color()color().
* At most nn calls to swap()swap().
* Constant extra space.

* DUTCH NATIONAL FLAG ALGORITHM or 3 WAY PARTIONING

* @author mgroovyank(MAYANK CHHIPA)

*/
#include<stdio.h>
main(){
    int a[]={-1,0,1,-1,0,1,-1,0,1};
    int lo,mid,hi,temp;
    lo=0;
    mid=0;
    hi=8;
    while(mid<=hi){
            if(a[mid]==0){
        mid++;
    }else if(a[mid]==-1){
        temp=a[mid];
        a[mid]=a[lo];
        a[lo]=temp;
        lo++;
        mid++;//in this case mid needs to shift because lo++ is being done
    }else if(a[mid]==1){
        temp=a[mid];
        a[mid]=a[hi];
        a[hi]=temp;
        hi--;//take care not to do mid++ in this case as mid need not shift in this case.
    }
    }
    int i;
    for(i=0;i<9;i++){
        printf("%d",a[i]);
    }
}
