string getPermutation(int n, int k) {
    vector<int> nums;
    for(int i = 1; i <= n; i++)
        nums.push_back(i);
    while(k > 1){
        k--;
        int c = n-1;
        while(c > 0){
            if(nums[c-1] < nums[c])
                break;
            c--;
        }
        
        int t = n-1;
        while(t > c){
            if(nums[t] > nums[c-1])
                break;
            t--;
        }
        swap(nums[c-1], nums[t]);
        reverse(nums.begin()+c, nums.end());
    }
    string res = "";
    for(int num : nums)
        res += (num + 48);
    return res;
}
