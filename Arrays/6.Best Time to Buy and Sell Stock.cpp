class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX,profit=0,maxprofit=0;
        for(int i=0;i<prices.size();i++){
            if(min>prices[i]) min=prices[i];

            profit=prices[i]-min;
            if(profit>maxprofit) maxprofit = profit;
        }
        return maxprofit;
    }
};