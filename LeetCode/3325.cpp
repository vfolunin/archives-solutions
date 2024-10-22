struct Counter {
    unordered_map<char, int> count;
    multiset<int> counts;

    void add(char c, int delta) {
        if (auto it = counts.find(count[c]); it != counts.end())
            counts.erase(it);
        count[c] += delta;
        counts.insert(count[c]);
    }
};

class Solution {
public:
    int numberOfSubstrings(string &s, int threshold) {
        Counter counter;
        int res = 0;
        
        for (int l = 0, r = 0; r < s.size(); r++) {
            counter.add(s[r], 1);
            while (*counter.counts.rbegin() >= threshold)
                counter.add(s[l++], -1);
            res += l;
        }

        return res;
    }
};