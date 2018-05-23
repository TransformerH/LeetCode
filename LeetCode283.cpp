 void moveZeroes(vector<int>& nums) {
    int n = (int)nums.size();
    int endIndex = n - 1;
    int currentIndex = n - 1;
    
    while(currentIndex >= 0 && endIndex >= 0){
        if(nums[currentIndex] == 0){
            for(int i = currentIndex + 1; i <= endIndex; i++)
                nums[i - 1] = nums[i];
            nums[endIndex] = 0;
            endIndex--;
        }
        currentIndex--;
    }
}

