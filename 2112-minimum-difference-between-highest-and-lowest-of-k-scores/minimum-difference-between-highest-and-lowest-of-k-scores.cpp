class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n = nums.size();
        int mindiff=1e6;
        sort(nums.begin() , nums.end());
        for(int i=0; i<=n-k; i++){
            mindiff=min(mindiff ,nums[i+k-1]-nums[i] );
        }

        return mindiff;
    }
};