class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        for (int i = 0; i + 10 <= s.size(); i++)
            count[s.substr(i, 10)]++;
        
        vector<string> res;
        for (auto &[s, count] : count)
            if (count > 1)
                res.push_back(s);
        return res;
    }
};