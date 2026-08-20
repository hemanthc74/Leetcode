class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0||k<=1) return 0;
        int left=0,right=0,result=0;
        int prod=1;
       
        while(right<n){
            prod=prod*nums[right];
            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            result+=right-left+1;
            right++;
        }

        return result;
    }
};


