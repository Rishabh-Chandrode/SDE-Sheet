class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'M'){
                ans+=1000;
                continue;
            }
            if(s[i] == 'D'){
                ans+=500;
                continue;
            }
            if(s[i] == 'C'){
                if(i+1<s.length()){
                    if(s[i+1] == 'D'){
                        ans+=400;
                        i++;
                        continue;
                    }
                    if(s[i+1] == 'M'){
                        ans += 900;
                        i++;
                        continue;
                    }else{
                        ans+=100;
                        continue;
                    }
                }else{
                    ans+=100;
                    continue;
                }
            }
            if(s[i] == 'L'){
                ans+=50;
                continue;
            }
            if(s[i] == 'X'){
                if(i+1<s.length()){
                    if(s[i+1] == 'L'){
                        ans+=40;
                        i++;
                        continue;
                    }
                    if(s[i+1] == 'C'){
                        ans += 90;
                        i++;
                        continue;
                    }else{
                        ans+=10;
                        continue;
                    }
                }else{
                    ans+=10;
                    continue;
                }
            }
            if(s[i] == 'V'){
                ans+=5;
                continue;
            }
            if(s[i] == 'I'){
                if(i+1<s.length()){
                    if(s[i+1] == 'V'){
                        ans+=4;
                        i++;
                        continue;
                    }
                    if(s[i+1] == 'X'){
                        ans += 9;
                        i++;
                        continue;
                    }else{
                        ans+=1;
                        continue;
                    }
                }else{
                    ans+=1;
                    continue;
                }
            }


        }
        return ans;
    }
};