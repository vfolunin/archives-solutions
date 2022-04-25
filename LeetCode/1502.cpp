class Solution {
public:
    bool canMakeArithmeticProgression(vector<int> &a) {
        sort(a.begin(), a.end());
        int diff = a[1] - a[0];
        for (int i = 2; i < a.size(); i++)
            if (a[i] - a[i - 1] != diff)
                return 0;
        return 1;
    }
};