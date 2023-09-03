class Solution {
public:
    int furthestDistanceFromOrigin(string &s) {
        int l = count(s.begin(), s.end(), 'L');
        int r = count(s.begin(), s.end(), 'R');
        int q = count(s.begin(), s.end(), '_');

        return max(l + q - r, r + q - l);
    }
};