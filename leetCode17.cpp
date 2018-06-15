vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.size() == 0)
        return res;
    // string is a kind of array.
    string digitChar[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for(int i = 0; i < digits.size(); i++){
        // don't need to use atoi
        string cur = digitChar[digits[i] - '0'];
        vector<string> temp;
        for(int j = 0; j < cur.size(); j++){
            for(int k = 0; k < res.size(); k++)
                temp.push_back(res[k]+cur[j]);
        }
        res = temp;
    }
    return res;
}