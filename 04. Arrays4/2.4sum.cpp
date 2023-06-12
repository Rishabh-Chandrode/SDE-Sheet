class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int t1=target-nums[i];
            for(int j=i+1;j<n;j++){
                int low=j+1,high=n-1;
                long long t=(long long)t1-nums[j];

                while(low<high){
                    if(t < (nums[low]+nums[high]))
                        high--;

                    else if(t > (nums[low]+nums[high])){
                        low++;
                    }
                    else{
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[low]);
                        v.push_back(nums[high]);
                        ans.push_back(v);
                        
                        while( low<high && nums[high] == v[3]) --high;
                        while(low<high && nums[low]==v[2]) ++low;  
                         
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) ++j;
            }
            while(i+1<n && nums[i]==nums[i+1]) ++i;
        }
        return ans;
    }
};