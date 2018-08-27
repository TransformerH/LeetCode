int maxProfit(int k, vector<int>& prices) {
    // A transaction needs 2 days, one day buy the stock, one day sell the stock.
    // So, when the number of transactions is more than the size of prices, it means that the number of transactions is infinity.
    if(k >= prices.size() / 2){
        int i0 = 0, i1 = INT_MIN;
        for(int price : prices){
            i0 = max(i0, i1 + price);
            i1 = max(i1, i0 - price);
        }
        return i0;
    }
    
    vector<int> k0(k+1, 0);
    vector<int> k1(k+1, INT_MIN);
    for(int price: prices){
        for(int i = 1; i <= k; i++){
            k0[i] = max(k0[i], k1[i] + price);
            k1[i] = max(k1[i], k0[i-1] - price);
        }
    }
    
    return k0[k];
}