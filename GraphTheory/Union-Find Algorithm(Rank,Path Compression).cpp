#include <iostream>
#include <cstring>
using namespace std;
class Subset{
  public:
  int parent;
  int rank;
};
class Edge{
  public:
  int src,dest;
};
class Graph{
  public:
  int v,e;
  Edge *edge;
};
Graph* createGraph(int v,int e){
  Graph* graph = new Graph();
  graph->v=v;
  graph->e=e;
  graph->edge=new Edge[graph->e * sizeof(Edge)];
  return graph;
}
int find(Subset *subsets,int node){
  if(subsets[node].parent!=node){
    subsets[node].parent=find(subsets,subsets[node].parent);
  }
  return subsets[node].parent;
}
void younion(Subset *subsets,int x,int y){
  int xset=find(subsets,x);
  int yset=find(subsets,y);
  if(subsets[xset].rank>subsets[yset].rank){
    subsets[yset].parent=xset;
  }else if(subsets[xset].rank<subsets[yset].rank){
    subsets[xset].parent=yset;
  }else{
    subsets[yset].parent=xset;
    subsets[xset].rank++; 
  }
}
bool isCycle(Graph *graph){
  Subset *subsets=new Subset[graph->v*sizeof(Subset)];
  for(int i=0;i<graph->v;i++){
    subsets[i].parent=i;
    subsets[i].rank=0;
  }
  for(int i=0;i<graph->e;i++){
    int x=find(subsets,graph->edge[i].src);
    int y=find(subsets,graph->edge[i].dest);
    if(x==y){
      return true;
    }
    younion(subsets,x,y);
  }
  return false;
}
int main(){
  int v=3,e=3;
  Graph *graph=createGraph(v,e);
  graph->edge[0].src=0;
  graph->edge[0].dest = 1; 
  graph->edge[1].src = 1; 
  graph->edge[1].dest = 2;  
  graph->edge[2].src = 0;  
  graph->edge[2].dest = 2;  

  if(isCycle(graph)){
    cout<<"graph contains cycle";
  }else{
    cout<<"graph doesn't contain cycle";
  }
  return 0;
}
