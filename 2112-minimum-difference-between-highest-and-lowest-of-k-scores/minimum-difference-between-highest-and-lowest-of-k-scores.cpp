class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n = nums.size();
        int mindiff=1e6;
        sort(nums.begin() , nums.end());
        for(int i=0; i<=n-k; i++){
            int mini=nums[i];
            int maxi=nums[i+k-1];
            
            mindiff=min(mindiff , maxi-mini);
        }

        return mindiff;
    }
};