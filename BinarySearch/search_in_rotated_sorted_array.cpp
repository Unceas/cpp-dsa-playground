#include <bits/stdc++.h>
using namespace std;

// Search in Rotated Sorted Array
int search(vector<int>& nums, int target) {

    int left = 0, right = nums.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        // left half sorted
        if (nums[left] <= nums[mid]) {

            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else { // right half sorted

            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << "Index: " << search(nums, target);

    return 0;
}

// Time Complexity: O(log n)
