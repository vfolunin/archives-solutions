class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        
        vector<int> res = { 0 };
        for (int i = 0, to = 0; i < s.size(); i++) {
            res.back()++;
            to = max(to, last[s[i] - 'a']);
            if (i == to && i + 1 < s.size())
                res.emplace_back();
        }
        return res;
    }
};