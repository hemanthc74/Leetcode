class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n = nums.size();
        int mindiff=1e6;
        sort(nums.begin() , nums.end());
        for(int i=0; i<=n-k; i++){
            int mini=1e9;
            int maxi=-1;
            for(int j=0;j<k;j++){
                if(nums[i+j] > maxi) maxi=nums[i+j];
                if(nums[i+j]<=mini) mini=nums[i+j];
            }
            mindiff=min(mindiff , maxi-mini);
        }

        return mindiff;
    }
};