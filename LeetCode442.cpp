 vector<int> findDuplicates(vector<int>& nums) {
    if(nums.size() < 2){
        nums.clear();
        return nums;
    }
    sort(nums.begin(), nums.end());
    int n = (int)nums.size();
    for(int i = n - 1; i >= 0; i--){
        if(nums[i] != nums[i-1]){
            nums.erase(nums.begin()+i);
        }
    }
    return nums;
}