 string toGoatLatin(string S) {
    string res = "";
    vector<string> words;
    string word = "";
    for(char c : S){
        if(c != ' '){
            word += c;
        } else {
            words.push_back(word);
            word = "";
        }
    }
    words.push_back(word);
    char vowel[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string sa = "";
    for(string word : words){
        sa += 'a';
        bool vo = false;
        for(int i = 0; i < 10; i++)
            if(word[0] == vowel[i])
                vo = true;
        if(!vo){
            string temp = word.substr(1);
            temp += word[0];
            word = temp;
        }
        word += "ma" + sa;
        res += word + ' ';
    }
    return res.substr(0, res.length()-1);
}

