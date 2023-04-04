class Solution {
public:
    string longestPrefix(string s) {
        int l=s.length();
        if(l<2) return "";
        vector<int> v(l,0);
        int i=1,j=0;
        for(i=1;i<l;){
            if(s[i] == s[j]){
                j++;
                v[i] = j;
                i++;
            }else{
                if(j!=0){
                    j = v[j-1];
                }else{
                    i++;
                }
                
            }
           
        }
        return s.substr(0,v[l-1]);
    }
};