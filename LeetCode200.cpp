int numIslands(vector<vector<char>>& grid) {
    int num = 0;
    if(grid.size() == 0)
        return num;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    stack<pair<int, int>> gridStack;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                num++;
                gridStack.push(make_pair(i, j));
                while(!gridStack.empty()){
                    auto node = gridStack.top();
                    gridStack.pop();
                    int curi = node.first;
                    int curj = node.second;
                    visited[curi][curj] = true;
                    if(curi + 1 < grid.size() && grid[curi + 1][curj] == '1' && !visited[curi+1][curj]) gridStack.push(make_pair(curi + 1, curj));
                    if(curj + 1 < grid[0].size() && grid[curi][curj + 1] == '1' && !visited[curi][curj + 1])gridStack.push(make_pair(curi, curj + 1));
                    if(curi - 1 >= 0 && grid[curi - 1][curj] == '1' && !visited[curi - 1][curj])gridStack.push(make_pair(curi - 1, curj));
                    if(curj - 1 >= 0 && grid[curi][curj - 1] == '1' && !visited[curi][curj - 1])gridStack.push(make_pair(curi, curj - 1));
                }
            }
        }
    }
    
    return num;
}
