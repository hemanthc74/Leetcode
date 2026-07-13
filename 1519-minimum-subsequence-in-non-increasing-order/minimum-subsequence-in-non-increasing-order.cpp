class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        sort(nums.begin() , nums.end());
        int psum=0;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            psum+=nums[i];
            ans.push_back(nums[i]);
            if(2*psum >sum){
                break;
            }
        }

        return ans;
    }
};