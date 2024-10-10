class Solution {
    int getLnisSize(vector<int> &a) {
        vector<int> last(a.size() + 1, -1e9);
        last[0] = 1e9;
        
        for (int value : a)
            *upper_bound(last.begin(), last.end(), value, greater<int>()) = value;

        int res = a.size();
        while (last[res] == -1e9)
            res--;
        return res;
    }

public:
    int minOperations(vector<int> &a) {
        return getLnisSize(a);
    }
};