class Solution {
public:
void reverse(vector<int>& nums){
    int n=nums.size();
    int mid=(n+1)/2;
    for(int i=0,l=n-1;i<mid;i++,l--){
        int t=nums[i];
        nums[i]=nums[l];
        nums[l]=t;
    }
}
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
             reverse(nums);
             return;
        }
        cout<<ind<<";"<<endl;
        int min=INT_MAX,j=ind;
        for(int i=ind+1;i<n;i++){
            if(nums[i]<=min){
                if(nums[i]>nums[ind]){
                    min=nums[i];
                    j=i;
                }
            }
           
        }
        int t=nums[ind];
        nums[ind]=nums[j];
        nums[j]=t;
        
       int i=ind+1,l=n-1;
       while(i<l){
           int t=nums[i];
        nums[i]=nums[l];
        nums[l]=t;
        i++;
        l--;
       }
        
    }
};