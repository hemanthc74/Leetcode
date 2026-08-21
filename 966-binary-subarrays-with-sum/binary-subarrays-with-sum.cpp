class Solution {
private:
    // Helper function to find number of subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0;
        int current_sum = 0;
        int count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];
            
            // Shrink window if sum exceeds goal
            while (current_sum > goal) {
                current_sum -= nums[left];
                left++;
            }
            
            // Number of valid subarrays ending at 'right' index
            count += (right - left + 1);
        }
        
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
