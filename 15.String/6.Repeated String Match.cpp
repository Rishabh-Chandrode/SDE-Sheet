class Solution {
public:
    vector<int> power;
    int base = 1000000;
    int M = 1e9 + 7;
    int tochar(char ch){
        return (ch-'A'+1);
    }
    int gethash(string s){
        int sum = 0;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            sum = (sum + ( tochar(s[i]) * 1LL * power[n-1-i] )%M )%M;
        }
        return sum;
    }
    bool checkstr(string pat,string str,int l,int n){
        for(int i=0;i<n;i++){
            if(pat[i] != str[i+l]) return false;
        }
        return true;
    }
    int rabinkarp(string pat,string str){
       // cout<<pat<< " "<<str<<endl;
        int n=pat.size(),m=str.size();
        power = vector<int> (n,1);
        for(int i=1;i<n;i++){
            power[i] = (base * 1LL * power[i-1])%M;
        }

        int pathash = gethash(pat);
        int rollhash = gethash(str.substr(0,n));
        int l=0,r=n-1;

        do{
           // cout<<pathash<<" "<<rollhash<<endl;
            if(pathash == rollhash && checkstr(pat,str,l,n)){
                return 1;
            }
            rollhash = (rollhash - ( tochar(str[l]) * 1LL *power[n-1] )%M )%M;
            l++,r++;
            if(r<m){
                rollhash = (rollhash * 1LL * base)%M;
                rollhash = (rollhash + ( tochar(str[r]) * 1LL * power[0] )%M +M)%M;
            }
        }while(r<m);
        return 0;

    }



    int repeatedStringMatch(string a, string b) {
        int count=1;
        if(a==b) return count;
        string source = a;
        while(source.size() < b.size() ){
            count++;
            source += a;
        }
        if(source == b) return count;
        
        if(rabinkarp(b,source) == 1) return count;
        if(rabinkarp(b,source+a) == 1  ) return count+1;
        return -1;
    }
};