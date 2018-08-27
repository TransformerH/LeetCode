 vector<vector<int>> generateMatrix(int n) {
    vector<int> row = vector<int>(n);
    vector<vector<int>> result = vector<vector<int>>(n, row);
    int val = 0;
    for(int index = 0; index < n; index++){
        for(int j1 = index; j1 <= (n-1-index); j1++){
            val++;
            result[index][j1] = val;
        }
        for(int i1 = index+1; i1 <= (n-1-index); i1++){
            val++;
            result[i1][n-1-index] = val;
        }
        for(int j2 = n-1-(index+1); j2 >= index; j2--){
            val++;
            result[n-1-index][j2] = val;
        }
        for(int i3 = n-1-(index+1); i3 >= index+1; i3--){
            val++;
            result[i3][index] = val;
        }
    }
    return result;
}