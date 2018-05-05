
// method 1
// not the dp one

int calculate(int n){
    int count = 0;
    for(int i = 0; i < 32; i++){
        int origin = n;
        int comp = origin ^ 1;
        if(origin > comp)
            count++;
        n >>= 1;
    }
    return count;
}

vector<int> countBits(int num) {
    vector<int> result;
    for(int i = 0; i <= num; i++)
        result.push_back(calculate(i));
    return result;
}

// method 2
// dp

vector<int> countBits(int num){
    vector<int> result(0, num + 1);
    int index = 1;
    result.push_back(0);
    for(int i = 1; i < num + 1; i++){
        if(index * 2 == i)
            index *= 2;
        result.push_back(result[i - index] + 1);
    }
    return result;
}
