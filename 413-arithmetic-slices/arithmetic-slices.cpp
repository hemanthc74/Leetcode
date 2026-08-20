class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int cnt=0;
        for(int i=0;i<n-2;i++){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                cnt++;
                int diff=nums[i+1]-nums[i];
                int r = i+3;
                while(r<n){
                    if(nums[r]-nums[r-1]==diff) {
                        cnt+=r-i-1;
                        r++;
                    }else{
                        i=r-2;
                        break;
                    }
                    if(r==n) {
                        i=r-2;
                    }
                }
            }
        }

        return cnt;
    }
};