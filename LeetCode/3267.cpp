class Solution {
    string getString(int value, int maxSize) {
        string s = to_string(value);
        return string(maxSize - s.size(), '0') + s;
    }

    unordered_set<string> getSwapped(string &s) {
        unordered_set<string> res = { s };

        for (int i1 = 0; i1 < s.size(); i1++) {
            for (int i2 = i1; i2 < s.size(); i2++) {
                swap(s[i1], s[i2]);
                res.insert(s);

                for (int i3 = 0; i3 < s.size(); i3++) {
                    for (int i4 = i3 + 1; i4 < s.size(); i4++) {
                        if (s[i3] == s[i4])
                            continue;

                        swap(s[i3], s[i4]);
                        res.insert(s);
                        swap(s[i3], s[i4]);
                    }
                }

                swap(s[i1], s[i2]);
            }
        }

        return res;
    }

public:
    int countPairs(vector<int> &a) {
        int maxSize = to_string(*max_element(a.begin(), a.end())).size();
        unordered_map<string, int> count;
        int res = 0;

        for (int value : a) {
            string s = getString(value, maxSize);
            res += count[s];

            for (const string &swapped : getSwapped(s))
                count[swapped]++;
        }

        return res;
    }
};