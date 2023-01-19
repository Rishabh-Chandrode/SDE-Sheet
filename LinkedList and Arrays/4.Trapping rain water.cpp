class Solution {
public:
    int trap(vector<int>& height) {
       int ans=0;
       int n=height.size();
       int left=0,right=n-1,maxleft=0,maxright=0;
       while(left < right){
           if(height[left] <= height[right]){
               if(height[left]>=maxleft){
                   maxleft = height[left];
               }else{
                   ans+=maxleft-height[left];
               }
               left++;
           }else{
               if(height[right]>=maxright){
                   maxright = height[right];
               }else{
                   ans+=maxright-height[right];
               }
               right--;
           }
       }
       return ans;
    }
};