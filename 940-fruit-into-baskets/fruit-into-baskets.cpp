class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0;
        int left = 0, right = 0;
        int n = fruits.size();
        
        // Maps fruit_type -> frequency_count in the current window
        unordered_map<int, int> counts;
        
        while (right < n) {
            
            counts[fruits[right]]++;
            
            while (counts.size() > 2) {
                counts[fruits[left]]--; 
                
                if (counts[fruits[left]] == 0) {
                    counts.erase(fruits[left]);
                }
                
                left++; 
            }
            
            maxlen = max(maxlen, right - left + 1);
            right++;
        }

        return maxlen;
    }
};
