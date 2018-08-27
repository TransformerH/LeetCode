int firstMissingPositive(vector<int>& nums) {
    int size = (int)nums.size();
    for(int i = 0; i < size; i++)
        while(nums[i] > 0 && nums[i] < size && nums[nums[i]-1] != nums[i])
            swap(nums[i], nums[nums[i]-1]);
    int k = 0;
    for(; k < size; k++)
        if(nums[k] != k+1)
            break;
    return k+1;
}
