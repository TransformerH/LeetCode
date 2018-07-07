// same like lc10
//dp
// dp: the result of the current subproblem can represent the result of previous subproblem.
bool isMatch(string s, string p) {
    int slen = (int)s.length();
    int plen = (int)p.length();
    vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
    dp[0][0] = true;
    for(int j = 1; j <= plen; j++)
        dp[0][j] = p[j-1] == '*' && dp[0][j-1];
    for(int i = 1; i <= slen; i++){
        for(int j = 1; j <= plen; j++){
            if(p[j-1] != '*')
                dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '?');
            else {
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    
    return dp[slen][plen];
}