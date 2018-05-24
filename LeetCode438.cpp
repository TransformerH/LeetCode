// time limit exceeded

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if(s.length() < p.length())
        return res;
    unordered_map<char, int> pChars;
    for(int i = 0; i < p.length(); i++){
        auto it = pChars.find(p[i]);
        if(it == pChars.end()){
            pChars[p[i]] = 1;
        } else {
            pChars[p[i]]++;
        }
    }
    
   unordered_map<char, int> temp = pChars;
    for(int i = 0; i < s.length(); i++){
        auto it = pChars.find(s[i]);
        int len = (int)p.length();
        if(it != pChars.end() && it->second > 0){
            it->second--;
            len--;
            for(int k = i + 1; k < s.length() && len > 0; k++){
                auto findit = pChars.find(s[k]);
                if(findit != pChars.end() && findit->second > 0){
                    findit->second--;
                    len--;
                }else {
                    break;
                }
            }
        }
        if(len == 0)
            res.push_back(i);
        pChars = temp;
    }
    
    return res;
}

// solution - window algorithm - 1

vector<int> findAnagrams(string s, string p) {
    vector<int> sv(26, 0), pv(26, 0), res;
    if(s.length() < p.length())
        return res;
    // the window' size  =  p.length()
    /*
    the value of sv[x] is 1 represents the char which in the substring of s which is in the current window 
    */
    int plen = (int)p.length();
    // the first position of window
    for(int i = 0; i < plen; i++){
        sv[s[i] - 'a']++;
        pv[p[i] - 'a']++;
    }
    if(sv == pv)
        res.push_back(0);
    for(int i = plen; i < s.length(); i++){
        //----------  move the window -----------//
        sv[s[i] - 'a']++;
        sv[s[i - plen] - 'a']--;
        //----------  move the window -----------//
        if(sv == pv)
            res.push_back(i - plen + 1);
    }
    return res;
}
