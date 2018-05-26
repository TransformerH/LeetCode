// hash table
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<string, int> patterns;
    int len = 10;
    for(int i = 0; i + len - 1 < s.length(); i++){
        string curp = s.substr(i, len);
        if(patterns.find(curp) == patterns.end())
            patterns[curp] = 1;
        else
            patterns[curp]++;
    }
    for(auto it = patterns.begin(); it != patterns.end(); it++){
        if(it->second > 1)
            res.push_back(it->first);
    }

    return res;
}
