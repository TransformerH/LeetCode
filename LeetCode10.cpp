bool isMatch(string s, string p) {
    int slen = (int)s.length();
    int plen = (int)p.length();
    vector<vector<bool>> dp(slen+1, vector<bool>(plen+1,false));
    dp[0][0] = true;
    for(int j = 1; j <= plen; j++){
        // the * must follow a letter.
        dp[0][j] = j > 1 && p[j-1] == '*' && dp[0][j-2];
    }
    for(int i = 1; i <= slen; i++){
        for(int j = 1; j <= plen; j++){
            if(p[j-1] != '*')
                dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '.');
            else
                //dp[i][j-2] : s[i-1] == p[j-3]  s: asd p: asp*d
                //(s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j] equals to s[i-2] == p[j-2] && s[i-2] == p[j-1]
                dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
        }
    }
    return dp[slen][plen];
}