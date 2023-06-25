class Solution {
public:
    int longestString(int kaa, int kbb, int kab) {
        return min(kaa, kbb) * 4 + kab * 2 + (kaa != kbb) * 2;
    }
};