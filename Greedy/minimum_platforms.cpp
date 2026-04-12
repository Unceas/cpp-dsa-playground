#include <bits/stdc++.h>
using namespace std;

// Minimum Platforms Required
int findPlatforms(vector<int>& arr, vector<int>& dep) {

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    int n = arr.size();

    while(i < n && j < n) {

        if(arr[i] <= dep[j]) {
            platforms++;
            i++;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        else {
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {

    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum Platforms Needed: "
         << findPlatforms(arrival, departure);

    return 0;
}

// Time Complexity: O(n log n)
