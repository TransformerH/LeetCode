int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum < S || (sum + S) % 2 != 0)
        return 0;
    int target = (sum + S) / 2;
    vector<int> dp(target+1, 0); // record the number of ways that can reach there.
    dp[0] = 1;
    for(int num : nums){
        for(int i = target; i <= num; i--){
            dp[i] += dp[i-num];
        }
    }
    return dp[target];
}