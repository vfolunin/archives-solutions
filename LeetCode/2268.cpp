class Solution {
public:
    int minimumKeypresses(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        vector<int> counts;
        for (auto &[c, count] : count)
            counts.push_back(count);
        sort(counts.rbegin(), counts.rend());

        int res = 0;
        for (int i = 0; i < counts.size(); i++)
            res += counts[i] * (i / 9 + 1);
        return res;
    }
};