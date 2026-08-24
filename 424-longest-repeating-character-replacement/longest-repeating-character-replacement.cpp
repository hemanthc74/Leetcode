class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left=0,right=0,maxlen=0,maxcount=0;
        int n=s.size();
        while(right<n){
            freq[s[right]-'A']++;
            maxcount = max(maxcount,freq[s[right]-'A']);
            while(right-left+1-maxcount>k){
                freq[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }

        return maxlen;
    }
};