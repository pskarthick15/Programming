class Solution {
public:
       int firstloc(vector<int>& nums, int target){
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(nums[mid]>=target)
                end=mid;
            else
                start=mid+1;
        }
        if(nums[start]!=target)
            return -1;
            return start;
        
    }
    
    int lastloc(vector<int>& nums, int target){
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<end){
            int mid=(start)+(end-start+1)/2;
            if(nums[mid]<=target)
                start=mid;
            else
                end=mid-1;
            
        }
        if(nums[start]!=target)
            return -1;
            return start;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>ans={-1,-1};
        if(nums.empty()){
            return ans;
        }
        ans[0]=firstloc( nums, target);
        ans[1]=lastloc(nums, target);
        return ans;
    }
};
