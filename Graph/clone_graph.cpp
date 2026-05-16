#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int _val) {
        val = _val;
    }
};

// Clone Graph
class Solution {

    unordered_map<Node*, Node*> mp;

public:

    Node* cloneGraph(Node* node) {

        if(!node)
            return NULL;

        if(mp.count(node))
            return mp[node];

        Node* copy = new Node(node->val);

        mp[node] = copy;

        for(Node* nei : node->neighbors) {
            copy->neighbors.push_back(
                cloneGraph(nei)
            );
        }

        return copy;
    }
};

int main() {

    cout << "Graph cloning implemented.";

    return 0;
}
