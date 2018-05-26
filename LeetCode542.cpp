// BFS 
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    queue<pair<int, int>> mq;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0)
                mq.push(make_pair(i, j));
            else
                matrix[i][j] = INT_MAX;
        }
    }
    vector<pair<int, int>> directions;
    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(0, 1));
    directions.push_back(make_pair(0, -1));
    
    while(!mq.empty()){
        auto top = mq.front();
        mq.pop();
        for(auto dire : directions){
            int curi = top.first + dire.first;
            int curj = top.second + dire.second;
            if(curi < 0 || curi >= matrix.size() || curj < 0 || curj >= matrix[0].size() || matrix[curi][curj] < matrix[top.first][top.second] + 1)
                continue;
            matrix[curi][curj] = matrix[top.first][top.second] + 1;
            mq.push(make_pair(curi, curj));
        }
    }
    
    return matrix;
}