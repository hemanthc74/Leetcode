class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }

    int helper(vector<int> & nums, int k){
        int left=0,right=0,tcount=0;
        int n=nums.size();
        while(right<n){
            if(nums[right]%2!=0) k--;
            while(k<0){
                if(nums[left]%2!=0) k++;
                left++;
            }
            tcount += right-left+1;
            right++;
        }

        return tcount;
    }
};