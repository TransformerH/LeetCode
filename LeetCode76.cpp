
// variable-size window algorithm

string minWindow(string s, string t) {
    string res = "";
    if(s.length() < t.length())
        return res;
    unordered_map<char, int> tMap;
    for(int i = 0; i < t.length(); i++)
        tMap[t[i]]++;
    int left = 0, right = 0;
    int len = INT_MAX;
    int charCount = (int)tMap.size();
    while(right < s.length()){
        if(tMap.find(s[right]) != tMap.end()){
            tMap[s[right]]--;
            if(tMap[s[right]] == 0)
                charCount--;
        }
       
        while(charCount == 0){
            if(right - left + 1 < len){
                len = right - left + 1;
                res = s.substr(left, len);
            }
            
            if(tMap.find(s[left]) != tMap.end()){
                tMap[s[left]]++;
                if(tMap[s[left]] > 0)
                    charCount++;
            }
            left++;
        }
         right++;
    }
    
    return res;
}
