void setZeroes(vector<vector<int>>& matrix) {
    set<int> zeroi;
    set<int> zeroj;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                zeroi.insert(i);
                zeroj.insert(j);
            }
        }
    }
    for(set<int>::iterator it = zeroi.begin(); it != zeroi.end(); it++){
        for(int j = 0; j < matrix[*it].size(); j++)
            matrix[*it][j] = 0;
    }
    
    for(set<int>::iterator it = zeroj.begin(); it != zeroj.end(); it++){
        for(int i = 0; i < matrix.size(); i++)
            matrix[i][*it] = 0;
    }
}