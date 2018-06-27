// dp
vector<int> largestDivisibleSubset(vector<int>& nums) {
       if(nums.size() == 0)
           return vector<int>();
    int size = (int)nums.size();
    vector<vector<int>> dp(size, vector<int>());
    sort(nums.begin(), nums.end());
    for(int i = 0; i < size; i++){
        dp[i].push_back(nums[i]);
        for(int j = i+1; j < size; j++){
            if(nums[j] % nums[i] == 0){
                if(dp[j].size() < dp[i].size()+1){
                    dp[j].clear();
                    for(int pre : dp[i]){
                        dp[j].push_back(pre);
                    }
                }
            }
            
        }
    }
    int maxSize = 0;
    for(int i = 0; i < size; i++){
        if(dp[i].size() > dp[maxSize].size())
            maxSize = i;
    }
    return dp[maxSize];
}