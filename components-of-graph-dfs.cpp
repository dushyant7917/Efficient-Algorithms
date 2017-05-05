// Program to find number of disconnected parts in graph
#include <vector>
#include <iostream>

using namespace std;


void dfs(int node, int visited[], vector<int> graph[]) {
    visited[node] = 1;
    for(int i = 0; i < graph[node].size(); i++)    {
        if(visited[graph[node][i]] == 0)
            dfs(graph[node][i], visited, graph);
    }
}

int num_connections(int n, vector<int> graph[]) {
    int visited[n + 1];
    for(int i = 0; i <= n; i++) {
        visited[i] = 0;
    }

    int cc = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i, visited, graph);
            cc++;
        }
    }

    return cc;
}


int main() {
    int n, m;
    // Number of nodes and edges respectively
    cin >> n >> m;

    vector<int> graph[n + 1];

    for(int j = 0; j < m; j++) {
        int v1, v2;
        // Vertices of edges
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << num_connections(n, graph) << endl;

    return 0;
}
