// regular permutation trying both recursion and heap algorithm, time limit exceeded
void heapPermutation(int size, vector<int>& cur, set<vector<int>>& setRes){
    if(size == 1){
        setRes.insert(cur);
        return;
    }
    
    for(int i = 0; i < size; i++){
        heapPermutation(size - 1, cur, setRes);
        if(size % 2 == 1)
            swap(cur[0], cur[size - 1]);
        else
            swap(cur[i], cur[size - 1]);
    }
}

string getPermutation(int n, int k) {
    string res = "";
    vector<int> curSet;
    set<vector<int>> resSet;
    for(int i = 1; i <= n; i++)
        curSet.push_back(i);
    heapPermutation(n, curSet, resSet);
    int count = 0;
    for(auto it = resSet.begin(); it != resSet.end(); it++)
    {
        count++;
        if(count == k){
            for(int num : *it)
                res += to_string(num);
            break;
        }
        
    }
    return res;
}


// result: 
