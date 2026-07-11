class Solution {
public:
    int countMonobit(int n) {
        int cnt=n+1;
        for(int i=2;i<=n;i++){
            int k=i;
            while(k>1){
                if((k&1)!=((k>>1)&1)) {
                    cnt--;
                    break;
                }
                k=k>>1;
            }
        }
        return cnt;
    }
};