#include <bits/stdc++.h>
using namespace std;

// Longest subarray with sum = k (positive integers)
int longestSubarray(vector<int>& nums, int k) {

    int left = 0, sum = 0, maxLen = 0;

    for(int right = 0; right < nums.size(); right++) {

        sum += nums[right];

        while(sum > k) {
            sum -= nums[left];
            left++;
        }

        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

int main() {

    vector<int> nums = {1,2,1,1,1,3,2};
    int k = 3;

    cout << "Longest Length: " << longestSubarray(nums, k);

    return 0;
}

// Time Complexity: O(n)
