class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        vector<int> ans;
        deque<int> q;
        int i=0;
        for(int i=0;i<nums.size();i++){
            while(!q.empty() && q.front() <= i-k ) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();

            q.push_back(i);
            if(i>= (k-1) ){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};