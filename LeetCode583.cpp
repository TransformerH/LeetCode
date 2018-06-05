// dp
int minDistance(string word1, string word2) {
    int len1 = (int)word1.length();
    int len2 = (int)word2.length();
    if(len1 == 0 || len2 == 0)
        return len1 > len2 ? len1 : len2;
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
        
    return (len1 + len2 - 2 * dp[len1][len2]);
}


