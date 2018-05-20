vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    if(nums.size() == 0)
        return res;
    map<int, int> frequent;
    for(int i = 0; i < nums.size(); i++){
        map<int, int>::iterator it = frequent.find(nums[i]);
        if(it == frequent.end())
            frequent[nums[i]] = 1;
        else
            it->second++;
    }
    
    while(k > 0){
        map<int, int>::iterator it = frequent.begin();
        int largest = it->second;
        int index = it->first;
        while(it != frequent.end()){
            if(it->second > largest){
                largest = it->second;
                index = it->first;
            }
            it++;
        }
        res.push_back(index);
        k--;
        frequent.erase(index);
    }
    
    return res;
}
