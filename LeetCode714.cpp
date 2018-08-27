int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            cash = max(cash, hold + prices[i] - fee);
            // don't need to save the old cash, cuz it can be bought when it was sold.
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }