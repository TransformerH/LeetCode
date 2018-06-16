 int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int size = nums.size();
        if(nums[0] > target && nums[size-1] < target)
            return -1;
        if(target >= nums[0]){
            for(int i = 0; i < size && nums[i] <= target; i++)
                if(nums[i] == target)
                    return i;
        } else if(target <= nums[size-1]){
            for(int i = size-1; i >= 0 && nums[i] >= target; i--)
                if(nums[i] == target)
                    return i;
        }
        return -1;
    }