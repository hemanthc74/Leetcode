
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        int l = 0;

        while (l < n) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l;
                while (r < n && nums[r] <= threshold &&
                       (r == l || nums[r] % 2 != nums[r-1] % 2)) {
                    ans = max(ans, r - l + 1);
                    r++;
                }
                l = r; 
            } else {
                l++;
            }
        }
        return ans;
    }
};

