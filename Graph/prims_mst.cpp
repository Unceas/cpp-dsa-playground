#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void primMST() {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        pq.push({0,0});
        key[0] = 0;

        int total = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if(inMST[u]) continue;

            inMST[u] = true;
            total += key[u];

            for(auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if(!inMST[v] && w < key[v]) {
                    key[v] = w;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "Total MST weight: " << total;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);
    g.addEdge(3,4,9);

    g.primMST();

    return 0;
}

// Time Complexity: O(E log V)
