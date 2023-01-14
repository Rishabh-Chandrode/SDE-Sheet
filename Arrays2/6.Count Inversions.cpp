#include <bits/stdc++.h> 
long long  ans=0;
    void merge(long long *nums,int low,int mid,int high){
        vector<int> v;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]>nums[j]){
               
                ans=ans + (mid-i+1);
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
        j=0;
        for(i=low;i<=high;i++){
            nums[i]=v[j];
            j++;
        }

    }
    void mergesort(long long *nums,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
long long getInversions(long long *nums, int n){
    // Write your code here.
     mergesort(nums,0,n-1);
        
        return ans;
}