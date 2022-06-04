class Solution {
    bool isSpecial(vector<int> &a, int value) {
        auto [l, r] = equal_range(a.begin(), a.end(), value);
        return (r - l) * 4 > a.size();
    }
    
public:
    int findSpecialInteger(vector<int> &a) {
        for (int value : { a[a.size() / 4], a[a.size() / 2], a[a.size() * 3 / 4] })
            if (isSpecial(a, value))
                return value;
        return -1;
    }
};