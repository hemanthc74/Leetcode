
class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--; 
            }
        }
        
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Step 4: If k is still odd, flip the smallest absolute element
        if (k % 2 != 0) {
            int minElement = *min_element(nums.begin(), nums.end());
            
            totalSum -= 2 * minElement;
        }
        
        return totalSum;
    }
};
