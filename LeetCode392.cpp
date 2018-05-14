 bool isSubsequence(string s, string t) {
    if(s == "")
        return true;
    int sIndex = 0;
    for(int i = 0; i < t.length(); i++){
        if(t[i] == s[sIndex]){
            sIndex++;
            if(sIndex == s.length())
                return true;
        }
    }
    return false;
}
