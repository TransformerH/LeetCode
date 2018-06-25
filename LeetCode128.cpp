// hash map
int longestConsecutive(vector<int>& nums) {
    int len = 0;
    unordered_map<int, int> consecutive;
    for(int num : nums){
        if(consecutive.find(num) == consecutive.end()){
            int left = (consecutive.find(num-1) == consecutive.end()) ? 0 : consecutive[num-1];
            int right = (consecutive.find(num+1) == consecutive.end()) ? 0 : consecutive[num+1];
            int sum = left + right + 1;
            consecutive[num] = sum;
            len = max(len, sum);
            consecutive[num-left] = sum;
            consecutive[num+right] = sum;
        }else
            continue;
    }
    return len;
}