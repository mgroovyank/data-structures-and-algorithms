#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int root(int a,int id[]);
void idnsz(int a,int b,int id[],int sz[]);
int main(){
int grid[5][5],id[27],sz[27],i,j,x,y,m=0,n=4,a;
int count=0;
double p;
for(i=0;i<27;i++){
    id[i]=i;
    sz[i]=1;
}
for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            grid[i][j]=0;
}
}
srand(time(0));
do{
    x=(rand()%(n-m+1))+m;
    y=(rand()%(n-m+1))+m;
    a=5*x+y+1;
    if(grid[x][y]==0){
            grid[x][y]=1;
            count++;
            
        if(x==0){
            idnsz(0,a,id,sz);
            if(grid[x+1][y]==1){
              idnsz(a,a+5,id,sz);
            }
        }else if(x==4){
            idnsz(26,a,id,sz);
            if(grid[x-1][y]==1){
              idnsz(a,a-5,id,sz);
            }
        }else if(y!=4 && y!=0){
            if(grid[x-1][y]==1){
                idnsz(a,a-5,id,sz);
            }
            if(grid[x+1][y]==1){
                idnsz(a,a+5,id,sz);
            }
            if(grid[x][y-1]==1){
                idnsz(a,a-1,id,sz);
            }
            if(grid[x][y+1]==1){
                idnsz(a,a+1,id,sz);
            }
        }
        if(y==0 && x!=0 && x!=4){
          if(grid[x-1][y]==1){
                idnsz(a,a-5,id,sz);
            }
            if(grid[x+1][y]==1){
                idnsz(a,a+5,id,sz);
            }
            if(grid[x][y+1]==1){
                idnsz(a,a+1,id,sz);
            }
        }else if(y==4 && x!=0 && x!=4){
          if(grid[x-1][y]==1){
                idnsz(a,a-5,id,sz);
            }
            if(grid[x+1][y]==1){
                idnsz(a,a+5,id,sz);
            }
            if(grid[x][y-1]==1){
                idnsz(a,a-1,id,sz);
            }
        }
    }
    if(root(0,id)==root(26,id)){
      printf("percolation is done\n");
      p=count/25.00;
      printf("the threshold probablity is %lf",p);

    }else{
        printf("percolation not done");
    }
    }while(root(0,id)!=root(26,id));
    }
int root(int a,int id[]){
    if(a==id[a]){
       return a;
     }else{
       return root(id[a],id);
     }
  }
void idnsz(int a,int b,int id[],int sz[]){
      int rootA=root(a,id);
      int rootB=root(b,id);
      if(sz[rootA]>sz[rootB]){
            id[rootB]=id[rootA];
            sz[rootA]+=sz[rootB];
      }else if(sz[rootA]<sz[rootB]){
          id[rootA]=id[rootB];
          sz[rootB]+=sz[rootA];
          }else{
              id[rootB]=id[rootA];
              sz[rootA]+=sz[rootB];
              }
  }
