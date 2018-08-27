int maxProfit(vector<int>& prices) {
    int i10 = 0, i20 = 0, i11 = INT_MIN, i21 = INT_MIN;
    for(int i = 0; i < prices.size(); i++){
    	// buying and selling one stock is one transaction
    	// i21 = max(i21, i10 - princes[i])
    	// i20 = max(i20, i21 + princes[i])
        i20 = max(i20, i21 + prices[i]);
        i21 = max(i21, i10 - prices[i]);
        i10 = max(i10, i11 + prices[i]);
        i11 = max(i11, -prices[i]);
    }
    
    return i20;
}