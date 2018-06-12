// time exceeded
int getPalindrome(string s, int i, int j){
    if(i > j)
        return 0;
    if(i == j)
        return 1;
    if(s[i] == s[j])
        return 2 + getPalindrome(s, i+1, j-1);
    else
        return max(getPalindrome(s, i+1, j), getPalindrome(s, i, j-1));
}

int longestPalindromeSubseq(string s) {
    return getPalindrome(s, 0, s.length()-1);
}

// another dp solution
int longestPalindromeSubseq(string s) {
    int len = (int)s.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    // because dp[i][j] = 2 + dp[i+1][j-1]
    // dp[i][j] =  max(dp[i+1][j], dp[i][j-1])
    // i begin from len-1 but not from 0
    for(int i = len-1; i >= 0; i--){
        dp[i][i] = 1;
        for(int j = i+1; j < len; j++){
            if(s[i] == s[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][len-1];
}

