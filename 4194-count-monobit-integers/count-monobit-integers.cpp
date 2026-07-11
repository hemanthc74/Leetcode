class Solution {
public:
    int countMonobit(int n) {
        int cnt=1;
        long long current =1;
        while(current<=n){
            cnt++;
            current=(current<<1)|1;
        }
        return cnt;
    }
};