class Solution {
public:
    int bagOfTokensScore(vector<int> &a, int power) {
        sort(a.begin(), a.end());
        int score = 0, res = 0;
        
        for (int l = 0, r = a.size() - 1; l <= r; ) {
            if (power >= a[l]) {
                power -= a[l];
                score++;
                l++;
            } else if (score) {
                power += a[r];
                score--;
                r--;
            } else {
                break;
            }
            res = max(res, score);
        }
        
        return res;
    }
};