// stack
bool isValid(string s) {
    stack<char> cstack;
    for(int i = 0; i < s.length(); i++){
        if(cstack.empty())
            cstack.push(s[i]);
        else{
            char top = cstack.top();
            if((top == '(' && s[i] == ')') || (top == '[' && s[i] == ']') || (top == '{' && s[i] == '}')){
                cstack.pop();
            }else{
                cstack.push(s[i]);
            }
        }
    }
   
    return cstack.empty() ? true:false;
}
