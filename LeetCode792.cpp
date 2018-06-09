int numMatchingSubseq(string S, vector<string>& words) {
    // ASCII 
    vector<const char*> wordsVector[128];
    for(auto &word : words)
        // classify members of words by the initial
        wordsVector[word[0]].push_back(word.c_str());
    for(char c : S){
        // when pass through the S, we can get the word that has the same letter
        // and because the order of the S, we can get words that are sequences of the S.
        auto curv = wordsVector[c];
        wordsVector[c].clear();
        for(auto it : curv)
            wordsVector[*++it].push_back(it);
    }

    return (int)wordsVector[0].size();
}

