class Solution {
    int getReversed(int value) {
        string s = to_string(value);
        reverse(s.begin(), s.end());
        return stoi(s);
    }

public:
    int minMirrorPairDistance(vector<int> &a) {
        unordered_map<int, int> pos;
        int res = 1e9;

        for (int i = 0; i < a.size(); i++) {
            if (auto it = pos.find(a[i]); it != pos.end())
                res = min(res, i - it->second);
            pos[getReversed(a[i])] = i;
        }

        return res != 1e9 ? res : -1;
    }
};