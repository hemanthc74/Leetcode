class Solution {
public:
    string longestNiceSubstring(string s) {
        
        int n=s.size();
        if(n<2) return {};
        vector<int> hash(128,0);
        for(auto it : s){
            hash[it]=1;
        }
        
        for(int i=0; i<n; i++){
            char c = s[i];
            if(hash[tolower(c)]==1 && hash[toupper(c)]==1) continue;
            string left = longestNiceSubstring(s.substr(0,i));
            string right = longestNiceSubstring(s.substr(i+1));
            if(left.size()>=right.size()) return left;
            else return right;
        }
        

        return s;
    }
};