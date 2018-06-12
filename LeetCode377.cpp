 //Bravo!!!
 int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= target)
            dp[nums[i]] = 1;
    }
    for(int i = 0; i < target; i++){
        for(int j = 0; j < nums.size(); j++){
            if(i + nums[j] <= target){
                dp[i+nums[j]] += dp[i];
            }
        }
    }
    
    return dp[target];
}