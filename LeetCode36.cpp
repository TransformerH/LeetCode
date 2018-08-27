 // 未审题
// only the filled cells need to be validated
 bool isValidSudoku(vector<vector<char>>& board) {
        int len = board.size();
        vector<vector<bool>> row(len, vector<bool>(9, false));
        vector<vector<bool>> column(len, vector<bool>(9, false));
        vector<vector<bool>> square(9, vector<bool>(9, false));
        
        for(int i = 0; i < len; i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0'-1;
                    int sq = i/3*3 + j/3;
                    if(row[i][num] || column[j][num] || square[sq][num])
                        return false;
                    row[i][num] = column[j][num] = square[sq][num] = true;
                }
            }
        }
        
        return true;
    }