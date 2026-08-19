class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();

        int bestStart = 0, bestLen = 0;

        for (int k = 1; k <= 26; k++) {

            int lower[26] = {};
            int upper[26] = {};

            int distinct = 0;
            int complete = 0;

            int left = 0;

            for (int right = 0; right < n; right++) {

                int idx = tolower(s[right]) - 'a';

                if (lower[idx] == 0 && upper[idx] == 0)
                    distinct++;

                if (islower(s[right])) {
                    lower[idx]++;

                    if (lower[idx] == 1 && upper[idx] > 0)
                        complete++;
                } else {
                    upper[idx]++;

                    if (upper[idx] == 1 && lower[idx] > 0)
                        complete++;
                }

                while (distinct > k) {

                    int removeIdx = tolower(s[left]) - 'a';

                    if (islower(s[left])) {
                        lower[removeIdx]--;

                        if (lower[removeIdx] == 0 &&
                            upper[removeIdx] > 0)
                            complete--;
                    } else {
                        upper[removeIdx]--;

                        if (upper[removeIdx] == 0 &&
                            lower[removeIdx] > 0)
                            complete--;
                    }

                    if (lower[removeIdx] == 0 &&
                        upper[removeIdx] == 0)
                        distinct--;

                    left++;
                }

                if (distinct == k && complete == k) {

                    int len = right - left + 1;

                    if (len > bestLen ||
                        (len == bestLen && left < bestStart)) {

                        bestLen = len;
                        bestStart = left;
                    }
                }
            }
        }

        return s.substr(bestStart, bestLen);
    }
};