  string addBinary(string a, string b) {
    int asize = (int)a.length();
    int bsize = (int)b.length();
    string res(max(asize, bsize) + 1, '0');
    int i = asize - 1;
    int j = bsize - 1;
    int z = (int)res.length() - 1;
    int carry = 0;
    while(i >= 0 && j >= 0){
        int avalue = a[i] - '0';
        int bvalue = b[j] - '0';
        int temp = avalue + bvalue + carry;
        if(temp > 1){
            res[z] =  temp - 2 +'0';
            carry = 1;
        } else {
            res[z] = temp + '0';
            carry = 0;
        }
        i--;
        j--;
        z--;
    }
    while(i >= 0){
        int temp = a[i] - '0' + carry;
        if(temp > 1){
            res[z] = '0';
            carry = 1;
        } else {
            res[z] = temp + '0';
            carry = 0;
        }
        i--;
        z--;
    }
    while(j >= 0){
        int temp = b[j] - '0' + carry;
        if(temp > 1){
            res[z] = '0';
            carry = 1;
        } else {
            res[z] = temp + '0';
            carry = 0;
        }
        j--;
        z--;
    }
    res[0] = carry + '0';
    size_t sub = res.find_first_not_of('0');
    if(sub != string::npos)
        res = res.substr(sub);
    else
        return "0";
    return res;
}