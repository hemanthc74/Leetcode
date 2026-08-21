class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefix_sum;
        prefix_sum[0]=1;
        int current_sum=0 , total_subarrays=0;
        for(auto num:nums){
            current_sum+=num;
            if(prefix_sum.count(current_sum - goal)){
                total_subarrays+=prefix_sum[current_sum - goal];
            }
            prefix_sum[current_sum]++;
        }

        return total_subarrays;
    }
};