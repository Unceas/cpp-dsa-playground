#include <bits/stdc++.h>
using namespace std;

// Lower Bound: first index where element >= target
int lowerBound(vector<int>& nums, int target) {

    int left = 0, right = nums.size();

    while(left < right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// Upper Bound: first index where element > target
int upperBound(vector<int>& nums, int target) {

    int left = 0, right = nums.size();

    while(left < right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {

    vector<int> nums = {1,2,2,2,3,4};

    int target = 2;

    cout << "Lower Bound: " << lowerBound(nums, target) << endl;
    cout << "Upper Bound: " << upperBound(nums, target) << endl;

    return 0;
}

// Time Complexity: O(log n)
