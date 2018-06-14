// dp
int numSquares(int n) {
    vector<int> squares;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i*i <= n; i++)
        squares.push_back(i*i);
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < squares.size(); j++){
            if(i + squares[j] <= n){
                dp[i+squares[j]] = min(dp[i+squares[j]], dp[i]+1);
            }
        }
    }
    
    return dp[n];
}