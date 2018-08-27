int totalHammingDistance(vector<int>& nums) {
    int sum = 0;
    int zeroone[2] = {0,0};
    
    while(true){
        zeroone[0] = 0;
        zeroone[1] = 0;
        // recount the number of zero
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                 count++;
            zeroone[nums[i] % 2]++;
            nums[i] >>= 1;      
        }
        sum += zeroone[0]*zeroone[1];
        if(count == nums.size())
            break;
    }
    
    return sum;
}