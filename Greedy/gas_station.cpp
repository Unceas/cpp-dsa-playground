#include <bits/stdc++.h>
using namespace std;

// Gas Station Problem
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int total = 0, curr = 0, start = 0;

    for(int i = 0; i < gas.size(); i++) {

        int diff = gas[i] - cost[i];

        total += diff;
        curr += diff;

        if(curr < 0) {
            start = i + 1;
            curr = 0;
        }
    }

    return (total >= 0) ? start : -1;
}

int main() {

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << "Start Index: "
         << canCompleteCircuit(gas, cost);

    return 0;
}
