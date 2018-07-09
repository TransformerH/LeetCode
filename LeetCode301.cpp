void remove(vector<string>& res, string s, int start, int right, vector<char> pa){
    for(int count = 0, i = start; i < (int)s.length(); i++){
        if(s[i] == pa[0]) count++;
        if(s[i] == pa[1]) count--;
        if(count >= 0) continue;
        
        for(int j = right; j <= i; j++){
            if(s[j] == pa[1] && (j == right || s[j-1] != pa[1]))
                // multiple results, return is the key
                remove(res, s.substr(0, j) + s.substr(j+1, s.length()-j-1), i, j, pa);
        }
        return;
    }
    // must create a new string, because multiple results
     string news = s;   
     vector<char> newpa = pa;
     reverse(news.begin(), news.end());
     reverse(newpa.begin(), newpa.end());
    if(pa[0] == '('){
       
        remove(res, news, 0, 0, newpa);
    } else {
        res.push_back(news);
    }
}
vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    vector<char> pa;
    pa.push_back('(');
    pa.push_back(')');
    remove(res, s, 0, 0, pa);
    return res;
}