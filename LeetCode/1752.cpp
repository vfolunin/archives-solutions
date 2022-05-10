class Solution {
public:
    bool check(vector<int> &a) {
        int inv = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            inv += a[i] > a[i + 1];
        inv += a.back() > a.front();
        return inv <= 1;
    }
};