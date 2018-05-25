// the problem can be converted to find the max size of a defined variable-size window
int lengthOfLongestSubstring(string s) {
    if(s.length() == 0)
        return 0;
    unordered_map<char, int> charMap;
    int left = 0;
    int right = 1;
    charMap[s[left]]++;
    int len = 1;
    while(right < s.length()){
        while(charMap.find(s[right]) != charMap.end()){
            charMap.erase(s[left]);
            left++;
        }
        
        charMap[s[right]]++;
        if(right - left + 1 > len)
            len = right - left + 1;
        
        right++;
    }
    
    return len;
}