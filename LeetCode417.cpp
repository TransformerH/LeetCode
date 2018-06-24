void bfs(queue<pair<int, int>>& ocean, vector<vector<bool>>& continent, vector<vector<int>>& matrix){
    vector<pair<int, int>> directs;
    directs.push_back(make_pair(1, 0));
    directs.push_back(make_pair(-1, 0));
    directs.push_back(make_pair(0, 1));
    directs.push_back(make_pair(0, -1));
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    while (!ocean.empty()) {
        auto top = ocean.front();
        ocean.pop();
        for(auto direct : directs){
            int x = top.first + direct.first;
            int y = top.second + direct.second;
            if(x < 0 || x >= m || y < 0 || y >= n || continent[x][y] || matrix[x][y] < matrix[top.first][top.second])
                continue;
            continent[x][y] = true;
            ocean.push(make_pair(x, y));
        }
    }
}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> res;
    
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return res;
    
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
   
    queue<pair<int, int>> pq;
    queue<pair<int, int>> aq;
    for(int i = 0; i < m; i++){
        pq.push(make_pair(i, 0));
        pacific[i][0] = true;
        aq.push(make_pair(i, n-1));
        atlantic[i][n-1] = true;
    }
    for(int j = 0; j < n; j++){
        pq.push(make_pair(0, j));
        pacific[0][j] = true;
        aq.push(make_pair(m-1, j));
        atlantic[m-1][j] = true;
    }
    
    bfs(pq, pacific, matrix);
    bfs(aq, atlantic, matrix);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(pacific[i][j] && atlantic[i][j])
                res.push_back(make_pair(i, j));
        }
    }
    
    return res;
}
