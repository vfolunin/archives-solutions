class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string &s) {
        for (int i = 0; i + 1 < s.size(); i++)
            if (abs(s[i] - s[i + 1]) > 2)
                return 0;
        return 1;
    }
};