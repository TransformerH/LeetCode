void findCom(vector<int>& curCom, set<vector<int>>& setRes, vector<int>& candidates, int target, int start){
    int curSum = 0;
    for(int num : curCom)
        curSum += num;
    if(curSum == target){
        setRes.insert(curCom);
        return;
    }
    if(start == candidates.size())
        return;
    
    for(int i = start; i < candidates.size(); i++){
        if(candidates[i] + curSum <= target){
            curCom.push_back(candidates[i]);
            findCom(curCom, setRes, candidates, target, i + 1);
            curCom.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    set<vector<int>> setRes;
    if(candidates.size() == 0)
        return res;
    vector<int> curCom;
    sort(candidates.begin(), candidates.end());
    findCom(curCom, setRes, candidates, target, 0);
    for(auto it = setRes.begin(); it != setRes.end(); it++)
        res.push_back(*it);
    
    return res;
}
