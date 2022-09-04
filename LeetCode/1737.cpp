class Solution {
    int f1(string &a, string &b) {
        int res = a.size() + count(b.begin(), b.end(), 'a');
        for (int ai = 0; ai < a.size(); ai++) {
            int bi = upper_bound(b.begin(), b.end(), a[ai]) - b.begin();
            if (bi < b.size())
                res = min<int>(res, a.size() - 1 - ai + bi);
        }
        res = min<int>(res, count(a.begin(), a.end(), 'z') + b.size());
        return res;
    }
    
    int f2(string &a, string &b) {
        vector<int> count(26);
        for (char c : a)
            count[c - 'a']++;
        for (char c : b)
            count[c - 'a']++;
        return a.size() + b.size() - *max_element(count.begin(), count.end());
    }
    
public:
    int minCharacters(string &a, string &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return min({ f1(a, b), f1(b, a), f2(a, b) });
    }
};