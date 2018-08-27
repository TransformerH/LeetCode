vector<int> grayCode(int n) {
        vector<int> ret;
        //  the previous one and the next one should have one different bit
        // that means the pow(2, x)
        // i ^ i/2 and (i+1) ^ (i+1)/2 can be proved that there is one different bit
        for(int i = 0; i < pow(2, n); i++){
            ret.push_back(i ^ i/2);
        }
        return ret;
    }