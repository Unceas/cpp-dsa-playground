#include <bits/stdc++.h>
using namespace std;

// Structure to store value + array index + element index
struct Node {
    int value;
    int arrIndex;
    int elemIndex;

    bool operator>(const Node& other) const {
        return value > other.value;
    }
};

vector<int> mergeKArrays(vector<vector<int>>& arrays) {

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    int k = arrays.size();

    // Push first element of each array
    for(int i = 0; i < k; i++) {
        if(!arrays[i].empty()) {
            pq.push({arrays[i][0], i, 0});
        }
    }

    vector<int> result;

    while(!pq.empty()) {

        Node curr = pq.top();
        pq.pop();

        result.push_back(curr.value);

        int i = curr.arrIndex;
        int j = curr.elemIndex;

        // Push next element from same array
        if(j + 1 < arrays[i].size()) {
            pq.push({arrays[i][j + 1], i, j + 1});
        }
    }

    return result;
}

int main() {

    vector<vector<int>> arrays = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    vector<int> merged = mergeKArrays(arrays);

    for(int x : merged)
        cout << x << " ";

    return 0;
}

// Time Complexity: O(N log K)
// N = total elements, K = number of arrays
