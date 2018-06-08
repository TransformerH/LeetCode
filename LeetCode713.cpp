// dp - time limited
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int count = 0;
    int n = (int)nums.size();
    vector<long> dp(n, 0);
    
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++){
            if(i != j)
                dp[i] *= nums[j];
            else
                dp[i] = nums[j];
            if(dp[i] < k && dp[i] > 0)
                count++;
            else{
                dp[i] = 0;
                break;
            }
        }
    
    return count;
}

// window
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int count = 0;
    int product = 1;
    if(k == 0)
        return count;
    for(int i = 0, j = 0; j < nums.size(); j++){
        product *= nums[j];
        while(i <= j && product >= k){
            product /= nums[i++];
        }
        count += (j - i + 1);
    }
    
    return count;
}