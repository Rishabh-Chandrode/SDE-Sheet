class Solution {
public:
    int util(int left,int right,string s){
        int l=left,r = right;
        while(l >=0 && r<s.length() && s[l] == s[r]){
                l--;
                r++;
        
        }
    
        return (r - l -1);
    }
    string longestPalindrome(string s) {
        if(s.length() <2) return s;
        
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            int len1 = util(i,i,s);
            int len2 = util(i,i+1,s);
            int len = max(len1,len2);
            if(len > end - start){
               start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        string ans="";
        ans = s.substr(start,end-start+1);
        return ans;
    }
};