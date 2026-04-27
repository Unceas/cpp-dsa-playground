#include <bits/stdc++.h>
using namespace std;

// Search in 2D Matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0, right = m*n - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        int val = matrix[mid / n][mid % n];

        if(val == target)
            return true;
        else if(val < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {

    vector<vector<int>> matrix = {
        {1,3,5},
        {7,9,11},
        {13,15,17}
    };

    int target = 9;

    cout << (searchMatrix(matrix, target) ? "Found" : "Not Found");

    return 0;
}
