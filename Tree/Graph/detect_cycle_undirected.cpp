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
        adj[v].push_back(u);
    }

    bool dfs(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited))
                    return true;
            }
            else if (neighbor != parent) {
                return true; // Cycle found
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0); // Creates cycle
    g.addEdge(2,3);

    if (g.hasCycle())
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
