vector<int> plusOne(vector<int>& digits) {
    int len = (int)digits.size();
    vector<int> res;
    res.push_back((digits[len-1]+1) % 10);
    int carry = (digits[len-1]+1) > 9 ? 1 : 0;
    for(int i = len-2; i >= 0; i--){
        res.push_back((digits[i]+carry) % 10);
        carry = (digits[i]+carry) / 10;
    }
    if(carry > 0)
        res.push_back(1);
    reverse(res.begin(), res.end());
    return res;
}

