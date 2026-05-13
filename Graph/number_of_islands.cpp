#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {

    int m = grid.size();
    int n = grid[0].size();

    if(r < 0 || c < 0 || r >= m || c >= n ||
       grid[r][c] == '0')
        return;

    grid[r][c] = '0';

    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int numIslands(vector<vector<char>>& grid) {

    int count = 0;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {

            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main() {

    vector<vector<char>> grid = {
        {'1','1','0','0'},
        {'1','0','0','1'},
        {'0','0','1','1'},
        {'0','0','0','0'}
    };

    cout << numIslands(grid);

    return 0;
}
