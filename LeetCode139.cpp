//BFS - time limited exceeded
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, string> wordMap;
    queue<pair<int, int>> sq;
    for(string word : wordDict)
        wordMap[word] = "";
    int start = 0, len = 1;
    sq.push(make_pair(0, 0));
    while(!sq.empty()){
        auto top = sq.front();
        sq.pop();
        start = top.first + top.second;
        len = 0;
        while(start + len < s.length()){
            string curword = s.substr(start, len);
            if(wordMap.find(curword) != wordMap.end()){
                sq.push(make_pair(start, len));
                if(start + len == s.length())
                	return true;
            }
            len++;
        }
    }
    return false;
}

// dp
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet;
    for(string word : wordDict)
        wordSet.insert(word);
    vector<bool> visited(s.length()+1, false);
    visited[0] = true;
    for(int i = 1; i <= s.length(); i++){
        for(int j = i - 1; j >= 0; j--){
            if(visited[j]){
                string sub = s.substr(j, i-j);
                if(wordSet.find(sub) != wordSet.end()){
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    return visited[s.length()];
}