class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        vector<int> num;
        int fact=1;
        for(int i=1;i<n;i++){
            num.push_back(i);
            fact*=i;
        }
        num.push_back(n);
        k--;
        while(true){
            s += to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0) break;
            k = k%fact;
            fact = fact/num.size();
        }
        return s;
    }
};