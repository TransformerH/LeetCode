// method 1: no skill

bool palindromic(string s){
    int len = (int)s.length();
    for(int l = 0; l < len / 2; l++){
        if(s[l] != s[len - 1 - l])
            return false;
    }
    return true;
}

int countSubstrings(string s) {
    int result = 0;
    for(int start = 0; start < s.length(); start++){
        for(int subLen = 1; subLen <= s.length() - start; subLen++){
            string sub = s.substr(start, subLen);
            if(palindromic(sub))
                result++;
        }
    }
    return result;
}

// method 2: dp
int countSubstrings(string s) {
    vector<string> curSubstrings;
    vector<string> lastSubstrings;
    int len = (int)s.length();
    
    lastSubstrings.push_back(string(1, s[len - 1]));
    int result = 1;
    for(int i = len - 2; i >= 0; i--){
        string n = string(1, s[i]);
        result++;
        curSubstrings.push_back(n);
        for(auto it:lastSubstrings){
            string r = n + it;
            curSubstrings.push_back(r);
            if(palindromic(r))
                result++;
        }
        lastSubstrings = curSubstrings;
        curSubstrings.clear();
    }
    
    return result;
}