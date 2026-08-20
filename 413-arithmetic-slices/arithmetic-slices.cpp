class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int total_cnt = 0;
        int current_streak = 0;
        
        // Start from index 2 and check the difference of consecutive triplets
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                // If the triplet forms an arithmetic progression, 
                // it extends all previous valid slices ending at i-1 by one element,
                // plus creates 1 new triplet slice.
                current_streak++;
                total_cnt += current_streak;
            } else {
                // If the sequence breaks, reset the streak
                current_streak = 0;
            }
        }
        
        return total_cnt;
    }
};
