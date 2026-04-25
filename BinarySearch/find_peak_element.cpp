#include <bits/stdc++.h>
using namespace std;

// Find Peak Element
int findPeak(vector<int>& nums) {

    int left = 0, right = nums.size() - 1;

    while(left < right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] < nums[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {

    vector<int> nums = {1,2,1,3,5,6,4};

    cout << "Peak Index: " << findPeak(nums);

    return 0;
}
