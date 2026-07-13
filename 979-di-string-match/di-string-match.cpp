class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int f=0 , l=n;
        vector<int> arr(n+1);
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                arr[i]=l;
                l--;
            }else{
                arr[i]=f;
                f++;
            }
        }
        arr[n]=f;
        return arr;
    }
};