#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm using priority queue
class Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto neighbor : adj[node]) {
                int next = neighbor.first;
                int weight = neighbor.second;

                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        cout << "Shortest distances from source:\n";
        for (int i = 0; i < V; i++)
            cout << i << " -> " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(2,1,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,5);
    g.addEdge(3,4,3);

    g.dijkstra(0);

    return 0;
}

// Time Complexity: O((V + E) log V)
