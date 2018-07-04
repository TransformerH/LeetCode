// dp
/*
 Because s3 is composed by s1 and s2 which are sequences with original order,
 when s1 or s2 current position char is equal to s3 correct position char,
 we should check if the s1 or s2 previous position char is in s3.
 The corresponding code is
 dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1])
 */
/*
 If the dp problem can be translated into a matrix, the problem should be considered the edges of the matrix
 */

bool isInterleave(string s1, string s2, string s3) {
    int m = (int)s1.length();
    int n = (int)s2.length();
    if(m+n != s3.length())
        return false;
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 && j == 0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
             else if(j == 0)
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
            else
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    
    return dp[m][n];
}