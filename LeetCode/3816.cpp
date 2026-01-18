class Solution {
public:
    string lexSmallestAfterDeletion(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;

        string res;
        for (char c : s) {
            while (!res.empty() && res.back() > c && count[res.back() - 'a'] > 1) {
                count[res.back() - 'a']--;
                res.pop_back();
            }
            res.push_back(c);
        }

        while (count[res.back() - 'a'] > 1) {
            count[res.back() - 'a']--;
            res.pop_back();
        }
        return res;
    }
};