#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax edges V-1 times
        for (int i = 1; i < V; i++) {
            for (auto e : edges) {
                if (dist[e.u] != INT_MAX &&
                    dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        // Check negative cycle
        for (auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.w < dist[e.v]) {
                cout << "Negative cycle detected\n";
                return;
            }
        }

        cout << "Shortest distances:\n";
        for (int i = 0; i < V; i++)
            cout << i << " -> " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);

    g.bellmanFord(0);

    return 0;
}

// Time Complexity: O(V * E)
