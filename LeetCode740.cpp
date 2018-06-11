// dp
int deleteAndEarn(vector<int>& nums) {
	// save the sum of each value
	// if the array have triple four, the numsArray[4] = 12
    vector<int> numsArray(10001, 0);
    vector<int> dp(10003, 0);
    for(int num : nums)
        numsArray[num] += num;
    for(int i = 10000; i >= 0; i--){
    	// the problem that getting the points and deleting the former and the later
    	// can be changed to the ajacent value can not be added to the point.
        dp[i] = max(numsArray[i] + dp[i+2], dp[i+1]);
    }
    
    return dp[0];
}