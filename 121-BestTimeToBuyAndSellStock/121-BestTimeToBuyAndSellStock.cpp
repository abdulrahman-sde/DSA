// Last updated: 8/13/2025, 2:36:02 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int diff=0;
        int profit=0;

        for(int i=0;i<prices.size();i++){
            diff=prices[i]-mini;
            profit=max(profit,diff);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};