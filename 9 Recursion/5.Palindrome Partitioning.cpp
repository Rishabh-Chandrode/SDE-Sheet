class Solution {
public:
    vector<vector<string>> ans;
    bool check(string s,int low,int high){
        while(low<high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    void util(string s,int ind,vector<string> v){
        if(ind==s.size()){
            ans.push_back(v);
            return;
        }
       for(int i=ind;i<s.size();i++){
           if(check(s,ind,i)){
               v.push_back(s.substr(ind,i-ind+1));
               util(s,i+1,v);
                v.pop_back();
           }
       }
    }
    vector<vector<string>> partition(string s) {
        int high = s.length()-1;
        vector<string> v;
        util(s,0,v);
        return ans;
    }
};