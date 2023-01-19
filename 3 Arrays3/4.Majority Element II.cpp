class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=0,n2=0,c1=0,c2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(c1==0 && nums[i]!=n2){
                n1=nums[i];
                c1++;
                continue;
            }
            if(n1==nums[i]){
                c1++;
                continue;
            }
            if(c2==0 && nums[i]!=n1){
                n2=nums[i];
                c2++;
                continue;
            }

            
            if(n2==nums[i]){
                c2++;
                continue;
            }

            c1--;
            c2--;
        }
        
       

        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==n1) c1++;
            if(nums[i]==n2) c2++;
        }
        vector<int> v;
        if(n1==n2){
           v.push_back(n1);
           return v;
        }
        if(c1 > (n/3))
        v.push_back(n1);
        if(c2 > (n/3))
        v.push_back(n2);
        return v;
    }
};