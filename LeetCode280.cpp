void wiggleSort(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 1){
                if(nums[i] < nums[i-1])
                    swap(nums[i], nums[i-1]);
            } else {
                if(i > 0 && nums[i] > nums[i-1])
                    swap(nums[i], nums[i-1]);
            }
        }
    }