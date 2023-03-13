class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
               m[nums[i]] = 1;
            }else{
                m[nums[i]]++;
            }
        }
        priority_queue< pair<int,int> > p ;
        for(auto i : m){
            p.push(make_pair(i.second,i.first));
        }
        vector<int> ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};