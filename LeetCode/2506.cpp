class Solution {
public:
    int similarPairs(vector<string> &a) {
        unordered_map<string, int> count;
        for (string &s : a) {
            sort(s.begin(), s.end());
            s.erase(unique(s.begin(), s.end()), s.end());
            count[s]++;
        }

        int res = 0;
        for (auto &[s, count] : count)
            res += count * (count - 1) / 2;
        return res;
    }
};