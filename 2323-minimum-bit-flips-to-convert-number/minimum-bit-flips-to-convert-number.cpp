class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = start^goal;
        int cnt=0;
        while(count>0){
            if(count&1 == 1) cnt++;
            count = count>>1;
        }
        return cnt;
    }
};