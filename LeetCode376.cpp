// dp thought:
/*
the sizes of record boards are equal to the size of nums
*/
int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
    int size = (int)nums.size();
    vector<int> up(size, 0);
    vector<int> down(size, 0);
    up[0] = 1;
    down[0] = 1;
    
    for(int i = 1; i < size; i++){
        if(nums[i] - nums[i-1] > 0){
            up[i] = down[i-1] + 1;
            down[i] = down[i-1];
        } else if(nums[i] - nums[i-1] < 0){
            down[i] = up[i-1] + 1;
            up[i] = up[i-1];
        } else {
            down[i] = down[i-1];
            up[i] = up[i-1];
        }
    }
    
    return max(up[size-1], down[size-1]);
}