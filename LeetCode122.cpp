 int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int cash = 0;
    int hold = -prices[0];
    for(int i = 1; i < prices.size(); i++){
    	// 购买时的利润选最大的
        cash = max(cash, hold + prices[i]);
        // 买进时剩余的钱越多越好，即低价买进
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}