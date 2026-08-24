class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> hash;
        int n=nums.size(),left=0,right=0,sum=0,maxsum=0;
        while(right<n){
            
            while(hash.count(nums[right])) {
                hash.erase(nums[left]);
                sum-=nums[left];
                left++;

            }
            hash.insert(nums[right]);
            sum +=nums[right];
            maxsum=max(sum,maxsum);
            right++;
        }

        return maxsum;
    }
};