// dp deformation
int robProcess(vector<int>& nums, int start, int end){
    int pre = 0;
    int cur = 0;
    // cur keeps the current maximal value
    // pre keeps the last cur 
    // add the new member of nums to the last pre
    // the process can be represented by : 
    /* 
    last_pre->last_cur->new_member
    new_cur = max(last_pre + new_member, last_cur)
    */
    for(int i = start; i <= end; i++){
        int temp = max(pre+nums[i], cur);
        pre = cur;
        cur = temp;
    }
    
    return cur;
}

int rob(vector<int>& nums) {
    if(nums.size() < 2)
        return nums.size() ? nums[0] : 0;
    return max(robProcess(nums, 0, nums.size()-2), robProcess(nums, 1, nums.size()-1));
}

