class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int left = colors[i];
            int mid = colors[(i + 1) % n];
            int right = colors[(i + 2) % n];

            if (mid != left && mid != right) {
                count++;
            }
        }

        return count;
    }
};
