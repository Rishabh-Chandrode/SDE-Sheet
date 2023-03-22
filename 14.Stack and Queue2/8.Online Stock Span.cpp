class StockSpanner {
public:
vector<pair<int,int>> v;
int top=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(v.size() == 0){
            v.push_back(make_pair(price,-1));
            top++;
            return 1;
        }
        if(price < v[top].first){
            v.push_back(make_pair(price,top));
            top++;
            return 1;
        }
        int ind = top;
        while(price >= v[ind].first ){
            if(v[ind].second == -1){
                
                    ind = -1;
                    break;
                
            }
            ind = v[ind].second;
        }

        v.push_back(make_pair(price,ind));
        top++;
        if(ind == -1){
            return top+1;
        }
        return top-ind;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */