int numDistinct(string s, string t) {
        int ts = t.length();
        int ss = s.length();
        vector<vector<int>> dp(ts+1, vector<int>(ss+1, 0));
        for(int i = 0; i <= ss; i++)
            dp[0][i] = 1;
        for(int i = 1; i <= ts; i++){
            for(int j = 1; j <= ss; j++){
                if(t[i-1] == s[j-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[ts][ss];
    }