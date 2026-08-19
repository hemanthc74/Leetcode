class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> hash(256,0);
        int l=0,maxlen=0;
        for(int r=0; r<n;r++){
            hash[s[r]]++;
            while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }

        return maxlen;
    }
};