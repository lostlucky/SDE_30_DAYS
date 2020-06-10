class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int minVal = prices[0], ans = 0;
        for(auto x:prices){
            if(x - minVal > 0) ans += x - minVal, minVal = x;
            else minVal = x;
        }
        return ans;
    }
};
