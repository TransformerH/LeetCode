// dp

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    
    vector<vector<int>> square(m, vector<int>(n, 0));
    int maxSize = 0;
    for(int i = 0; i < m; i++){
        square[i][0] = matrix[i][0] - '0';
        maxSize = max(maxSize, square[i][0]);
    }
    for(int j = 0; j < n; j++){
        square[0][j] = matrix[0][j] - '0';
        maxSize = max(maxSize, square[0][j]);
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            square[i][j] = (matrix[i][j] - '0' == 0) ? 0 : min(min(square[i-1][j], square[i][j-1]), square[i-1][j-1])+1;
            maxSize = max(maxSize, square[i][j]);
        }
    }
    return maxSize * maxSize;
}