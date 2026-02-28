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
        // Directed edge u -> v
        adj[u].push_back(v);
    }

    void dfs(int node, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, st);
            }
        }

        // Push after exploring all neighbors (post-order)
        st.push(node);
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, st);
            }
        }

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << '\n';
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

    cout << "Topological Sort: ";
    g.topologicalSort();

    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
