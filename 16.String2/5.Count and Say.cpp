class Solution {
public:
    string say(string &s){
       
        char no = s[0] ;
        int count=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i] == no) count++;
            else{
                char ch = '0' + count;
                ans  = ans + ch + no;
                no = s[i];
                count = 1;
            }
            
        }
          char ch = '0' + count;
                ans  = ans + ch + no;
       
        return ans;
    }
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            s = say(s);
        }
        return s;
    }
};