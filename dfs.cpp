#include<bits/stdc++.h>
using namespace std;
#define N 100

int visited[N];

void dfs(vector<int> graph[], int node) {
  if(visited[node] == 1)
    return;

  // Else
  visited[node]=1;
  cout<<node<<" ";
  for(int i=0;i<graph[node].size();i++) {
    dfs(graph, graph[node][i]);
  }
}

void initialize() {
  for(int i=1;i<=5;i++)
    visited[i]=0;
}

int main() {

  // Making a graph(number of nodes = 5) using adjacency list
  vector<int> graph[6];
  graph[1].push_back(2);
  graph[1].push_back(4);
  graph[2].push_back(1);
  graph[2].push_back(3);
  graph[2].push_back(5);
  graph[3].push_back(2);
  graph[3].push_back(5);
  graph[4].push_back(1);
  graph[5].push_back(2);
  graph[5].push_back(3);

  // Initially no node is visited
  initialize();

  dfs(graph,1);

  return 0;
}
