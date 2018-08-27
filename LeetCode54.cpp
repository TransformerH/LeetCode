vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return res;
    int rowBegin = 0;
    int rowEnd = (int)matrix.size() - 1;
    int colBegin = 0;
    int colEnd = (int)matrix[0].size() - 1;
    while(rowBegin <= rowEnd && colBegin <= colEnd){
        for(int j = colBegin; j <= colEnd; j++)
            res.push_back(matrix[rowBegin][j]);
        rowBegin++;
        for(int i = rowBegin; i <= rowEnd; i++)
            res.push_back(matrix[i][colEnd]);
        colEnd--;
        
        if(rowBegin <= rowEnd){
            for(int j = colEnd; j >= colBegin; j--)
                res.push_back(matrix[rowEnd][j]);
        }
        rowEnd--;
        
        if(colBegin <= colEnd){
            for(int i = rowEnd; i >= rowBegin; i--)
                res.push_back(matrix[i][colBegin]);
        }
        colBegin++;
    }
    return res;
}

