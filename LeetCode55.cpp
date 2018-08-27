// 0-1 knapsack problem
// each point can be choosen as reached or not

bool canJump(vector<int>& nums) {
    if(nums.size() <= 1)
        return true;
    if(nums[0] == 0)
        return false;
    vector<bool> jump(nums.size(), false);
    jump[0] = true;
    for(int i = 1; i < nums.size(); i++){
        for(int j = i - 1; j >= 0; j--){
            if(jump[j] && nums[j] + j >= i)
                jump[i] = true;
        }
    }
    return jump[nums.size() - 1];
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
}

bool canJump(vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    // i moves step by step
    // reach represents the farest position that can be reached when standing on the current i.
    // So we can reach every position among current i and reach, and we need to check the farest position that can be reached and change the param reach
    // since before change, the range is i -> reach_before , after change, the range is i -> reach_before -> reach_after
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + nums[i], reach);
    return i == n;
}
