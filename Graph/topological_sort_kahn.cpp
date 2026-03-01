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
        adj[u].push_back(v); // Directed graph
    }

    void kahnTopologicalSort() {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
            for (int neighbor : adj[i])
                indegree[neighbor]++;

        queue<int> q;

        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort (Kahn): ";
    g.kahnTopologicalSort();

    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
