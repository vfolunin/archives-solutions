class Solution {
public:
    int minimumCardPickup(vector<int> &a) {
        int res = -1;
        unordered_map<int, int> last;
        for (int i = 0; i < a.size(); i++) {
            if (last.count(a[i]) && (res == -1 || res > i - last[a[i]] + 1))
                res = i - last[a[i]] + 1;
            last[a[i]] = i;
        }
        return res;
    }
};