int singleNumber(vector<int>& nums) {
    vector<int> bits(32, 0);
    int size = nums.size();
    for(int i = 0; i < size; i++){
        int n = nums[i];
        for(int j = 31; j >= 0; j--){
            bits[j] += n&1;
            n >>= 1;
            if(!n)
                break;
        }
    }
    
    int ret = 0;
    for(int i = 0; i < 32; i++){
        if(bits[i] % 3)
            ret += (1<<(31-i));
        
    }
    return ret;
}