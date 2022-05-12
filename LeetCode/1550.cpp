class Solution {
public:
    bool threeConsecutiveOdds(vector<int> &a) {
        for (int i = 0; i + 2 < a.size(); i++)
            if (a[i] % 2 && a[i + 1] % 2 && a[i + 2] % 2)
                return 1;
        return 0;
    }
};