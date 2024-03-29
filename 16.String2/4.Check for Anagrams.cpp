class Solution {
public:
    bool isAnagram(string s, string t) {
       int arr[26];
       
       for(int i=0;i<26;i++){
           arr[i] = 0;
       }
       
       for(int i=0;i<s.length();i++){
           arr[s[i]-'a']++;
       }

       
       for(int i=0;i<t.length();i++){
          
           if(arr[t[i]-'a'] == 0) return false;
           else arr[t[i]-'a']--;
       }
       
       
       for(int i=0;i<26;i++){
           if(arr[i]>0) return false;
       }
       return true;
    }
};