class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<n+m;i++){
            nums1[i]=nums2[i-m];
        }
        int mid=(n+m)/2,i;

        while(mid>0){
            int l=0;
            for(int i=mid;i<n+m;i++){
                if(nums1[i]<nums1[l]){
                    swap(nums1[i],nums1[l]);
                }
                l++;
            }
            if (mid == 1) {
      mid = 0;
    } else {
      mid = ceil((float) mid / 2);
    }
        }
    }
};