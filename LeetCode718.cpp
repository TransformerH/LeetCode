
// basic dp
int findLength(vector<int>& A, vector<int>& B) {
    int an = (int)A.size();
    int bn = (int)B.size();
    int len = 0;
    vector<vector<int>> dp(an+1, vector<int>(bn+1, 0));
    for(int i = 1; i <= an; i++){
        for(int j = 1; j <= bn; j++){  
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    len = max(len, dp[i][j]);
                } 
        }
    }
    
    return len;
}

