struct Counter {
    unordered_map<int, int> count;
    multiset<int> counts;

    void add(int i, int delta) {
        if (auto it = counts.find(count[i]); it != counts.end())
            counts.erase(it);        
        count[i] += delta;
        if (!count[i])
            count.erase(i);
        else
            counts.insert(count[i]);
    }
};

class Solution {
    int longestSubstring(string &s, int repeatCount, int uniqueCount) {
        Counter counter;
        int res = 0;
        
        for (int l = 0, r = 0; r < s.size(); l++) {
            while (r < s.size() && counter.count.size() <= uniqueCount) {
                counter.add(s[r], 1);
                r++;
                
                if (counter.count.size() == uniqueCount && *counter.counts.begin() >= repeatCount)
                    res = max(res, r - l);
            }

            counter.add(s[l], -1);
        }
        
        return res;
    }
    
public:
    int longestSubstring(string &s, int repeatCount) {
        int res = 0;
        
        for (int uniqueCount = 1; uniqueCount <= 26; uniqueCount++)
            res = max(res, longestSubstring(s, repeatCount, uniqueCount));
        
        return res;
    }
};