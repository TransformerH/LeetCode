vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(words.size() == 0)
        return res;
    int wordLen = (int)words[0].size();
    int windowSize = (int)words.size() * wordLen;
    if(s.length() < windowSize)
        return res;
    
    unordered_map<string, int> wordMap;
    for(string word : words)
        wordMap[word]++;
    unordered_map<string, int> temp(wordMap);

    for(int i = 0; i < words[0].size(); i++){
        int left = i;
        int right = i;
        int wordCount = (int)wordMap.size();
        while(right + wordLen - 1 < s.length()){
            string rightWord = s.substr(right, wordLen);
            if(wordMap.find(rightWord) != wordMap.end()){
                wordMap[rightWord]--;
                if(wordMap[rightWord] == 0)
                    wordCount--;
            }
            if(right + wordLen - left == windowSize){
                // the current window has an answer candidate
                if(wordCount == 0){
                    res.push_back(left);
                }
                string leftWord = s.substr(left, wordLen);
                if(wordMap.find(leftWord) != wordMap.end()){
                    wordMap[leftWord]++;
                    if(wordMap[leftWord] > 0)
                        wordCount++;
                }
                // move the left of the window
                left += wordLen;
            }
            // the size of the window does not equal to the windowSize, 
            // so we need to add a new word in to the window
            right += wordLen;
        }
        wordMap = temp;
    }
    return res;
}