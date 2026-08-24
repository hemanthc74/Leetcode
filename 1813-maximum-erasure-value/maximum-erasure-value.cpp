class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size(), left = 0, sum = 0, maxsum = 0;

        for (int right = 0; right < n; right++) {
            freq[nums[right]]++;
            sum += nums[right];

            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};
