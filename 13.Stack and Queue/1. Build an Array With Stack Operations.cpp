class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        string push="Push",pop="Pop";
        int i=0,num=1;
        while(i<target.size()){
            while(num!=target[i]){
                ans.push_back(push);
                ans.push_back(pop);
                num++;
            }
            ans.push_back(push);
            num++;
            i++;
        }
        return ans;
    }
};