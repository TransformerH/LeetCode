// DFS - time limited one :(
void findPath(vector<vector<int>>& grid, int i, int j, int len, int& shortest){
    if(i >= grid.size() - 1 && j >= grid[0].size() - 1){
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
            len += grid[i][j];
        if(len < shortest)
            shortest = len;
        return;
    }
    len += grid[i][j];
    if(i < grid.size() -1){
        findPath(grid, i+1, j, len, shortest);
    }
    if(j < grid[0].size() - 1){
        findPath(grid, i, j+1, len, shortest);
    }
}

int minPathSum(vector<vector<int>>& grid) {
    if(grid.size() == 0)
        return 0;
    int res = INT_MAX;
    int len = 0;
    findPath(grid, 0, 0, len, res);
    return res;
}

// solution - DP

int minPathSum(vector<vector<int>>& grid) {
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));
    
    for(int i = 1; i < m; i++)
        sum[i][0] = sum[i-1][0] + grid[i][0];
    
    for(int j = 1; j < n; j++)
        sum[0][j] = sum[0][j-1] + grid[0][j];
    
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
    
    return sum[m-1][n-1];
}