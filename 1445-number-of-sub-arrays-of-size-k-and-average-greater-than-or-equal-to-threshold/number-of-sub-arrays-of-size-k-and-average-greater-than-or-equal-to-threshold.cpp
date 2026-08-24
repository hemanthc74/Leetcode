class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int len=0,sum=0,left=0,right=0,cnt=0;
        while(right<n){
            len++;
            sum+=arr[right];
            
            while(len>k){
                sum-=arr[left];
                left++;
                len--;
            } 
            if(len==k && sum/k >= threshold) cnt++;
            right++;
            
        }

        return cnt;
    }
};