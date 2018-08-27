 int lengthOfLastWord(string s) {
    int len = (int)s.length();
    int res = 0;
    for(int i = len-1; i >= 0; i--){
        if(s[i] == ' ')
            continue;
        for(int j = i; j >= 0; j--){
            if(s[j] == ' ')
                return res;
            res++;
            i--;
        }
    }
    return res;
}