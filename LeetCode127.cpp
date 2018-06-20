 // BFS
 bool nextTo(string origin, string side){
    int diff = 0;
    for(int i = 0; i < origin.length(); i++){
        if(origin[i] != side[i])
            diff++;
        if(diff > 1) return false;
    }
    return diff == 1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;
    queue<string> strQueue;
    set<string> visited;
    queue<int> dist;
    strQueue.push(beginWord);
    visited.insert(beginWord);
    dist.push(1);
    
    while(!strQueue.empty()){
        string cur = strQueue.front();
        strQueue.pop();
        int distant = dist.front();
        dist.pop();
        if(cur == endWord)
            return distant;
        for(int i = 0; i < wordList.size(); i++){
            if(nextTo(cur, wordList[i]) && visited.find(wordList[i]) == visited.end()){
                dist.push(distant+1);
                strQueue.push(wordList[i]);
                visited.insert(wordList[i]);
            }
        }
    }
    
    return 0;
}

