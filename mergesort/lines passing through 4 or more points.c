/*
    The problem. Given a set of n distinct points in the plane, find every (maximal)
    line segment that connects a subset of 4 or more of the points.

    Performance requirement. The order of growth of the running time of your program
    should be n4 in the worst case and it should use space proportional to n
    plus the number of line segments returned.

    @author Mayank Chhipa(mgroovyank)
*/
#include<stdio.h>
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
void pushInLines(struct point pt,float slope,int lno);
int findInLines(struct point pt,float slp,int lno);
int main(){
  struct point points[10];
  int i,j,k,lno=0,count,fndLine;
  float slp;
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
    for(j=0;j<10;j++){
      count=2;
      if(i==j){
        continue;
      }else{
        slp=slope(points[i],points[j]);
        fndLine=findInLines(points[i],slp,lno);
        if(fndLine==1){
          continue;
        }
      }
      for(k=0;k<10;k++){
        if(k==i || k==j){
          continue;
        }else{
          if(slope(points[i],points[k])==slp){
            count++;
          }
        }
      }
      if(count>=4){
        pushInLines(points[i],slp,lno);
        printf("\n i= %d ,j = %d\n",i,j);
        lno++;
      }
    }
  }
  for(i=0;i<lno;i++){
    printf("x: %f y: %f slope: %f",lines[i].pt.x,lines[i].pt.y,lines[i].slope);
    printf("\n");
  }
  printf("%d",lno);
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

