class Solution {
public:
    int solve(string &s1,string &s2,int &i,int &j){
        long long n1=0,n2=0;
        if(i<s1.length() && s1[i]=='.') i++;
        if(j<s2.length() && s2[j] =='.') j++;
        while(i<s1.length()){
            if(s1[i]=='.') break;
            n1 = (n1*10) + (s1[i]-'0');
            i++;
        }
        while(j<s2.length()){
            if(s2[j] == '.') break;
            n2 = (n2*10) + (s2[j]-'0');
            j++;
        }
        
        if (n1<n2) return -1;
        if(n1>n2) return 1;
        if(i<s1.length() || j<s2.length()) return  solve(s1,s2,i,j);
        return 0;
    }
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        return solve(version1,version2,i,j);
    }
};