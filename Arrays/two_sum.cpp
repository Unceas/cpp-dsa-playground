#include <bits/stdc++.h>
using namespace std;

// Two Sum using Hash Map
// Finds indices of two numbers whose sum equals target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
        cout << result[0] << " " << result[1];
    else
        cout << "No solution found";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
