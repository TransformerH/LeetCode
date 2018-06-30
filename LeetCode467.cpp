// dp
// The key point of this problem is the substring is consecutive
// e.g.  abcde  alp[a] = 1（a）, alp[b] = 2（ab, b）, alp[c] = 3（abc,bc,c）....
int findSubstringInWraproundString(string p) {
    vector<int> alphabet(26, 0);
    int curcount = 0;
    for(int i = 0; i < p.length(); i++){
        if(i > 0 && ((p[i] - p[i-1] == 1) || (p[i-1] - p[i] == 25)))
            curcount++;
        else
            curcount = 1;
        alphabet[p[i]-'a'] = max(alphabet[p[i]-'a'], curcount);
    }
    
    int res = 0;
    for(int i = 0; i < 26; i++)
        res += alphabet[i];
    
    return res;
}