class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return 1;
        unordered_map<char, int > hash;
        for(int i=0;i<n;i++){
            hash[s[i]]++;
        }
        int cnt =0;
        bool hashodd =false;
        for(auto it:hash){
            if(it.second%2 != 0) hashodd = true;
            cnt = cnt + (it.second/2)*2;
        }

        if(hashodd)  cnt++;

        return cnt;
    }
};