string customSortString(string S, string T) {
    unordered_map<char, string> smap;
    for(char c : S)
        smap[c] = "";
    string res = "";
    for(char c : T){
        if(smap.find(c) != smap.end())
            smap[c] += c;
        else
            res += c;
    }
    for(char c : S){
        res += smap[c];
    }
    return res;
}