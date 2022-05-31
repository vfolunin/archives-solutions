class Solution {
public:
    bool kLengthApart(vector<int> &a, int k) {
        int last = -1e9;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]) {
                if (i - last <= k)
                    return 0;
                last = i;
            }
        }
        return 1;
    }
};