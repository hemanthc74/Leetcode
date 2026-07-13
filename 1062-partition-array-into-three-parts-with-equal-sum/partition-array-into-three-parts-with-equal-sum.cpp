class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int totalsum = 0;

        for (int i = 0; i < n; i++) {
            totalsum += arr[i];
        }

        if (totalsum % 3 != 0) return false;

        int sum = totalsum / 3; 
        int currsum = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            currsum += arr[i]; 
            
            
            if (currsum == sum) {
                cnt++;       
                currsum = 0; 
            }
        }

        
        return cnt >= 3;
    }
};
