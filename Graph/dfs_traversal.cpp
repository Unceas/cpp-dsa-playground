#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void dfs(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfs(neighbor, visited);
        }
    }

    void startDFS(int start) {
        vector<bool> visited(V, false);
        dfs(start, visited);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);

    cout << "DFS Traversal: ";
    g.startDFS(0);

    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
