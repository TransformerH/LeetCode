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
