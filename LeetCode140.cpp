class Solution {
    unordered_map<string, vector<string>> m;
    vector<string> combined(string word, vector<string> strv){
        for(int i = 0; i < strv.size(); i++)
            strv[i] += " "+word;
        return strv;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s))
            return m[s];
        vector<string> result;
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
            result.push_back(s);
        for(int i = 1; i < s.length(); i++){
            string word = s.substr(i);
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                string substring = s.substr(0, i);
                vector<string> temp = combined(word, wordBreak(substring, wordDict));
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }
        m[s] = result;
        return result;
    }
};