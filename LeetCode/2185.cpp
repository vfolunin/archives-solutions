class Solution {
public:
    int prefixCount(vector<string> &words, string pref) {
        sort(words.begin(), words.end());
        auto l = lower_bound(words.begin(), words.end(), pref);
        pref.back()++;
        auto r = lower_bound(words.begin(), words.end(), pref);
        return r - l;
    }
};