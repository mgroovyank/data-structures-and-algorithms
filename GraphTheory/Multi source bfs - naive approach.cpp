#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 100000+1
int source[N];
int visited[N];
int dist[N];
void bfs(vector<int> graph[],int start){
  queue<pair<int,int> > q;
  q.push(make_pair(start,0));
  while(!q.empty()){
    int t,d;
    t=q.front().first;
    d=q.front().second;
    visited[t]=1;
    q.pop();
    if(source[t]==1){
      dist[start]=d;
      return;
    }
    for(int i=0;i<graph[t].size();i++){
      if(visited[graph[t][i]]==0){
        q.push(make_pair(graph[t][i], d+1 ));
      }
    }
  }  
}
void nearestTown(vector<int> graph[],int n,int sources[], int s){
  for(int i=1;i<=n;i++){
    source[i]=0;
  }
  for(int i=0;i<s;i++){
    source[sources[i]]=1;
  }
  for(int i=1;i<=n;i++){
    for(int i=1;i<=n;i++){
      visited[i]=0;
    }
    cout<<"\n"<<i<<"\n";
    bfs(graph,i);
  }
  for(int i=1;i<=n;i++){
    cout<<i<<" "<<dist[i]<<"\n";
  } 
}
void addEdge(vector<int> graph[],int u,int v){
  graph[u].push_back(v);
  graph[v].push_back(u);
}
int main(){
  int n=6;
  vector<int> graph[n+1];
  addEdge(graph,1,2);
  addEdge(graph,1,6);
  addEdge(graph,2,6);
  addEdge(graph,2,3);
  addEdge(graph,3,6);
  addEdge(graph,5,4);
  addEdge(graph,6,5);
  addEdge(graph,3,4);
  addEdge(graph,5,3);

  int sources[]={1,5};
  int s=2;//size of source[]
  nearestTown(graph,n,sources,s);
}
