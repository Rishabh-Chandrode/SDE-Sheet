class Solution {
public:
    int myAtoi(string s) {
        int i=0,f=1;
        while(s[i] == ' ' || s[i]=='_') i++;
        
        if(s[i] == '-' || s[i] == '+'){
            f= s[i]=='-'?-1:1;
            i++;
        }
        
        
        
        long long ans=0;
        while(i<s.length() && (s[i]>='0' && s[i]<='9')){
            
            ans = (ans*10) + (s[i]-48);
            if(ans*f>=INT_MAX) return INT_MAX;
            if(ans*f <= INT_MIN) return INT_MIN;
           // cout<<ans<<endl;
            i++;
        }
        return ans*f;
    }
};