#include<bits/stdc++.h>
using namespace std;
#define N 100

int visited[N];

void bfs(vector<int> graph[], int node) {
  queue<int> q;
  visited[node]=1;
  q.push(node);

  while(q.empty()==false) {
    node=q.front();
    cout<<node<<" ";
    q.pop();

    for(int i=0;i<graph[node].size();i++) {
      if(visited[graph[node][i]]==0) {
        visited[graph[node][i]]=1;
        q.push(graph[node][i]);
      }
    }
  }
}

void initialize() {
  for(int i=1;i<=5;i++)
    visited[i]=0;
}

int main() {

  // Making a graph(number of nodes = 5) using adjacency list
  vector<int> graph[7];
  graph[1].push_back(2);
  graph[1].push_back(4);
  graph[2].push_back(3);
  graph[2].push_back(5);
  graph[3].push_back(2);
  graph[3].push_back(6);
  graph[4].push_back(1);
  graph[5].push_back(2);
  graph[5].push_back(6);
  graph[6].push_back(3);
  graph[6].push_back(5);

  // Initially no node is visited
  initialize();

  bfs(graph,1);

  return 0;
}
