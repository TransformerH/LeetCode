int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(string s : strs){
        int sm = 0, sn = 0;
        for(char c : s){
            if(c == '0')
                sm++;
            else
                sn++;
        }
        // top-down
        // the value of dp[i][j] will change if a new string from strs is added
        /* 
            when the new string is added, the sizes of i , j which are smaller or equal to m, n 
            should be judged again.
        */
        /*
         top-down is reflected in dp[i][j], dp[i-sm][j-sn]...
         bottom-up is dp[i][j], dp[i+sm][j+sn]...
         the final result must be stored in dp[m][n] and top-down can ensure it
        */
        for(int i = m; i >= sm; i--){
            for(int j = n; j >= sn; j--){
                dp[i][j] = max(dp[i][j], dp[i-sm][j-sn]+1);
            }
        }
    }
    return dp[m][n];
}