#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

void floydWarshall(vector<vector<int>>& dist, int V) {

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }
}

int main() {

    int V = 4;

    vector<vector<int>> dist = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(dist, V);

    cout << "Shortest distance matrix:\n";

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){

            if(dist[i][j]==INF)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// Time Complexity: O(V^3)
// Space Complexity: O(V^2)
