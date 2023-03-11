class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low=0,high=n1,mid;
        int l1,l2,r1,r2,c1,c2;
        while(low<=high){
            mid=(low+high)/2;
            c1 = mid;
            c2 = ((n1+n2+1)/2) -mid;
            l1 = c1==0?INT_MIN:nums1[c1-1];
            l2 = c2==0?INT_MIN:nums2[c2-1];
            r1 = c1==n1?INT_MAX:nums1[c1];
            r2 = c2==n2?INT_MAX:nums2[c2];

            if(l1<=r2 && l2 <=r1){
                if( (n1+n2)%2 &1 ) return max(l1,l2);
                return double ( max(l1,l2)+min(r1,r2) ) /2;
            }else{
                if(l1>r2){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            
            
        }

        
      return 0.0;

    }
};