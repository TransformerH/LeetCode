  int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len+1, 0);
        dp[len] = 1;
        dp[len-1] = s[len-1] - '0' == 0 ? 0 : 1;
        for(int i = len-2; i >= 0; i--){
            if(s[i] == '0')
                continue;
            int sub = stoi(s.substr(i, 2));
            dp[i] = ( sub <= 26 && sub >= 1) ? dp[i+1] + dp[i+2] : dp[i+1];
        }
        return dp[0];
    }