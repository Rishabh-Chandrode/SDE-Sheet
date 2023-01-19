class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        if(s.length()<2){
            return s.length();
        }
        
        int count=0,ans=0,si=0;
        for(int i=0;i<s.length();i++){
            
            if(m.find(s[i]) == m.end()){
                count++;
                m[s[i]]=i;
            }else{
                if(m[s[i]]<si){
                    count++;
                   
                }else{
                    ans=max(ans,count);
                    count=(i-m[s[i]]);
                    si=m[s[i]]+1;
                }
               
                m[s[i]]=i;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};