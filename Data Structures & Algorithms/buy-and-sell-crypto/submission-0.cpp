class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int currentPrice=prices[0];
        for(int i=1;i<prices.size();i++){
            maxi=max(maxi,prices[i]-currentPrice);
            currentPrice=min(currentPrice,prices[i]);
        }
        return maxi;
    }
};
