class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int l = -1, r = letters.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (letters[m] <= target)
                l = m;
            else
                r = m;
        }
        return letters[r % letters.size()];
    }
};