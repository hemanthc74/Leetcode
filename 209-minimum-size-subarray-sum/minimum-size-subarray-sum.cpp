class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int n = nums.size();
        int sum=0;
        int minlen=1e9;
        for(int j=0 ; j<n; j++){
            sum+=nums[j];

            while(sum>=target){
                minlen=min(minlen , j-i+1);
                sum-=nums[i];
                i++;
            }
            
        }
        if(minlen==1e9) return 0;
        return minlen;
    }
};