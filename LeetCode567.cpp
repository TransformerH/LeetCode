 // fixed-window
// same like 438
 bool checkInclusion(string s1, string s2) {
    vector<int> s1v(26, 0), s2v(26, 0);
    int len1 = s1.length();
    int len2 = s2.length();
    for(int i = 0; i < len1; i++){
        s1v[s1[i] - 'a']++;
        s2v[s2[i] - 'a']++;
    }
    if(s1v == s2v)
       return true;
    for(int j = len1; j < len2; j++){
        s2v[s2[j] - 'a']++;
        s2v[s2[j-len1] - 'a']--;
        if(s1v == s2v)
            return true;
    }
    
    return false;
}