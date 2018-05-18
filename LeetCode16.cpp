bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(),nums.end(), 0);
    if(sum % 2 != 0)
        return false;
    int target = sum / 2;
    vector<bool> beReached(target + 1, false);
    beReached[0] = true;
    
    for(int i = 0; i < nums.size(); i++){
        for(int j = target; j > 0; j--){
        /*
when the sum is i and it can be reached, the num will not be added.
when it can't be reached, if that i-num can be reached means the num can be added and the i can be reached at the same time.
        */
            if(j >= nums[i] && !beReached[j])
                beReached[j] = beReached[j - nums[i]];
        }
    }
    
    return beReached[target];
}