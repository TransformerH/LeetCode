 // bit operation
 int hammingDistance(int x, int y) {
    int diff = 0;
    for(int i = 0; i < 31; i++){
        int bitx = x;
        int bity = y;
        bitx ^= 1;
        bity ^= 1;
        bitx = (bitx < x) ? 1 : 0;
        bity = (bity < y) ? 1 : 0;
        
        diff += (bitx == bity) ? 0 : 1;
        
        x >>= 1;
        y >>= 1;
    }
    return diff;
}