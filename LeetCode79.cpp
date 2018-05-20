bool findWord(vector<vector<char>>& board, string word, int wordIndex,int i, int j){
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '\0'|| wordIndex >= word.length()|| word[wordIndex] != board[i][j])
        return false;
    if(wordIndex + 1 == word.length() )
        return true;
    char temp = board[i][j];
    board[i][j] = '\0';
    if(findWord(board, word, wordIndex + 1, i + 1, j) || findWord(board, word, wordIndex + 1, i - 1, j) || findWord(board, word, wordIndex + 1, i, j + 1) || findWord(board, word, wordIndex + 1, i, j - 1))
        return true;
    board[i][j] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[i].size(); j++){
            if(findWord(board, word, 0, i, j))
                return true;
        }
    return false;
}

