/*
A faster, sorting-based solution.
  * Remarkably, it is possible to solve the problem much faster than the brute-force
    solution described above. Given a point p, the following method determines
    whether p participates in a set of 4 or more collinear points.

  *Think of p as the origin.
  * For each other point q, determine the slope it makes with p.
  *Sort the points according to the slopes they makes with p.
  *Check if any 3 (or more) adjacent points in the sorted order have equal slopes
  with respect to p. If so, these points, together with p, are collinear.

  @author Mayank Chhipa(mgroovyank)
*/
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct point{
  float x;
  float y;
};
struct line{
  struct point pt;
  float slope;
};
struct line lines[10];
float slope(struct point pt1,struct point pt2);
void merge(float arr[],int l,int m,int r);
void mergesort(float arr[],int l,int r);
void printArray(float arr[],int arr_size);
void pushInLines(struct point pt,float slope,int lno);
int findInLines(struct point pt,float slp,int lno);
int main(){
  struct point points[10];
  int i,j,k,slpNo,lno=0,fndLine;
  float slp;
  float tempSlps[9];
  points[0].x=0; points[0].y=0;
  points[1].x=1; points[1].y=1;
  points[2].x=2; points[2].y=0;
  points[3].x=3; points[3].y=0;
  points[4].x=3; points[4].y=1;
  points[5].x=2; points[5].y=2;
  points[6].x=2; points[6].y=3;
  points[7].x=2; points[7].y=4;
  points[8].x=3; points[8].y=3;
  points[9].x=4; points[9].y=4;

  for(i=0;i<10;i++){
    slpNo=0;
    for(j=0;j<10;j++){
      if(i==j){
        continue;
      }else{
        slp=slope(points[i],points[j]);
        tempSlps[slpNo]=slp;
        slpNo++;
      }
    }
    mergesort(tempSlps,0,8);
    for(k=0;k<7;k++){
      if((tempSlps[k]==tempSlps[k+1]) && (tempSlps[k]==tempSlps[k+2])){
        fndLine=findInLines(points[i],tempSlps[k],lno);
        if(fndLine==0){
          pushInLines(points[i],tempSlps[k],lno);
          lno++;
        }
      }
    }
  }

  for(i=0;i<lno;i++){
    printf("\nx: %f y: %f slope: %f\n",lines[i].pt.x,lines[i].pt.y,lines[i].slope);
  }
}

float slope(struct point pt1,struct point pt2){
  if(pt1.x==pt2.x){
    float slp=INFINITY;
    return slp;
  }else{
    float slp=(pt2.y-pt1.y)/(pt2.x-pt1.x);
    return slp;
  }
}

void merge(float arr[],int l,int m,int r){
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;

  float L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=arr[l+i];
  }
  for(j=0;j<n2;j++){
    R[j]=arr[m+1+j];
  }

  i=0;
  j=0;
  k=l;
  while(i<n1 && j<n2){
    if(L[i]>R[j]){
      arr[k]=R[j];
      j++;
      k++;
    }else if(L[i]<R[j]){
      arr[k]=L[i];
      i++;
      k++;
    }else{
      arr[k]=L[i];
      i++;
      k++;
    }
  }
  while(i<n1){
    arr[k]=L[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k]=R[j];
    j++;
    k++;
  }
}

void mergesort(float arr[],int l,int r){
  if(l<r){
    int m=l+(r-l)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

void printArray(float arr[],int arr_size){
  int i;
  printf("\n");
  for(i=0;i<arr_size;i++){
    printf(" %f ",arr[i]);
  }
  printf("\n");
}

void pushInLines(struct point pt,float slope,int lno){
  lines[lno].pt=pt;
  lines[lno].slope=slope;
}

int findInLines(struct point pt,float slp,int lno){
  int m;
  float tempSlp;
  for(m=0;m<lno;m++){
    if(lines[m].slope==slp){
      if(lines[m].pt.x==pt.x && lines[m].pt.y==pt.y){
        return 1;
      }
      tempSlp=slope(pt,lines[m].pt);
      if(tempSlp==slp){
        return 1;
      }
    }
  }
  return 0;
}
