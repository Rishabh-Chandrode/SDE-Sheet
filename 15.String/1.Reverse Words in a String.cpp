class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string word="";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ' && word.length() > 0){
                if(ans == ""){
                  
                    ans = word;
                }else{
                   
                     ans = word + " " + ans;
                }
               
                word = "";
                continue;
            }
            if(s[i] !=' '){
                word = word+s[i];
            }
            
        }
       
        if (ans == "") return word;
        if(word.length() >0 && ans != "")
        ans = word + " " + ans;
        
        return ans;
    }
};