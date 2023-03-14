class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i] == '[' || s[i]=='{'){
                if(s[i] == '(') stack.push(')');
                else if (s[i] == '[') stack.push(']');
                else if (s[i]=='{') stack.push('}');
            }else{
                if(stack.empty()){
                    return false;
                }
                if(s[i] == stack.top()){
                    stack.pop();
                }else{
                    return false;
                }
            }
        }
        
        return stack.empty();
    }
};