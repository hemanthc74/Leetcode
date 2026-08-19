class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int len = 0;

        for (int l = 0; l < n; l++) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int cnt = 0;
                int r = l;
                while (r < n && nums[r] <= threshold &&
                       (r == l || nums[r] % 2 != nums[r-1] % 2)) {
                    cnt++;
                    r++;
                }
                len = max(len, cnt);
            }
        }
        return len;
    }
};
