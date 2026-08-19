class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int whiteCount = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }

        int minOps = whiteCount;

        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') whiteCount++;      
            if (blocks[i - k] == 'W') whiteCount--;  
            minOps = min(minOps, whiteCount);
        }

        return minOps;
    }
};
