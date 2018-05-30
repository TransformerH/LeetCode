int findMin(vector<int>& nums) {
    int min = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < nums[i - 1])
            min = nums[i];
    }
    
    return min;
}