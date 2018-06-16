// multiplication algorithm
string multiply(string num1, string num2) {
    string pro(num1.length() + num2.length(), '0');
    for(int i = num1.length()-1; i >= 0; i--){
        int carry = 0;
        for(int j = num2.length()-1; j >= 0; j--){
            int val = (pro[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
            pro[i+j+1] = val % 10 + '0';
            carry = val / 10;
        }
        // this step is very important.
        pro[i] += carry;
    }
    size_t pos = pro.find_first_not_of("0");
    if(pos != string::npos){
        pro = pro.substr(pos);
        return pro;
    }
    return "0";
}

