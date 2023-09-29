class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0) {
            nums1 = nums2;
            return;
        }
        int i=n+m-1;
        int p=m-1;
        int q = n-1;
        while(p<i && p>=0){
            if(nums1[p]>nums2[q]){
                nums1[i] = nums1[p];
                i--;
                p--;
            }else if(nums2[q] >= nums1[p]){
                nums1[i] = nums2[q];
                i--;
                q--;
            }
        }
        while(q>=0){
            nums1[i] = nums2[q];
            i--;
            q--;
        }
        return;
    }
};