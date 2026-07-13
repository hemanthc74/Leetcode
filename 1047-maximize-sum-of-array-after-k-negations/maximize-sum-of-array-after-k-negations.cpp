class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int mini = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--; 
            }
            
            mini = min(mini, nums[i]);
        }
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (k % 2 != 0) {
            totalSum -= 2 * mini;
        }
        
        return totalSum;
    }
};
