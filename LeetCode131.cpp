bool isPalindrome_self(string s){
    int len = (int)s.length();
    for(int i = 0; i < len / 2; i++){
        if(s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

    void partitionPa(string origin, int start, vector<string>& curSet, vector<vector<string>>& res){
    if(origin.length() == start){
        res.push_back(curSet);
        return;
    }
    int len = (int)origin.size();
    for(int i = start; i < len ; i++){
        string curSub = origin.substr(start, i - start + 1);
        if(isPalindrome_self(curSub)){
            curSet.push_back(curSub);
            partitionPa(origin, i + 1, curSet, res);
            curSet.pop_back();
        }
    }
}



vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    if(s.length() == 0)
        return res;
    vector<string> curSet;
    partitionPa(s, 0, curSet, res);
    return res;
}