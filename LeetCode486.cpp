// two-dimensional dp problem

 int judge(vector<int>& nums,  vector<vector<int>>& dp, int i, int j){
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int left = nums[i] + min(judge(nums, dp, i+1, j-1), judge(nums, dp, i+2, j));
    int right = nums[j] + min(judge(nums, dp, i+1, j-1), judge(nums, dp, i, j-2));
    
    return max(left, right);
}

bool PredictTheWinner(vector<int>& nums) {
    int n = (int)nums.size();
    if(n % 2 == 0)
        return true;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int player1 = judge(nums, dp, 0, n-1);
    
    return player1 >= (sum - player1)? true : false;
}