class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1) ;
        arr[0]=0;
        for(int i=0 ; i<=n ;i++){
            if(i%2==0) arr[i]=arr[i/2];
            else if (i%2==1)arr[i]=arr[i-1]+1;
            
        }

        return arr;
    }
};