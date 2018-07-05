/*
About dynamic programming:
At every step, what we need to do is just to think about whether the last step compliances with the rules.

the dp table dp[i][j]: one value corresponds to two variables.
*/

int minCut(string s) {
    int len = (int)s.length();
        if(len == 0)
            return 0;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    vector<int>cut(len, 0);
    for(int i = len-1; i >= 0; i--){
        cut[i] = len - 1 - i;
        for(int j = i; j < len; j++){
        	// the order of j - i < 2 and dp[i+1][j-1] can not be changed
            if(s[i] == s[j] && (j - i < 2 || dp[i+1][j-1])){
                dp[i][j] = true;
                // there is no cut inside the current substring
                if(j == len-1)
                    cut[i] = 0;
                // cut[j+1] is the number of cuts which are inside the current substring
                // cut[i] is a new cut based on the cut[j+1]
                else if(cut[i] > cut[j+1] + 1)
                    cut[i] = cut[j+1] + 1;
            }
        }
    }
    return cut[0];
}