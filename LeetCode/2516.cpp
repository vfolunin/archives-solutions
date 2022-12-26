struct Counter {
    vector<int> count;
    int limit;

    Counter(int limit) : count(3),  limit(limit) {}

    void add(char c, int delta) {
        count[c - 'a'] += delta;
    }

    bool isOk() {
        for (int value : count)
            if (value < limit)
                return 0;
        return 1;
    }
};

class Solution {
public:
    int takeCharacters(string &s, int limit) {
        Counter counter(limit);

        int r = 0;
        while (r < s.size() && !counter.isOk()) {
            r++;
            counter.add(s[s.size() - r], 1);
        }

        if (!counter.isOk())
            return -1;

        int res = r;
        
        for (int l = 1; l <= s.size(); l++) {
            counter.add(s[l - 1], 1);

            while (r && counter.isOk()) {
                counter.add(s[s.size() - r], -1);
                r--;
            }
            
            res = min(res, l + r + !counter.isOk());
        }

        return res;
    }
};