struct Counter {
    vector<int> count;
    int negativeCount = 0;

    Counter() : count(128) {}

    void add(int i, int delta) {
        negativeCount -= count[i] < 0;
        count[i] += delta;
        negativeCount += count[i] < 0;
    }

    bool isOk() {
        return !negativeCount;
    }
};

class Solution {
public:
    string minWindow(string &s, string &t) {
        Counter counter;
        for (char c : t)
            counter.add(c, -1);
        
        int resSize = s.size() + 1, resFrom = s.size();
        
        for (int l = 0, r = 0; l < s.size(); l++) {
            while (r < s.size() && !counter.isOk()) {
                counter.add(s[r], 1);
                r++;
            }
            
            if (counter.isOk() && resSize > r - l) {
                resSize = r - l;
                resFrom = l;
            }
            
            counter.add(s[l], -1);
        }
        
        return s.substr(resFrom, resSize);
    }
};