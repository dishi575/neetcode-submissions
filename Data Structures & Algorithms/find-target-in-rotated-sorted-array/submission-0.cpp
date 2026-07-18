class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<nums[r]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        int pivot=l;
        int res=bin(nums,target,0,pivot-1);
        if(res!=-1){
            return res;
        }
        return bin(nums,target,pivot,nums.size()-1);
    }
    int bin(vector<int>& nums,int target,int l,int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid-1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
