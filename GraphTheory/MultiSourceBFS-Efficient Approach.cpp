#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define N 100000+1
#define inf 1000000
int source[N];
int dist[N];
set<pair<int,int> > q;
void multiSourceBFSUtil(vector<int> graph[],int s){
  set<pair<int, int> >::iterator it;
  int i;
  for(i=0;i<graph[s].size();i++){
    int v=graph[s][i];
    if(dist[s]+1<dist[v]){
      it=q.find(make_pair(dist[v],v));
      q.erase(it);
      dist[v]=dist[s]+1;
      q.insert(make_pair(dist[v],v));
    }
  }
  if(q.size()==0){
    return;
  }
  it=q.begin();
  int next=it->second;
  q.erase(it);
  multiSourceBFSUtil(graph,next);
}
void multiSourceBFS(vector<int> graph[],int n,int sources[],int s){
  for(int i=1;i<=n;i++){
    source[i]=0;
  }
  for(int i=0;i<s;i++){
    source[sources[i]]=1;
  }
  for(int i=1;i<=n;i++){
    if(source[i]){
      dist[i]=0;
      q.insert(make_pair(0,i));
    }else{
      dist[i]=inf;
      q.insert(make_pair(inf,i));
    }
  }
  set<pair<int, int> >::iterator itr; 
  itr=q.begin(); 
  int start=itr->second;
  multiSourceBFSUtil(graph,start);
  for(int i=1;i<= n;i++){
    cout<<i<<" "<<dist[i]<<"\n";
  }  
}
void addEdge(vector<int> graph[], int u, int v){ 
  graph[u].push_back(v); 
  graph[v].push_back(u); 
} 
int main(){
  int n=6;
  vector<int> graph[n + 1]; 
  addEdge(graph, 1, 2); 
  addEdge(graph, 1, 6); 
  addEdge(graph, 2, 6); 
  addEdge(graph, 2, 3); 
  addEdge(graph, 3, 6); 
  addEdge(graph, 5, 4); 
  addEdge(graph, 6, 5); 
  addEdge(graph, 3, 4); 
  addEdge(graph, 5, 3); 

  int sources[]={1,5};
  int s=2;//size of sources
  multiSourceBFS(graph,n,sources,s);
}
