
// double pointers + for loop = three numbers
// key points:
/*
1. sort the original array
2. front and rear pointers represeant the smallest and largest numbers in the array
*/
 vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); i++){
        int target = -nums[i];
        int front = i+1;
        int rear = (int)nums.size()-1;
        while(front < rear){
            int comp = nums[front] + nums[rear];
            if(comp < target)
                front++;
            else if(comp > target)
                rear--;
            else{
                vector<int> curRes;
                curRes.push_back(nums[i]);
                curRes.push_back(nums[front]);
                curRes.push_back(nums[rear]);
                res.push_back(curRes);
                
                while(front+1 < rear && nums[front+1] == nums[front])
                    front++;
                while(front < rear-1 && nums[front] == nums[rear-1])
                    rear--;
                
                front++;
                rear--;
            }
        }
        while(i+1 < nums.size() && nums[i+1] == nums[i])
            i++;
    }
    
    return res;
}