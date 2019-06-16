#include <iostream>
#include <cstring>
using namespace std;
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
int find(int parent[],int node){
  if(parent[node]==-1){
    return node;
  }
  return find(parent,parent[node]);
}
void younion(int parent[],int x,int y){
  int xset=find(parent,x);
  int yset=find(parent,y);
  if(xset!=yset){
    parent[xset]=yset;
  }
}
bool isCycle(Graph *graph){
  int parent[graph->v];
  memset(parent,-1,sizeof(parent));
  for(int i=0;i<graph->e;i++){
    int x=find(parent,graph->edge[i].src);
    int y=find(parent,graph->edge[i].dest);
    if(x==y){
      return true;
    }
    younion(parent,x,y);
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
