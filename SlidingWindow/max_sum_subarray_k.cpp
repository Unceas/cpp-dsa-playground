#include <bits/stdc++.h>
using namespace std;

// Max Sum Subarray of size k
int maxSum(vector<int>& nums, int k) {

    int windowSum = 0;

    for(int i=0;i<k;i++)
        windowSum += nums[i];

    int maxSum = windowSum;

    for(int i=k;i<nums.size();i++) {
        windowSum += nums[i] - nums[i-k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {

    vector<int> nums = {2,1,5,1,3,2};
    int k = 3;

    cout << "Max Sum: " << maxSum(nums, k);

    return 0;
}
