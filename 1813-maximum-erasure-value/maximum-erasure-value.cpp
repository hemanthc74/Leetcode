class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> hash;
        int n = nums.size(), left = 0, sum = 0, maxsum = 0;

        for (int right = 0; right < n; right++) {
            while (hash.count(nums[right])) {
                hash.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            hash.insert(nums[right]);
            sum += nums[right];
            maxsum = max(maxsum, sum);
        }

        return maxsum;
    }
};
