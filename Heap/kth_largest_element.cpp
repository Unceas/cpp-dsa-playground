#include <bits/stdc++.h>
using namespace std;

// Kth Largest Element using Min Heap
int findKthLargest(vector<int>& nums, int k) {

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int num : nums) {
        pq.push(num);

        if(pq.size() > k)
            pq.pop();
    }

    return pq.top();
}

int main() {

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << "Kth Largest: " << findKthLargest(nums, k);

    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
