class Solution {
public:
    bool isConsecutive(vector<int> &a) {
        sort(a.begin(), a.end());
        for (int i = 1; i < a.size(); i++)
            if (a[i] != a[0] + i)
                return 0;
        return 1;
    }
};