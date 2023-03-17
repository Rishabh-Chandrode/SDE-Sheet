class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        for(int i=prices.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(prices[i]);
                continue;
            }
            while(!s.empty() && prices[i] < s.top()){
                s.pop();
            }
            if(s.empty()){
                s.push(prices[i]);
            }else{
                int t = prices[i];
                prices[i] = prices[i] - s.top();
                s.push(t);
            }
        }
        return prices;
    }
};