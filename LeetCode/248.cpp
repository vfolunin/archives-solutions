class Solution {
    void rec(string s, vector<long long> &values) {
        if (s.size() > 15)
            return;
        
        if (s.size() == 1 || s.size() > 1 && s[0] != '0')
            values.push_back(stoll(s));

        rec("0" + s + "0", values);
        rec("1" + s + "1", values);
        rec("6" + s + "9", values);
        rec("8" + s + "8", values);
        rec("9" + s + "6", values);
    }

    vector<long long> prepare() {
        vector<long long> values;
        rec("", values);
        rec("0", values);
        rec("1", values);
        rec("8", values);

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        return values;
    }

public:
    int strobogrammaticInRange(string &l, string &r) {
        static vector<long long> values = prepare();
        auto lIt = lower_bound(values.begin(), values.end(), stoll(l));
        auto rIt = upper_bound(values.begin(), values.end(), stoll(r));
        return rIt - lIt;
    }
};