class Solution {
public:
    int count=0;
    void merge(vector<int>& nums,int low,int mid,int high){
        int i=low,j=mid+1;
        vector<int> v; 
        int k=mid+1;
        for(int f=low;f<=mid;f++){
            
            while(k<=high && nums[f] > (2LL*nums[k]) ){
                k++;
            }
            count+=(k-(mid+1));
            
        }
        while(i<=mid && j<=high){
            if(nums[i]>nums[j]){
                v.push_back(nums[j]);
                j++;
            }else{
                v.push_back(nums[i]);
                i++;
            }

        }
        while(i<=mid){
            v.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            v.push_back(nums[j]);
            j++;
        }
        k=0;
        i=low;
        while(i<=high){
            nums[i]=v[k];
            k++;
            i++;
        }
    }
    void mergesort(vector<int>& nums,int low,int high){
        if(low<high){
            int mid=(high+low)/2;
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return count;
    }
};