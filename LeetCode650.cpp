 // classic dp problem
 int minSteps(int n) {
    vector<int> dp(n+1, 0);
    // n A can be made by 1 step of copy and n-1 steps of paste
    for(int i = 2; i <= n; i++)
        dp[i] = i;
    // find i A can be made by copying j A and pasting several times 
    // if i % j == 0
    for(int i = 2; i <= n; i++){
        for(int j = i-1; j > 1; j--){
            if(i % j == 0){
                dp[i] = dp[j] + i/j;
                break;
            }
        }
    }
    return dp[n];
}d