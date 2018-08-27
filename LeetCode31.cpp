   void nextPermutation(vector<int>& nums) {
    int len = (int)nums.size();
    int c = len-1;
    while(c > 0){
        if(nums[c-1] < nums[c])
            break;
        c--;
    }
    if(c == 0)
        reverse(nums.begin(), nums.end());
    else {
        int t = len-1;
        while(t >= c){
            if(nums[t] > nums[c-1])
                break;
            t--;
        }
        swap(nums[c-1], nums[t]);
        reverse(nums.begin()+c, nums.end());
    }
 }