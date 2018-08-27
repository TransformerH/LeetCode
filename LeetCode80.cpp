int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int templen = 1;
    int pre = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == pre){
            templen++;
            if(templen > 2){
                nums.erase(nums.begin()+i);
                i--;
            }
        } else {
            templen = 1;
            pre = nums[i];
        }
    }
    return nums.size();
}