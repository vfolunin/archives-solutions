class Solution {
    struct Counter {
        vector<int> count;
        int zeroCount;
        
        Counter() : count(26), zeroCount(26) {}
        
        void add(int i, int delta) {
            zeroCount -= !count[i];
            count[i] += delta;
            zeroCount += !count[i];
        }
        
        bool isOk() {
            return zeroCount == 26;
        }
    };
    
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return {};
        
        Counter counter;
        for (char c : p)
            counter.add(c - 'a', -1);
        for (int i = 0; i < p.size(); i++)
            counter.add(s[i] - 'a', 1);
        
        vector<int> res;
        if (counter.isOk())
            res.push_back(0);
        
        for (int i = p.size(); i < s.size(); i++) {
            counter.add(s[i - p.size()] - 'a', -1);
            counter.add(s[i] - 'a', 1);
            if (counter.isOk())
                res.push_back(i - p.size() + 1);
        }
        
        return res;
    }
};