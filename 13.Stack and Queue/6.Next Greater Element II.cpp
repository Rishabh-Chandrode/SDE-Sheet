class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans;
        
        
        for(int i=nums.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(nums[i]);
                continue;
            }

            while(!s.empty() && nums[i] >= s.top()){
                s.pop();
            }
            s.push(nums[i]);

        }

        for(int i=nums.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(nums[i]);
                ans.insert(ans.begin(),nums[i]);
                continue;
            }

            while( s.empty() == false && nums[i] >= s.top() ){
                s.pop();
            }
            if(s.empty()){
                ans.insert(ans.begin(),-1);
            }else{
                ans.insert(ans.begin(),s.top());
            }
            s.push(nums[i]);
        }


        return ans;
    }
};