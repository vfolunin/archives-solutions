class Solution {
public:
    int longestBalanced(string &s) {
        int res = 0;

        for (int l = 0; l < s.size(); l++) {
            unordered_map<char, int> count;
            multiset<int> counts;

            for (int r = l; r < s.size(); r++) {
                if (count[s[r]])
                    counts.erase(counts.find(count[s[r]]));
                count[s[r]]++;
                counts.insert(count[s[r]]);

                if (*counts.begin() == *counts.rbegin())
                    res = max(res, r - l + 1);
            }
        }

        return res;
    }
};