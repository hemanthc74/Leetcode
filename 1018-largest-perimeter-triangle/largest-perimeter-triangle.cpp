class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return 0;
        sort(nums.begin() , nums.end());
        if(nums[n-1]<nums[n-2]+nums[n-3]) return nums[n-1]+nums[n-2]+nums[n-3];
        for(int i=n-1 ; i>1 ;i--){
            if(nums[i]<nums[i-1]+nums[i-2]) return nums[i]+nums[i-1]+nums[i-2];
        }

        return 0;
    }
};