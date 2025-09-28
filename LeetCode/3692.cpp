class Solution {
public:
    string majorityFrequencyGroup(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        unordered_map<int, string> group;
        for (int i = 0; i < count.size(); i++)
            if (count[i])
                group[count[i]] += i + 'a';
        
        int resCount = 0;
        string res;
        for (auto &[count, s] : group) {
            if (res.size() < s.size() || res.size() == s.size() && resCount < count) {
                res = s;
                resCount = count;
            }
        }
        return res;
    }
};